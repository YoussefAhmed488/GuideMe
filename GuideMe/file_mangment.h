#ifndef FILE_MANGMENT_H
#define FILE_MANGMENT_H

#include<qmainwindow.h>
#include<QFile>
#include<QDir>
#include<QDebug>
#include<QTextStream>

using namespace std;

class File_Mangment
{
public:
    File_Mangment();
    void write();
    static QString read();
};

#endif // FILE_MANGMENT_H
