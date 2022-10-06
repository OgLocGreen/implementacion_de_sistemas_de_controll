#include <QCoreApplication>
#include <QTextStream>
#include <iostream>
#include "SimulSerialPort.h"
#include "MySerialReceiver.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SimulSerialPort Serial;
    MySerialReceiver recv;
    MyQuaterMinServer QuaterMinServer;
    QTextStream qtOut(stdout);

    qtOut << "Hello Serialport \n";
    qtOut.flush();

    return a.exec();
}

