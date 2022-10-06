#include "mysignal.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

MySignal::MySignal(int i_nmax)
{
    data.resize(i_nmax);
    cout << "Constructing object " << name << " of type MySignal" << endl;
}

MySignal::MySignal(const string& i_name, int i_nmax)
{
    name = i_name;
    data.resize(i_nmax);
    cout << "Constructing named object " << name << " of type MySignal" << endl;
}

MySignal::~MySignal()
{
      cout << "Destroying object " << name << " of type MySignal" << endl;
}

void MySignal::NewSample(float new_value)
{
    data.insert(data.begin(),new_value);
    cout << "Adding new value to " << name << ": " << new_value << endl;
}

string MySignal::GetName() const
{
    return name;
}

float MySignal::GetValueDelayed(int delay) const
{
    //TAREA
    return 0;
}

int MySignal::GetCurrentSize() const
{
    //return the current Size of the vector
    int tmp = data.size();

    return tmp;
}

int MySignal::GetMaxSize() const
{
    //return the Max Size of the vector

    return 0;
}

float MySignal::GetMin() const
{
    //return the minum of the vector
    float min;
    for (int x; x< GetCurrentSize(); x++)
    {
        if (min > data[x])
        {
            min = x;
        }
    }
    // or use min = *min_element(data.begin(), data.end());
    return min;
}



