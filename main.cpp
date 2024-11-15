#include <deque>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <iostream>
#include "Car.h"

using namespace std;

const int INITIAL_QUE = 2;

void print(deque<Car>& toll_booth);

int main()
{
    deque<Car> toll_booth;
    int i = 0;

    cout << "Initial Que: " << endl;
    while(i < INITIAL_QUE)
    {
        Car temp;
        toll_booth.push_back(temp);
        i++;
    }

    print(toll_booth);

    int prob = rand() % 100 + 1;  // returns random number 1-100
}

void print(deque<Car>& toll_booth)
{
    for(auto it : toll_booth)
    {
        it.print();
    }
}
