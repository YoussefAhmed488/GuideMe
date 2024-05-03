#include "filereader.h"
#include <fstream>
#include <string>
#include <iostream>
#include <QApplication>
//#include<bits\stdc++.h>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include <QCoreApplication>
#include <QString>
#include <QDebug>

using namespace std;

FileReader::FileReader()
{

}

void FileReader::readFile()
{
    ifstream file(QCoreApplication::applicationDirPath().toStdString() + "/input.txt");
    string content;

    if (file.is_open()) { // Check if file is open
        std::string line;
        while (std::getline(file, line)) { // Read the file line by line
            content += line + "\n"; // Append each line to the content string
        }
        file.close(); // Close the file
    } else {
        std::cerr << "Unable to open file"; // Error if unable to open file
        //return 1;
    }

    std::cout << "Content of the file:\n" << content << std::endl;
}




















