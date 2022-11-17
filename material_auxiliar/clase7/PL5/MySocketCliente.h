#ifndef MYSOCKETCLIENTE_H
#define MYSOCKETCLIENTE_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QIODevice>


class MySocketCliente : public QObject
{
    Q_OBJECT
private:
    QTcpSocket sock;

public:
    explicit MySocketCliente(QObject *parent = nullptr);
    void connect();

signals:
    void connected();

public slots:
    void OnClientConnected();
    void OnClientDisconnected();
    void OnDataReceived();
    void OnError(QAbstractSocket::SocketError err);
};

#endif // MYSOCKETCLIENTE_H
