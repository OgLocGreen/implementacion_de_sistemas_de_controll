#include "MyXmlFunctions.h"


QString XmlCreateTage(const QString &text, bool is_start_tag)
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

QString XmlGetStr(const QString &textXml, const QString &tagXml)
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

int GetStart(const QString &textXml, const QString &tagXml)
{
    int istart;

    istart = textXml.indexOf("<"+tagXml+">") +tagXml.length()+2;

    return istart;
}

int GetLen(const QString &textXml, const QString &tagXml)
{
    int istart, iend;
    int indexStart, lengStr;


    istart = textXml.indexOf("<"+tagXml+">");
    iend = textXml.indexOf("</"+tagXml+">");
    indexStart = istart+tagXml.length()+2;
    lengStr = iend - indexStart;

    return lengStr;
}


float XmlGetFloat(const QString& textXml,const QString& tag)
{
    return textXml.mid(GetStart(textXml, tag), GetLen(textXml, tag)).toFloat();
}


QVector<float> XmlGetVector(const QString& xml,const QString& tag)
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
