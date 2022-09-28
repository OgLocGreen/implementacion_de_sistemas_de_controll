#ifndef MYSIGNAL_H
#define MYSIGNAL_H

#include <vector>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
//#include <iterator>

using namespace std;

class MySignal
{
private:
    vector<float> data; //implementar en tarea
    int nmax;           //implementar en tarea
    string name;

public:
    MySignal(int i_nmax);
    MySignal(const string& i_name, int i_nmax);
    ~MySignal();

    void SetNewSample(float new_value);
    float GetValueDelayed(int delay) const; //know clue what this is
    int GetCurrentSize() const;             //return the current Size of the vector how many values are in the vector
    int GetMaxSize() const;                 //return the Max Size of the vector
    float GetMin() const;                   //return the minum of the vector
    float GetMinValue() const;    //return the minum Value of the vector
    void GetTable();
    float GetMedian(int n) const;
    vector<float> GetLastNValues(int n) const;
    string GetName() const; //for functions with arguments of type const

};


#endif // MYSIGNAL_H
