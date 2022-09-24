#include "mysignal.h"
#include <iostream>
using namespace std;

MySignal::MySignal(int i_nmax)
{
    cout << "Constructing object " << name << " of type MySignal" << endl;

}

MySignal::MySignal(const string& i_name, int i_nmax)
{
    name = i_name;
    cout << "Constructing named object " << name << " of type MySignal" << endl;
}

MySignal::~MySignal()
{
      cout << "Destroying object " << name << " of type MySignal" << endl;
}

void MySignal::NewSample(float new_value)
{
    //data.insert(...) //TAREA
    cout << "Adding new value to " << name << ": " << new_value << endl;
}

string MySignal::GetName() const
{
    return name;
}


