#include "MySignal.h"



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

void MySignal::SetNewSample(float new_value)
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
    for (int x=0; x < GetCurrentSize(); x++)
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

float MySignal::GetMedian(int n) const
{
    float median;
    for(int i=0; i<n; i++)
    {
        median += data[data.size()-i];

    }
    median = median/n;

    return median;
}


vector<float> MySignal::GetLastNValues(int n) const
{
    vector<float> ret;
    ret.reserve(n);
    for(int i=0; i<n;i++)
    {
        ret[i]=data[data.size()-i];
    }

    return ret;
}

void CheckMySignal(const MySignal& one, const MySignal& two)    //& so that the object isn't copied but used itself;
                                                                //const so that the variable can't be changed
{
    cout << "Checking one and two" << endl;
    cout << "ONE = " << one.GetName();
    cout << " TWO = " << two.GetName() << endl;
}
