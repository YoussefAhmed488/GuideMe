#ifndef FILEREADER_H
#define FILEREADER_H
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
    Graph* graph = Graph::getInstance();
    FileReader();
    void readFile();
    void savefile();
};

#endif // FILEREADER_H
