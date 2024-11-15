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

const int INITIAL_QUEUE = 2;

void print(deque<Car> (&lanes)[4]);

int main()
{
    srand(time(0));

    deque<Car> lanes[4];

    int i = 0;

    cout << "Initial Queue: " << endl;
    while(i < INITIAL_QUEUE)
    {
        for(auto lane : lanes)
        {
            Car temp;
            lane.push_back(temp);
            i++;
        }
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
            cout << "Time " << time << " operation: ";
            if (prob <= 55)
            {
                cout << "Left lane: ";
                toll_booth.front().print();
                toll_booth.pop_front();
            }
            else
            {
                Car temp;
                cout << "Joined lane: ";
                temp.print();
                toll_booth.push_back(temp);
            }
            cout << "Queue: " << endl;
            print(toll_booth);
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
