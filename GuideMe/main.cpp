
#include "Graph.h"

#include<iostream>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    Graph graph;
    int source = 1;
    int dest = 5;

    cout << "enter source   1 or 2 or 3 or...." << endl;
    cout << "enter 1: for  Asyut " << endl;
    cout << "enter 2: for  Cairo " << endl;
    cout << "enter 3: for  BeniSuef " << endl;
    cout << "enter 4: for  Dahab " << endl;
    cout << "enter 5: for  Giza " << endl;



    vector<vector<pair<int, edge>>> paths = graph.findallpasses(source, dest);

    cout << "all paths from node " << source << " to node " << dest << ":" << endl;
    for (const auto& path : paths) {
        for (auto node : path) {
            if (node.second.metrocost>0)
            {
                cout << " TAKE  " << graph.mp[node.second.type1] << "  With cost  " << node.second.buscost << " OR TAKE  " << graph.mp[node.second.type2] << "  With cost  " << node.second.metrocost << "  To Go To " << graph.mp[node.first];
                cout << endl << " AND:  " << endl;
            }
        }
        cout << endl;
        cout << "Second way : " << endl;
        cout << endl;
    }

    cout<<"doe"<<endl;


    // gggg
}
