#ifndef MYQUATERMINSERVER_H
#define MYQUATERMINSERVER_H

#include <QObject>

class MyQuaterMinServer : public QObject
{
    Q_OBJECT
public:
    explicit MyQuaterMinServer(QObject *parent = nullptr);

signals:
    void QuaterMin(bool flank);

public slots:
    void On1SecondElapsed();
};

#endif // MYQUATERMINSERVER_H
