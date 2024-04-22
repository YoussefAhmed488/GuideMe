#include "Graph.h"
#include <vector>
#include<map>
#include<iostream>
#define MOD 100007
#include <utility>
#include <unordered_set>
#include <unordered_map>
Graph::Graph() {
    setData();
}

void Graph::setData() {
    edge edg[10000];

    edg[0].buscost = 250;
    edg[0].metrocost = 450;
    edg[0].type1 = 't';
    edg[0].type2 = 'b';

    edg[1].buscost = 20;
    edg[1].metrocost = 15;
    edg[1].type1 = 'm';
    edg[1].type2 = 'b';

    edg[2].buscost = 200;
    edg[2].metrocost = 315;
    edg[2].type1 = 'm';
    edg[2].type2 = 'b';

    edg[3].buscost = 500;
    edg[3].metrocost = 345;
    edg[3].type1 = 'b';
    edg[3].type2 = 'm';

    edg[4].buscost = 30;
    edg[4].metrocost = 6;
    edg[4].type1 = 'M';
    edg[4].type2 = 'b';

    edg[5].buscost = 60;
    edg[5].metrocost = 600;
    edg[5].type1 = 'b';
    edg[5].type2 = 'm';

    mp[1] = "Asyut", mp[2] = "Cairo", mp[3] = "BeniSuef", mp[4] = "Dahab", mp[5] = "Giza";
    mp['m'] = "microbus", mp['b'] = "bus", mp['M'] = "metro", mp['t'] = "train";

    graph[1] = { { 2, edg[0] } };
    graph[2] = { {1, edg[0]}, {3, edg[1]}, {5, edg[4]} };
    graph[3] = { {2, edg[1]}, {4, edg[2]} };
    graph[4] = { {3, edg[2]}, {5, edg[3]} };
    graph[5] = { {4, edg[3]}, {2, edg[4]} };
}



void Graph::dfs(int node, int dest, unordered_map<int, vector<pair<int, edge>>>& graph, vector<pair<int, edge>>& path, vector<vector<pair<int, edge>>>& paths, unordered_set<int>& visited) {
    path.push_back({ node ,nodee });
    if (node == dest) {
        //  cout << "=";
        paths.push_back(path);
    }
    else {
        for (auto child : graph[node]) {
            if (visited.find(child.first) == visited.end()) {
                visited.insert(child.first);
                //  cout << "out " << child.first << endl;
                nodee = child.second;
                dfs(child.first, dest, graph, path, paths, visited);
                // cout << "outt" << endl;
                visited.erase(child.first);
            }
        }
    }
    path.pop_back();
}
vector<vector<pair<int, edge>>> Graph::findallpasses(int source, int dest) {
    vector<vector<pair<int, edge>>> paths;
    vector<pair<int, edge>> path;
    unordered_set<int> visited;
    visited.insert(source);
    dfs(source, dest, graph, path, paths, visited);
    return paths;
}
