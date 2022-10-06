#ifndef MYSERIALRECEIVER_H
#define MYSERIALRECEIVER_H

#include <QObject>
#include "SimulSerialPort.h"
#include "MyQuaterMinServer.h"

class MySerialReceiver : public QObject
{
    Q_OBJECT
private:
    SimulSerialPort Serial;
    MyQuaterMinServer QuaterMinServer;

public:
    explicit MySerialReceiver(QObject *parent = nullptr);

signals:

public slots:
    //void OnIsTimerToSend();
    void OnNewDataAvailable();
    void OnQuaterMin(bool started);
};

#endif // MYSERIALRECEIVER_H
