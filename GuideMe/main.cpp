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

    FileReader f;
    f.readFile();
    MainWindow w;


    w.setGeometry(270, 70, 1065, 250);
    w.show();


    cout <<'\n';
    f.savefile();
    return a.exec();
}










