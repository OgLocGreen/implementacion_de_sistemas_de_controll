
#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class MySignal {
    private:
    int n = 0;
    vector<float> temperatur_vektor;

  public:
    MySignal()
    {
        cout << "How many values do you want to save?";
        cin >> n;
        temperatur_vektor.resize(n);
        for(int i = 0; i<temperatur_vektor.size();i++)
        {
            cout << "Add Temperatur: ";
            cin >> temperatur_vektor[i];
            cout << endl;
        }
    }
    int anadir();
    void info();
    float get_min();
    bool isNumber(const string& str);
};

int MySignal::anadir()
{
    string temp_now;
    cout << "which temp do you want to add? if you get out of While write no else just write the number: ";
    cin >> temp_now;
    if (isNumber(temp_now))
    {
        float temp_numb = stof(temp_now);
        if(temp_numb - get_min() < -5 )
        {
            cout << "-->Alarm!!!<--" << endl;
        }
        temperatur_vektor.insert(temperatur_vektor.begin(),temp_numb);
        info();
        return 1;
    }
    else
    {
        return 0;
    }
}

void MySignal::info()
{
    for(int i = 0; i<temperatur_vektor.size(); i++)
    {
        cout << temperatur_vektor[i] << " "<<endl;
    }
}

float MySignal::get_min()
{
    float min = *min_element(temperatur_vektor.begin(), temperatur_vektor.end());
    cout << "min temp is: " << min <<endl;
    return min;
}


bool MySignal::isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

int main()
{
    cout << "Prak1" << endl;
    MySignal Signal;
    Signal.info();
    bool check = 1;
    while(check)
    {
        check = Signal.anadir();
    }
    cout << "Fnished!!!"<<endl;
    return 0;
}