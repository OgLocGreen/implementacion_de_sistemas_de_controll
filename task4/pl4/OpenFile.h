#ifndef OPENFILE_H
#define OPENFILE_H

#include <QString>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QTextStream>
#include <QMessageBox>

class OpenFile
{
public:
    OpenFile();

    void set_path(QString path);
    QString get_path();
    void get_data(QString *data);
    QString read_data(QString path);
private:
    QString file_path;
    QString data;

};

#endif // OPENFILE_H
