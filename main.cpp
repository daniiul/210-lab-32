// COMSC-210 | 210-lab-32 | Daniil Malakhov
// IDE used: Codeblocks
#include <deque>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <iostream>
#include "Car.h"

using namespace std;

const int INITIAL_QUEUE = 2, LANES = 4, PROB1 = 46, PROB2 = 39, PROB3 = 15;

void print(deque<Car> (&lanes)[4]);

int main()
{
    srand(time(0));

    deque<Car> lanes[LANES];

    int i = 0;

    cout << "Initial Queue: " << endl;

    for(auto lane : lanes)
    {
        while(i < INITIAL_QUEUE)
        {
            Car temp;
            lane.push_back(temp);
            cout << "ss" << endl;
            i++;
        }
        i = 0;
    }
    print(lanes);

    int time = 1;
    while(time <= 20)
    {
        cout << "Time " << time << ": ";
        int l = 1;
        for (auto lane : lanes)
        {
            int prob = rand() % 100 + 1;  // returns random number 1-100
            cout << "Lane " << l << ": ";
            if (prob <= PROB1)
            {
                cout << "Left lane: ";
                lane.front().print();
                lane.pop_front();
            }
            else if (prob <= PROB2)
            {
                Car temp;
                cout << "Joined lane: ";
                temp.print();
                lane.push_back(temp);
            }
            else if (prob <= PROB3)
            {
                int randLane = rand() % 4;
                do
                {
                    randLane = rand() % 4;
                } while(randLane != (l - 1));
                Car temp = lane.back();
                lane.pop_back();
                lanes[randLane].push_back(temp);
                cout << "Switched: ";
                temp.print();
            }
            cout << "Queue: " << endl;
            print(lanes);
            l++;
        }
       time++;
    }


}
// prints the current queue
// arguments: address to toll_booth deque list
// returns none
void print(deque<Car> (&lanes)[4])
{
    for(auto lane : lanes)
    {
        for(auto it : lane)
        {
            cout << "     ";
            it.print();
        }

    }
}
