#include "file_mangment.h"
#include"graph.h"
#include "filereader.h"
#include "mainwindow.h"
#include"edit_edge.h"
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
#include <iostream>
#include "edit_edge.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    FileReader f;
    f.readFile();


    string source="Cairo",dest="BeniSuef";
    vector<vector<pair<string, edge>>> paths = f.graph.find_all_passes(source, dest);
    cout << "all paths from node " << source << " to node " << dest << ":" << endl;
    for (const auto& path : paths) {
        for (auto node : path) {

            cout<<node.first<<" \n";
            for(auto &path :node.second.dirction)
            {
                cout<<path.first<<" "<<path.second<<"\n";
            }

        }
        cout << endl;
        cout << "Second way : " << endl;
    }
    return a.exec();

}
