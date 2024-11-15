// COMSC-210 | 210-lab-33 | Daniil Malakhov
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

void print(deque<Car>& lane);

int main()
{
    srand(time(0));

    deque<Car> lanes[LANES];

    int i = 0;

    cout << "Initial Queue: " << endl;

    for(int j = 0; j < LANES; j++)
    {
        while(i < INITIAL_QUEUE)
        {
            Car temp;
            lanes[j].push_back(temp);
            cout << "ss" << endl;
            i++;
        }
        i = 0;
    }
    for(int j = 0; j < LANES; j++)
    {
        cout << "Lane " << j + 1 << ": " << endl;
        print(lanes[j]);
    }


    int time = 1;
    while(time <= 20)
    {
        cout << "Time " << time << ": " << endl;
        int l = 1;
        for (int i = 0; i < LANES; i++)
        {
            int prob = rand() % 100 + 1;  // returns random number 1-100
            cout << "Lane " << l << ": ";

            if (prob <= PROB3)
            {
                if(!lanes[i].empty()){
                    int randLane = rand() % 4;
                    do
                    {
                        randLane = rand() % 4;
                    } while(randLane == (l - 1));
                    Car temp;
                    temp.setMake(lanes[i].back().getMake());
                    temp.setYear(lanes[i].back().getYear());
                    temp.setTransponder(lanes[i].back().getTransponder());
                    lanes[i].pop_back();
                    lanes[randLane].push_back(temp);
                    cout << "Switched: ";
                    temp.print();
                }
            }
            else if (prob <= PROB2)
            {
                Car temp;
                cout << "Joined lane: ";
                temp.print();
                lanes[i].push_back(temp);
            }
            else if (prob <= PROB1)
            {
                if(!lanes[i].empty()){
                    cout << "Left lane: ";
                    lanes[i].front().print();
                    lanes[i].pop_front();
                }
            }
            else
                cout << endl;
            cout << "Queue: " << endl;
            print(lanes[i]);
            l++;
        }
        cout << endl;
        time++;
    }


}
// prints the current queue
// arguments: address to toll_booth deque list
// returns none
void print(deque<Car>& lane)
{
    if (!lane.empty())
    {
        for(auto it : lane)
        {
            cout << "     ";
            it.print();
        }
    }
    else
        cout << "     Lane is currently empty!" << endl;

}
