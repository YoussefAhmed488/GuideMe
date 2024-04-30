#include "mainwindow.h"
#include "file_mangment.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    File_Mangment().read();
    for(int i=0;i<File_Mangment().data_file.size();i++)
    {
        cout<<File_Mangment().data_file[i]<<'\n';
    }
    return a.exec();
}
