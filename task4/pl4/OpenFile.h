#ifndef OPENFILE_H
#define OPENFILE_H

#include <QString>
#include <QFileDialog>

class OpenFile
{
public:
    OpenFile();

    void set_path(QString path);
    QString get_path();
private:
    QString file_path;
    QString data;

};

#endif // OPENFILE_H
