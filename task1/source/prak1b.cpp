
#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class MySignal {
    private:
    int n = 0;
    vector<float> temperatur_vektor_outdoor;
    vector<float> temperatur_vektor_indoor;
  public:
    MySignal()
    {
        cout << "How many values do you want to save?";
        cin >> n;
        temperatur_vektor_outdoor.resize(n);
        temperatur_vektor_indoor.resize(n);
        for(int i = 0; i<temperatur_vektor_indoor.size();i++)
        {
            cout << "Add Temperatur: ";
            cin >> temperatur_vektor_outdoor[i]>>temperatur_vektor_indoor[i];
            cout << endl;
        }
    }
    int anadir();
    void info();
    float get_min(const vector<float>& vec_tmp);
    bool isNumber(const string& str);
};

int MySignal::anadir()
{
    string temp_now_out;
    string temp_now_in;

    cout << "which temp do you want to add? if you get out of While write no else just write the number: ";
    cin >> temp_now_out >> temp_now_in;
    if (isNumber(temp_now_out) && isNumber(temp_now_in))
    {
        float temp_numb_out = stof(temp_now_out);
        float temp_numb_in = stof(temp_now_in);

        temperatur_vektor_indoor.insert(temperatur_vektor_indoor.begin(),temp_numb_in);
        temperatur_vektor_outdoor.insert(temperatur_vektor_outdoor.begin(),temp_numb_out);
        info();
        int diff = get_min(temperatur_vektor_indoor) - get_min(temperatur_vektor_outdoor);
        if(diff > 5 || diff <-5)
        {
            cout << "-->Alarm!!!<--" << endl;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

void MySignal::info()
{
    cout << "temperatur_vektor_outdoor"<<endl;
    for(int i = 0; i<temperatur_vektor_outdoor.size(); i++)
    {
        cout << temperatur_vektor_outdoor[i] << ", ";
    }
    cout << endl;
    cout << "temperatur_vektor_indoor"<<endl;
    for(int i = 0; i<temperatur_vektor_indoor.size(); i++)
    {
        cout << temperatur_vektor_indoor[i] << ", ";
    }
    cout << endl;

}

float MySignal::get_min(const vector<float>& vec_tmp)
{
    float min = *min_element(vec_tmp.begin(), vec_tmp.end());
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