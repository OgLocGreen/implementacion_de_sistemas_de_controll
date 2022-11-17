#include "MySocketCliente.h"
#include <QAbstractSocket>
#include <iostream>

using namespace std;

MySocketCliente::MySocketCliente(QObject *parent): QObject{parent}
{



    QObject::connect(&sock, SIGNAL(connected()),
                     this, SLOT(OnClientConnected()));

    QObject::connect(&sock, SIGNAL(disconnected()),
                     this, SLOT(OnClientDisconnected()));

    /*QObject::connect(&sock, SIGNAL(errorOccurred(QAbstractSocket::SocketError socketError)),
                     this, SLOT(OnError(QAbstractSocket::SocketError err)));

    QObject::connect(&sock, SIGNAL(readReady()),
                     this, SLOT(OnDataReceived()));*/
}

void MySocketCliente::connect()
{
    const QString IpAdresse = "http://isa.uniovi.es/~ialvarez/Descargas/pagina_de_prueba.htm";
    quint16 port = 80;

    cout << "Connecting ..."<<endl;
    sock.connectToHost(IpAdresse,port);
    if (sock.waitForConnected(1000))
        qDebug("Connected!");
    cout << "Connected ..."<<endl;
}

void MySocketCliente::OnClientConnected()
{
    cout << "Is connected"<<endl;
}

void MySocketCliente::OnClientDisconnected()
{

}
void MySocketCliente::OnDataReceived()
{

}

void MySocketCliente::OnError(QAbstractSocket::SocketError err)
{
    cout << "Errrrroooorrrr"<<endl;
    cout << err << endl;
}
