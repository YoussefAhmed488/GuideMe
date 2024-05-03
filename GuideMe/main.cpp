#include "file_mangment.h"
#include "filereader.h"
#include "mainwindow.h"
#include<iostream>
#include <fstream>
#include <QApplication>
#include<bits\stdc++.h>
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
    /*File_Mangment file;
    file.write();
    file.read();
    w.show();
    for (int var = 0; var < File_Mangment().data_file.size(); ++var) {
        cout << File_Mangment().data_file[var]<<'\n';
    }
    FileReader f;
    f.readFile("input.txt");*/
    QString fEmp = QCoreApplication::applicationDirPath() + "/input.txt";
    QFile file(fEmp); // Create QFile object for the file
    QString content; // QString to store the content
    //qDebug() << fEmp;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) { // Open the file
        QTextStream in(&file); // Create QTextStream to read from the file
        while (!in.atEnd()) { // Read until end of file
            QString line = in.readLine(); // Read one line at a time
            content += line + "\n"; // Append line to content QString
        }
        file.close(); // Close the file
        qDebug() << "Content of the file:" << content; // Output the content
    } else {
        qDebug() << "Unable to open file:" << file.errorString(); // Print error message
        return 1;
    }
    return a.exec();
}










