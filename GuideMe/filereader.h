#ifndef FILEREADER_H
#define FILEREADER_H
#include"mainwindow.h"
#include <string>
#include <QApplication>
//#include<bits\stdc++.h>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include"graph.h"

using namespace std;

class FileReader
{


public:
    MainWindow m;
    FileReader();
    void readFile();
};

#endif // FILEREADER_H
