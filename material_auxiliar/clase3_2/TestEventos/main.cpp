#include <QCoreApplication>
#include <QTextStream>
#include <QTimer>
#include "MyTimerServer.h"

using namespace std;

int main(int argc, char *argv[])
{
    QTextStream qtOut(stdout);
    qtOut << "BEFORE CREATING a\n"; qtOut.flush();
    QCoreApplication a(argc, argv);
    qtOut << "AFTER CREATING a\n"; qtOut.flush();


    QTimer t1, t2;

    MyTimerServer s("S1");

    QObject::connect(&t1, SIGNAL(timeout()),&s, SLOT(OnTimerEvent())); //was macht das hier genau?

    t1.start(1000);
    t2.start(1000);

    int result = a.exec();
    qtOut << "AFTER FINISHING EXEC \n"; qtOut.flush();

    return result;
}
