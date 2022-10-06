#ifndef MYTIMERSERVER_H
#define MYTIMERSERVER_H


#include <QObject>
#include <QString>

class MyTimerServer: public QObject
{
    Q_OBJECT
private:
    int count = 0;
    QString name;
public:
    explicit MyTimerServer(const QString& i_name,
                           QObject *parent = 0);

signals:

public slots:
    void OnTimerEvent();



};






#endif // MYTIMERSERVER_H
