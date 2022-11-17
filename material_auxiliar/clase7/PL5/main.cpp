#include <QCoreApplication>
#include "MySocketCliente.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MySocketCliente cli;

    cli.connect();


    return a.exec();
}
