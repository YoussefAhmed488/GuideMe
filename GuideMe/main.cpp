#include "file_mangment.h"
#include "filereader.h"
#include "mainwindow.h"
#include<iostream>
#include <fstream>
#include <QApplication>
//#include<bits\stdc++.h>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include <QCoreApplication>
#include <QString>
#include <QDebug>
using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // File_Mangment file;
    // file.write();
    // file.read();
    // w.show();
    // for (int var = 0; var < File_Mangment().data_file.size(); ++var) {
    //     cout << File_Mangment().data_file[var]<<'\n';
    // }
    w.show();
    FileReader f;
    f.readFile();
    return a.exec();
}










