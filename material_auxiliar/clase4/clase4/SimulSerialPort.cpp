#include "SimulSerialPort.h"

SimulSerialPort::SimulSerialPort(QObject *parent) :QFile(parent)
{
    QObject::connect(&simulTimer,SIGNAL(timeout()),
                                      this,(SLOT(OnIsTimeToSend()))
                                      );
    simulTimer.start(500);
}

void SimulSerialPort::OnIsTimeToSend()
{
    emit readyRead();
}
