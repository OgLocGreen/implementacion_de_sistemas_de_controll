#include "MyQuaterMinServer.h"
#include <QTime>

MyQuaterMinServer::MyQuaterMinServer(QObject *parent)
    : QObject{parent}
{
    emit QuaterMin(false);

}

void MyQuaterMinServer::On1SecondElapsed()
{
    QTime now;
    now = QTime::currentTime();
    int sec = now.second();
    if (sec % 15)
    {
        emit QuaterMin(true);
    }
    else
    {
        emit QuaterMin(false);
    }
}
