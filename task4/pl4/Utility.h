#ifndef UTILITY_H
#define UTILITY_H


#include <QString>
#include <QTextStream>
#include <QVector>
#include <QFile>
#include <QTextStream>

class utility
{
public:
    utility();

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
    void Log_text(QString text, QString path);

};

#endif // UTILITY_H
