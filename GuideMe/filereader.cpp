#include "filereader.h"
#include <fstream>
#include <string>
#include <iostream>
#include <QApplication>
//#include<bits\stdc++.h>
#include<QFile>
#include<QTextStream>
#include "edge.h"
#include "graph.h"
#include<QMessageBox>
#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <sstream>
#include<string>
using namespace std;

FileReader::FileReader()
{

}

void FileReader::readFile()
{

    ifstream file("F:/FCIS 2026/DS Project/GuideMe/build-GuideMe-Desktop_Qt_6_7_0_MSVC2019_64bit-Debug/TransportationMap.txt");
    string content;

    if (file.is_open()) { // Check if file is open
        string line;
        getline(file, line);
        int num;
        num = stoi(line);
       // cout << num << endl;

        while (getline(file, line)) { // Read the file line by line

            istringstream str(line);
            string city1, city2, trans_info, ignore;
            //cout << line << endl; // Print the current line

            //Extract cities and split
            getline(str, city1, '-');
            getline(str, ignore, ' ');
            getline(str, city2, ' ');

            // Removing leading and trailing spaces
            city1.erase(city1.find_last_not_of(" ") + 1);
            city2.erase(0, city2.find_first_not_of(" "));
            //cout << "<"<< ignore << ">";
           // cout << city1 << " - " << city2 << " ";


            while (str >> trans_info) {
                string s = trans_info;
                float cost;
                str >> cost;
               // cout << trans_info << " " << cost << " ";
                g->addEdge(city1, city2, trans_info,cost);

            }

           // cout << endl;

        }
    }
    else {
        std::cerr << "Unable to open file"; // Error if unable to open file
        return;
    }
    file.close(); // Close the file
     // std::cout << "Content of the file:\n" << content << std::endl;

     // string s = "Cairo", d = "Dahab";
     // cout << "Following are all different paths from " << s
     //      << " to " << d << endl;

     // m.graph.getAllPaths(s, d,1);
}
