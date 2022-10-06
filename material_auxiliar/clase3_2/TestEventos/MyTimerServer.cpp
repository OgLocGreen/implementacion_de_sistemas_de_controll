#include "MyTimerServer.h"
#include <QTextStream>
#include <QObject>

//hier alles rein zum Timer

MyTimerServer::MyTimerServer(const QString &i_name, QObject *parent): QObject(*parent)
{
    name = i_name;
}

void MyTimerServer::OnTimerEvent()
{
    QTextStream qtOut(stdout);
    count++;
    qtOut << "Timer Evenet!!! \n" << count << endl;
    qtOut.flush();


}
