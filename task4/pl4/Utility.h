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
private:
    QString xml_file_path;

public:
    Utility();

    void set_xml_path(QString path);

    // Get_XML
    int GetXmlInt(const QString& textXml,const QString& tag);
    float GetXmlFloat(const QString& textXml,const QString& tag);
    QVector<float> GetXmlVector(const QString& xml,const QString& tag);
    QString GetXmlTag(const QString& text);
    QString GetXmlStr(const QString& text, const QString& tag);

    //Set_XML
    int GetLen(const QString &textXml, const QString &tagXml);
    int GetStart(const QString &textXml, const QString &tagXml);
    QString XmlCreateTag(const QString& text, bool is_start_tag);



    // XML_File
    QString ReadXml();
    QString ReadXml(QString xml_path);
    int WriteXml(QString xml_msg);
    int WriteXml(QString xml_msg, QString xml_path); // return 1 wenn all good
    int AppenedToXml(QString xml_msg);
    int AppenedToXml(QString xml_msg,QString xml_path);

    // Log_File // reserve
    void Log_text_string(QString text1, QString path);
    void Log_text_stream(QTextStream text1, QString path);

};

#endif // UTILITY_H
