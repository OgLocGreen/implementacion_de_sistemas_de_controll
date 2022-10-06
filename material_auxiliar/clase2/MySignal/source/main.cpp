#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include <iterator>
#include "../header/mysignal.h"

using namespace std;

void CheckMySignal(const MySignal& one, const MySignal& two)    //& so that the object isn't copied but used itself;
                                                                //const so that the variable can't be changed
{
    cout << "Checking one and two" << endl;
    cout << "ONE = " << one.GetName();
    cout << " TWO = " << two.GetName() << endl;
}

int main()
{
    MySignal tempk(4);//("Temperature");
    MySignal *otherk=NULL; //inicializar con un pointer 0
    vector<float> temp;
    float temp_new = 1;
    float temp_sum;
    float temp_min;
    float value_min;
    int x;
    int n;

    //tempk.name="Temperature";

    // str = "Hello world!";

    // cout << "Hello World!" << endl;
    // cout << str << endl;
    //cout << "Introd valor: ";
    //cin >> x;
    //cout << "X = " << x << endl;


    cout << "Introduzca tamano tabla: "<<endl;
    cin >> n;
    //temp.resize(n);
    //cout<<"tabla is a vector of "<< temp.size()<<" values"<<endl;


    if(n>10)
    {
        //MySignal otherk;
        //otherk.NewSample(25);
        otherk=new MySignal("other", 4);
        //otherk->name="other";
        otherk->NewSample(25); //giyon mayor (flecha)

        CheckMySignal(tempk, *otherk);
    }

    while(temp_new>0)
    {
        cout<<"Introduzca valor Temperatura: ";
        cin>>temp_new;
    /*    temp.insert(temp.begin(),temp_new);
        if(temp.size()>n)
            temp.resize(n);
     */

        tempk.NewSample(temp_new);
        if(temp_new<10)
        {
            delete otherk;
            otherk=NULL;
        }
        cout<<"The last "<< temp.size() << " temperatures are: ";
        for (int j=0; j<temp.size();j++)
        {
            cout<< temp[j]<<" ";
        }
        if (temp.size()==n)
        {
            temp_min = *min_element(temp.begin(), temp.end());
            cout<<"(min = "<<temp_min<<" )";
            //temp_sum=0;
            //for (int i=0;i<n;i++)
                //temp_sum=+temp[i];
        }
        else
        {
            cout<<"(incompleta, no se calcula min)";
        }
        cout<<endl;

    }
    return 0;
}
