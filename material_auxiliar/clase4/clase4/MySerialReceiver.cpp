#include "MySerialReceiver.h"
#include <QTextStream>

MySerialReceiver::MySerialReceiver(QObject *parent): QObject{parent}
{
    QTextStream qtOut(stdout);

    // Set up Serial
    Serial.setFileName("/home/oglocgreen/Desktop/gijon/implementacion_de_sistemas_de_controll/material_auxiliar/clase4/clase4/data.txt");
    //Serial.setFileName("data.txt");

    if (Serial.open(QIODevice::ReadOnly))
    {
        QObject::connect(&Serial, SIGNAL(readyRead()),
                         this, SLOT(OnNewDataAvailable()));
    }
    else
    {nnnn      n nbb
        qtOut << "Cant Read data \n";
        qtOut.flush();
    }

    QObject::connect(&QuaterMinServer, SIGNAL(QuaterMin(bool flank)),
                     this, SLOT(OnQuaterMin(bool started)));
}

void MySerialReceiver::OnNewDataAvailable()
{
    QTextStream qtOut(stdout);

    QString line_xml = Serial.readLine();


    qtOut <<"New Data Available: Reading XML Line... "<< line_xml <<"\n";
    // Leer Linea del Archibo
    // Decodificar XML
    // Escribir dato


}

void MySerialReceiver::OnQuaterMin(bool started)
{
    QTextStream qtOut(stdout);
    qtOut << "In OnQuaterMin \n";
    if(started)
    {
        // Mulityply data by 2
        qtOut << "Quatersec \n";
    }
    else
    {
        // pass;
    }
}
