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

    QFile stylesheetFile("D:/FCIS/Sophomore/Second Semester/Data Structure/New folder/GuideMe/Darkeum.qss");
    stylesheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(stylesheetFile.readAll());
    a.setStyleSheet(styleSheet);

    FileReader f;
    f.readFile();
    MainWindow w;


    w.setGeometry(270, 70, 1065, 250);
    w.show();

    return a.exec();
}










