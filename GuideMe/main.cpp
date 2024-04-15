#include "file_mangment.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    File_Mangment file;
    file.write();
    file.read();
    w.show();
    return a.exec();
}
