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

    Graph::getInstance()->addEdge("a", "b", "", 0);
    Graph::getInstance()->addEdge("b", "c", "", 0);
    Graph::getInstance()->addEdge("c", "d", "", 0);
    Graph::getInstance()->addEdge("d", "a", "", 0);
    Graph::getInstance()->addEdge("a", "c", "", 0);
    Graph::getInstance()->addEdge("d", "b", "", 0);
    Graph::getInstance()->printGraph();
    Graph::getInstance()->deleteEdge("a", "b", "f");
    Graph::getInstance()->printGraph();
    cout <<'\n';
    return a.exec();
}










