#include "Utility.h"
using namespace std;

Utility::Utility()
{

}

void Utility::set_xml_path(QString path)
{
    xml_file_path = path;
}


QString Utility::XmlCreateTag(const QString &text, bool is_start_tag)
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

QString Utility::GetXmlStr(const QString &textXml, const QString &tagXml)
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




float Utility::GetXmlFloat(const QString& textXml,const QString& tag)
{
    return textXml.mid(GetStart(textXml, tag), GetLen(textXml, tag)).toFloat();
}

int Utility::GetXmlInt(const QString& textXml,const QString& tag)
{
    return textXml.mid(GetStart(textXml, tag), GetLen(textXml, tag)).toInt();
}

QVector<float> Utility::GetXmlVector(const QString& xml,const QString& tag)
{
    QVector<float> ret;
    QString constens = GetXmlStr(xml, tag).trimmed();

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

QString Utility::GetXmlTag(const QString &text)
{
    int end_tag = text.indexOf(">");
    return text.mid(2,end_tag);
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


QString Utility::ReadXml()
{
    QString xml_data;
    QFile xml_file(xml_file_path);

    if (xml_file.open(QIODevice::ReadOnly)){
        QTextStream leer(&xml_file);
        xml_data.append(leer.readAll());
        xml_file.close();
    }
    return xml_data;
}


QString Utility::ReadXml(QString xml_path)
{
    QString xml_data;
    QFile xml_file(xml_path);

    if (xml_file.open(QIODevice::ReadOnly)){
        QTextStream leer(&xml_file);
        xml_data.append(leer.readAll());
        xml_file.close();
    }
    return xml_data;
}


int Utility::WriteXml(QString xml_msg)
{
    QFile xml_file(xml_file_path);
    try
    {
        if (xml_file.open(QIODevice::WriteOnly)){
            QTextStream escribir(&xml_msg);
            escribir<<xml_msg;
            xml_file.close();
            return 0;
        }
        else
        {
            throw -1;
        }

    }
    catch (int error)
    {
        return error;
    }
}

int Utility::WriteXml(QString xml_msg, QString xml_path)
{
    QFile xml_file(xml_path);
    try
    {
        if (xml_file.open(QIODevice::WriteOnly)){
            QTextStream escribir(&xml_msg);
            escribir<<xml_msg;
            xml_file.close();
            return 0;
        }
        else
        {
            throw -1;
        }

    }
    catch (int error)
    {
        return error;
    }
}



int Utility::AppenedToXml(QString xml_msg)
{
    QString lastlog;

    QFile log(xml_file_path);


    try
    {
        if (log.open(QIODevice::ReadOnly)){
            QTextStream leer(&log);
            lastlog.append(leer.readAll());
            log.close();
            if (log.open(QIODevice::WriteOnly)){
                QTextStream escribir(&log);
                escribir<<lastlog;
                escribir<<xml_msg;
                log.close();
            }
            else
            {
                throw -2;
            }
            return 0;
        }
        else
        {
            throw -1;
        }

    }
    catch (int error)
    {
        return error;
    }

}


int Utility::AppenedToXml(QString xml_msg,QString xml_path)
{
    QString lastxml;

    QFile log(xml_path);
    try
    {
        if (log.open(QIODevice::ReadOnly)){
            QTextStream leer(&log);
            lastxml.append(leer.readAll());
            log.close();
            if (log.open(QIODevice::WriteOnly)){
                QTextStream escribir(&log);
                escribir<<lastxml;
                escribir<<xml_msg;
                log.close();
            }
            else
            {
                throw -2;
            }
            return 0;
        }
        else
        {
            throw -1;
        }

    }
    catch(int error)
    {
        return error;
    }

}







void Utility::Log_text_string(QString text1, QString path)
{
    QFile file_log(path);    //linux

    if(file_log.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file_log.write(text1.toLatin1() + "\n");
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

