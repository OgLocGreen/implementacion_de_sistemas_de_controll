
#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class MySignal {
    private:
    int n = 0;
    float min = NULL;
    float last_min = NULL;
    vector<float> temperatur_vektor;

  public:
    MySignal():n(5)
    {
        cout << "How many values do you want to save?(Default 5) ";
        cin >> n;
        temperatur_vektor.resize(n);
        for(int i = 0; i<temperatur_vektor.size();i++)
        {
            cout << "Add Temperatur: ";
            cin >> temperatur_vektor[i];
            cout << endl;
        }
    }
    void anadir();
    void info();
    void get_min();
    void alarm();
};

void MySignal::anadir()
{
    int temp_now;
    cout << "which temp do you want to add? ";
    cin >> temp_now;
    //temperatur_vektor.resize(temperatur_vektor.size()+1);
    temperatur_vektor.insert(temperatur_vektor.begin(),temp_now);

}

void MySignal::info()
{
    for(int i = 0; i<temperatur_vektor.size(); i++)
    {
        cout << temperatur_vektor[i] << " "<<endl;
    }
}

void MySignal::get_min()
{
    min = *min_element(temperatur_vektor.begin(), temperatur_vektor.end());
    cout << "min temp is: " << min <<endl;
}

void MySignal::alarm()
{

    if(min < last_min && last_min-min >=5)
    {
        cout << "Warning!!!"<<endl;
    }
    if (min!=last_min)
    {
        last_min = min;
    }       
}


int main()
{
    cout << "Prak1" << endl;
    MySignal Signal;
    Signal.info();
    Signal.anadir();
    Signal.info();
    Signal.get_min();
    Signal.info();

    MySignal Signal2;
    Signal2.anadir();
    Signal2.get_min();
    Signal2.alarm();

    Signal2.anadir();
    Signal2.get_min();
    Signal2.alarm();

    Signal2.info();

    return 0;
}