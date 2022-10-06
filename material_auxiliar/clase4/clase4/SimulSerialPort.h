#ifndef SIMULSERIALPORT_H
#define SIMULSERIALPORT_H

#include <QFile>
#include <QTimer>

class SimulSerialPort : public QFile
{
    Q_OBJECT
private:
    QTimer simulTimer;

public:
    explicit SimulSerialPort(QObject *parent = nullptr);
    void setPortName(const QString& name) { setFileName(name); }
    void setBaudRate(int) { return; }
    void setDataBits(int) { return; }
    void setParity(int) { return; }
    void setStopBits(int) { return; }


signals:

public slots:
    void OnIsTimeToSend();
};

#endif // SIMULSERIALPORT_H



