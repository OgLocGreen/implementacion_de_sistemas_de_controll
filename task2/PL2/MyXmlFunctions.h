#ifndef MYXMLFUNCTIONS_H
#define MYXMLFUNCTIONS_H

#include <QString>
#include <QTextStream>
#include <QVector>

QString XmlCreateTage(const QString& text, bool is_start_tag);
QString XmlGetStr(const QString& text, const QString& tag);

int GetLen(const QString &textXml, const QString &tagXml);
int GetStart(const QString &textXml, const QString &tagXml);

float XmlGetFloat(const QString& textXml,const QString& tag);
QVector<float> XmlGetVector(const QString& xml,const QString& tag);


#endif // MYXMLFUNCTIONS_H
