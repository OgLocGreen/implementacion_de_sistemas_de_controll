#include <iostream>
#include <QString>
#include <QTextStream>
#include "MyXmlFunctions.h"
#include "MySignal.h"


using namespace std;

int main()
{
    QTextStream out(stdout);
    QTextStream in(stdin);
    QString myString;
    float  myFloat;
    QVector<float> myVektor;
    QString name;

    int nmax;


    QString xmlText = "hola que tal <Num>14</Num> <Name>MyName</Name> <Other>8.5</Other> <list>[0.333, 0.33, 0.3]</list>";

    out.flush();

    // Getting and Printing the  String
    out << "GetString" << "\n";
    name = "Name";
    myString = XmlGetStr(xmlText, name);
    out << myString << "\n";
    out.flush();


    // Getting and Printing the Float Var
    out << "GetFloat" << "\n";
    name = "Other";
    myFloat = XmlGetFloat(xmlText, name);
    out << myFloat << "\n";
    out.flush();

    // Getting and Printing the Vektor
    out << "GetVector" << "\n";
    name = "list";
    myVektor = XmlGetVector(xmlText, name);
    for(int i=0; i<myVektor.length(); i++)
    {
        out << myVektor[i] << "\n";
    }
    out.flush();

    // Get Signal Var and multiply them with const Factor
    out << "How big do you want the Tabel to be: " << "\n";
    in >> nmax;
    MySignal TabelTemp("Temp",nmax);
    out << "Inserte New Temp: " << "\n";
    out.flush();
    float new_temp;

    int n;
    // out << "median over how many values?: \n";
    // in >> n;
    n = myVektor.length();

    while(1)
    {
        in >> new_temp;
        TabelTemp.SetNewSample(new_temp);
        out << "Tabel is now: \n";
        TabelTemp.GetTable();
        out.flush();
        if(TabelTemp.GetCurrentSize() >= 3)
        {
            out << "Median of 3 is: \n";
            out << TabelTemp.GetMedian(3);
        }
        else
        {
            out << "No 3 Values \n";
        }

        out.flush();

        if(TabelTemp.GetCurrentSize() > n)
        {
            out << "Median + Const of "<< n << " is: \n";
            vector<float> LastN;
            LastN.resize(n);
            LastN = TabelTemp.GetLastNValues(n);

            float median = 0;

            for(int i = 0; i< n; i++)
            {
                median += LastN[i]*myVektor[i];
            }
            median += median/n;
            out << "Median: "<< median <<"\n";

            out.flush();
        }

    }





    return 0;
}
