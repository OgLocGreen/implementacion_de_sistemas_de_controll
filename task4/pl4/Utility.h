#ifndef UTILITY_H
#define UTILITY_H


#include <QString>
#include <QTextStream>
#include <QVector>

class utility
{
public:
    utility();

    QString XmlCreateTage(const QString& text, bool is_start_tag);
    QString XmlGetStr(const QString& text, const QString& tag);

    int GetLen(const QString &textXml, const QString &tagXml);
    int GetStart(const QString &textXml, const QString &tagXml);

    float XmlGetFloat(const QString& textXml,const QString& tag);
    QVector<float> XmlGetVector(const QString& xml,const QString& tag);

    QString XmlGetField(const QString&text, const QString& tag);
};

#endif // UTILITY_H
