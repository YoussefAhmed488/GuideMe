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

    w.setGeometry(270, 70, 1065, 855);
    w.show();
    FileReader f;
    f.readFile();
    Graph g;
    g.addEdge("a", "b", "", 0);
    g.addEdge("a", "c", "", 0);
    g.addEdge("b", "c", "", 0);
    g.addEdge("b", "a", "", 0);
    g.addEdge("c", "a", "", 0);
    g.addEdge("c", "b", "", 0);
    cout << "connected ?: " << g.isConnected() << endl;
    cout << "complete ?: " << g.isComplete() << endl;
    return a.exec();
}










