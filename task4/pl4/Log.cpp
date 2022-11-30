#include "Log.h"

Log::Log()
{
}

Log::Log(QString path)
{
    log_file_path = path;
}

void Log::setDatosLog(QString log_msg)
{
    QString lastlog;

    QFile log(log_file_path);

    if (log.open(QIODevice::ReadOnly)){
        QTextStream leer(&log);
        lastlog.append(leer.readAll());
        log.close();
    }
    if (log.open(QIODevice::WriteOnly)){
        QTextStream escribir(&log);
        escribir<<lastlog;
        escribir<<log_msg;
        log.close();
    }
}

void Log::setDatosLog(QString log_msg,QString log_path)
{
    QString lastlog;

    QFile log(log_path);

    if (log.open(QIODevice::ReadOnly)){
        QTextStream leer(&log);
        lastlog.append(leer.readAll());
        log.close();
    }
    if (log.open(QIODevice::WriteOnly)){
        QTextStream escribir(&log);
        escribir<<lastlog;
        escribir<<log_msg;
        log.close();
    }
}

void Log::OnAddToLog(const QString& NewDataLogIn)

{
    QString NewDataLog;
    NewDataLog.append(QDateTime::currentDateTime().toString("hh.mm.ss"));
    NewDataLog.append(" ");
    NewDataLog.append(QDate::currentDate().toString());
    NewDataLog.append(" ");
    NewDataLog.append(NewDataLogIn);
    NewDataLog.append("\r\n");
    setDatosLog(NewDataLog, log_file_path);

}


void Log::OnAddToLog(const QString& NewDataLogIn,QString log_path)

{
    QString NewDataLog;
    NewDataLog.append(QDateTime::currentDateTime().toString("hh.mm.ss"));
    NewDataLog.append(" ");
    NewDataLog.append(QDate::currentDate().toString());
    NewDataLog.append(" ");
    NewDataLog.append(NewDataLogIn);
    NewDataLog.append("\r\n");
    setDatosLog(NewDataLog, log_path);

}

void Log::set_log_path(QString path)
{
    log_file_path = path;
}
