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

    void NewSample(float new_value);
    float GetValueDelayed(int delay) const; //know clue what this is
    int GetCurrentSize() const;             //return the current Size of the vector how many values are in the vector
    int GetMaxSize() const;                 //return the Max Size of the vector
    float GetMin() const;                   //return the minum of the vector
    float GetMinValue() const;    //return the minum Value of the vector
    void GetTable();
    string GetName() const; //for functions with arguments of type const

};

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
    data.insert(data.begin(),  new_value);
    cout << "Adding new value to " << name << ": " << new_value << endl;
}

string MySignal::GetName() const
{
    return name;
}

float MySignal::GetValueDelayed(int delay) const
{
    return data[delay];
}

int MySignal::GetCurrentSize() const
{
    //return the current Size of the vector

    return data.size();
}

int MySignal::GetMaxSize() const
{
    //return the Max Size of the vector
    return nmax;
}

float MySignal::GetMinValue() const
{
    //return the minum value of the vector
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

float MySignal::GetMin() const
{
    return *min_element(data.begin(), data.end());
}

void MySignal::GetTable()
{
    for (int j=0; j<GetCurrentSize();j++)
    {
        cout<< GetValueDelayed(j)<<" ";
    }
}


void CheckMySignal(const MySignal& one, const MySignal& two)    //& so that the object isn't copied but used itself;
                                                                //const so that the variable can't be changed
{
    cout << "Checking one and two" << endl;
    cout << "ONE = " << one.GetName();
    cout << " TWO = " << two.GetName() << endl;
}

int main()
{
    vector<float> temp;
    float temp_new = 1;
    int n;
    string name;


    cout << "Table size: "<<endl;
    cin >> n;
    cout << "Table name: "<<endl;


    MySignal TempTable("Tint", n);

    while(temp_new>0)
    {
        cout<<"new temperature value: ";
        cin>>temp_new;
        TempTable.NewSample(temp_new);

        cout<<"The last "<< TempTable.GetCurrentSize() << " temperatures are: ";
        TempTable.GetTable();

        if (TempTable.GetCurrentSize()==TempTable.GetMaxSize())
        {
            cout<<"(min = "<<TempTable.GetMin()<<")"<<endl;;
        }
        else
        {
            cout<<"(incomplete, not possible to calculate min)"<<endl;
        }

    }
    return 0;
}
