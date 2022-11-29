#include "Utility.h"
using namespace std;

Utility::Utility()
{

}

QString Utility::XmlCreateTage(const QString &text, bool is_start_tag)
{
    QString ret;

    if(is_start_tag)
    {
        ret = "<"+text+">";
    }
     else
    {
        ret = "</"+text+">";
    }
    return ret;
}

QString Utility::XmlGetStr(const QString &textXml, const QString &tagXml)
{
    QString ret;
    int istart, iend;
    int indexStart, lengStr;


    istart = textXml.indexOf("<"+tagXml+">");
    iend = textXml.indexOf("</"+tagXml+">");
    indexStart = istart+tagXml.length()+2;
    lengStr = iend - indexStart;
    ret = textXml.mid(indexStart, lengStr);

    return ret;
}




float Utility::XmlGetFloat(const QString& textXml,const QString& tag)
{
    return textXml.mid(GetStart(textXml, tag), GetLen(textXml, tag)).toFloat();
}

int Utility::XmlGetInt(const QString& textXml,const QString& tag)
{
    return textXml.mid(GetStart(textXml, tag), GetLen(textXml, tag)).toInt();
}

QVector<float> Utility::XmlGetVector(const QString& xml,const QString& tag)
{
    QVector<float> ret;
    QString constens = XmlGetStr(xml, tag).trimmed();

    if (constens.startsWith("[") && constens.endsWith("]"))
    {
            constens = constens.mid(1,constens.length()-2);
            QStringList values = constens.split(",");
            ret.resize(values.length());
            for(int i= 0; i<values.length(); i++)
            {
                ret[i]=values[i].toFloat();
            }
    }
    return ret;
}

int Utility::GetStart(const QString &textXml, const QString &tagXml)
{
    int istart;

    istart = textXml.indexOf("<"+tagXml+">") +tagXml.length()+2;

    return istart;
}

int Utility::GetLen(const QString &textXml, const QString &tagXml)
{
    int istart, iend;
    int indexStart, lengStr;


    istart = textXml.indexOf("<"+tagXml+">");
    iend = textXml.indexOf("</"+tagXml+">");
    indexStart = istart+tagXml.length()+2;
    lengStr = iend - indexStart;

    return lengStr;
}



void Utility::Log_text_string(QString text1, QString path)
{
    QFile file_log(path);    //linux

    if(file_log.open(QIODevice::WriteOnly | QIODevice::Text)) {

        file_log.write("text blablabla"); // this works
        file_log.write(text1.toLatin1() + "\n");            // this doesn´t

    }
    file_log.close();
}

void Utility::Log_text_stream(QTextStream text1, QString path)
{
    QFile file_log(path);    //linux
    // writing a Stream of Text
    // Again just works with "text like that"
    QTextStream out(&file_log);

    out << "text balablalbla"; //this works
    //out << to_string(text1);            // this doesn´t
}



void setDatosLog(QString log_msg,QString log_path)
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

void OnAddToLog(const QString& NewDataLogIn,QString log_path)

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

