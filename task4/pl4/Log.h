#ifndef LOG_H
#define LOG_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDate>

class Log
{
private:
    QString log_file_path;
public:
    Log();
    Log(QString path);
    void setDatosLog(QString log_msg);
    void setDatosLog(QString log_msg,QString log_path);
    void OnAddToLog(const QString& NewDataLogIn);
    void OnAddToLog(const QString& NewDataLogIn,QString log_path);

    void set_log_path(QString path);
};

#endif // LOG_H
