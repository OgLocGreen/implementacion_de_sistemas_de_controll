#ifndef UTILITY_H
#define UTILITY_H


#include <QString>
#include <QTextStream>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QDateTime>


class Utility
{    
public:
    Utility();

    // Get_XML
    int XmlGetInt(const QString& textXml,const QString& tag);
    float XmlGetFloat(const QString& textXml,const QString& tag);
    QVector<float> XmlGetVector(const QString& xml,const QString& tag);

    void XmlGetAll(const QString& textXml, const QString& tag);

    //Set_XML

    int GetLen(const QString &textXml, const QString &tagXml);
    int GetStart(const QString &textXml, const QString &tagXml);
    QString XmlCreateTage(const QString& text, bool is_start_tag);
    QString XmlGetStr(const QString& text, const QString& tag);


    // Log_File
    void Log_text_string(QString text1, QString path);
    void Log_text_stream(QTextStream text1, QString path);

    void setDatosLog(QString log_msg, QString log_path);
    void OnAddToLog(const QString& NewDataLogIn,QString log_path);
};

#endif // UTILITY_H
