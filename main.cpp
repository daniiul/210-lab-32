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

void print(deque<Car>& toll_booth);

int main()
{
    deque<Car> toll_booth;
    int i = 0;

    cout << "Initial Queue: " << endl;
    while(i < INITIAL_QUEUE)
    {
        Car temp;
        toll_booth.push_back(temp);
        i++;
    }
    print(toll_booth);

    int time = 1;
    while(!toll_booth.empty())
    {
        int prob = rand() % 100 + 1;  // returns random number 1-100
        cout << "Time " << time << " operation: ";
        if (prob <= 55)
        {
            cout << "Left lane: ";
            toll_booth.front().print();
            cout << endl;
            toll_booth.pop_front();
        }
        else if (prob <= 44)
        {
            Car temp;
            cout << "Joined lane: ";
            temp.print();
            cout << endl;
            toll_booth.push_back(temp);
        }
        cout << endl;
        print(toll_booth);
        time++;
    }


}

void print(deque<Car>& toll_booth)
{
    for(auto it : toll_booth)
    {
        cout << "     ";
        it.print();
    }
}
