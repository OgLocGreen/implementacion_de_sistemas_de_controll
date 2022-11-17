#include "OpenFile.h"

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
