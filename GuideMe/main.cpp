#include "mainwindow.h"
#include "file_mangment.h"
#include <QApplication>
#include <iostream>
#include "edit_edge.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     QIcon appIcon("D:/visual studio projects/Qt_practice/Qt_practice/edit_icon.ico");
    Edit_Edge w;
     w.setWindowTitle("Edit Edges");
    w.setWindowIcon(appIcon);
    w.show();
    File_Mangment().read();
    for(int i=0;i<File_Mangment().data_file.size();i++)
    {
        cout<<File_Mangment().data_file[i]<<'\n';
    }
    return a.exec();
}
