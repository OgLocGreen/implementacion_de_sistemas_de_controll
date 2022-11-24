#include "Utility.h"

utility::utility()
{

}

QString utility::XmlCreateTage(const QString &text, bool is_start_tag)
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

QString utility::XmlGetStr(const QString &textXml, const QString &tagXml)
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

float utility::XmlGetFloat(const QString& textXml,const QString& tag)
{
    return textXml.mid(GetStart(textXml, tag), GetLen(textXml, tag)).toFloat();
}

int utility::XmlGetInt(const QString& textXml,const QString& tag)
{
    return textXml.mid(GetStart(textXml, tag), GetLen(textXml, tag)).toInt();
}

QVector<float> utility::XmlGetVector(const QString& xml,const QString& tag)
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

int utility::GetStart(const QString &textXml, const QString &tagXml)
{
    int istart;

    istart = textXml.indexOf("<"+tagXml+">") +tagXml.length()+2;

    return istart;
}

int utility::GetLen(const QString &textXml, const QString &tagXml)
{
    int istart, iend;
    int indexStart, lengStr;


    istart = textXml.indexOf("<"+tagXml+">");
    iend = textXml.indexOf("</"+tagXml+">");
    indexStart = istart+tagXml.length()+2;
    lengStr = iend - indexStart;

    return lengStr;
}



void Log_text(QString text1,QTextStream text2, QString path)
{
    QFile file_log(path);    //linux

    if(file_log.open(QIODevice::WriteOnly | QIODevice::Text)) {

        // issue #5
        // only possible to write "Sting like this"
        // not as QStream

        file_log.write("text blablabla"); // this works
        //file_log.write(text1);            // this doesn´t


        // writing a Stream of Text
        // Again just works with "text like that"
        QTextStream out(&file_log);

        out << "text balablalbla"; //this works
        // out << text2;            // this doesn´t
    }
    file_log.close();
}
