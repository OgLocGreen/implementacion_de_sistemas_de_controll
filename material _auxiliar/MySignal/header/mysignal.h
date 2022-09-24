#ifndef MYSIGNAL_H
#define MYSIGNAL_H
#include <vector>
#include <string>

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

    void NewSample(float new_value);
    float GetValueDelayed(int delay) const; //TAREA
    int GetCurrentSize() const;             //return the current Size of the vector
    int GetMaxSize() const;                 //return the Max Size of the vector
    float GetMin() const;                   //return the minum of the vector

    string GetName() const; //for functions with arguments of type const

};

#endif // MYSIGNAL_H
