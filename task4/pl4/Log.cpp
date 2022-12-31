#include "Log.h"

Log::Log()
{
}
Log::Log(QString path)
{
    // non-deafault constructor with the file path
    log_file_path = path;
}

void Log::setDatosLog(QString log_msg)
{
    // Write the new "log_msg" to the the Log File
    // First read the log_file
    // then add the msg to the log_file
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
    // Write the new "log_msg" to the the Log File
    // First read the log_file with the "log_path"
    // then add the msg to the log_file
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
    // This writes the LogMessage in the write order and adds the Date
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
    // This writes the LogMessage in the write order and adds the Date
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
    // Setter for the path
    log_file_path = path;
}
