#include "OpenFile.h"

#include <QString>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QTextStream>
#include <QMessageBox>
#include <QXmlStreamReader>
#include <QFile>

OpenFile::OpenFile()
{

}

void OpenFile::set_path(QString path)
{
    file_path = path;
}

QString OpenFile::get_path()
{
    return file_path;
}

void OpenFile::get_data(QString *data)
{
    /*
    QFile file("/home/hamad/lesson11.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        data = model->appendRow(fields);
    }

    file.close();
    */

}

QString OpenFile::read_data(QString path)
{
    path = "../other/data.txt";

    /*
    QXmlStreamReader xmlReader;
    QXmlInputSource *source = new QXmlInputSource(path);

    QString previousElement;
    while(!xmlReader.atEnd())
    {
        xmlReader.readNext();

        if (!xmlReader.isStartElement()) {
            continue;
        }

        QString text = xmlReader.name().toString();

        if ( (text == QStringLiteral("motor")) ||
             (text == QStringLiteral("value2")) ||
             (text == QStringLiteral("number1")) ||
             (text == QStringLiteral("number2")) )
        {
            ui->textEdit->append(xmlReader.readElementText());
        }

        data = text;
    }

    if (xmlReader.hasError()) {
        return (QStringLiteral("Error parsing XML: ") + xmlReader.errorString());
}
*/

        QFile f(path);
        if (!f.open(QFile::ReadOnly | QFile::Text))
        {
            return "false";
        }
        QTextStream in(&f);

        return "true";
}
