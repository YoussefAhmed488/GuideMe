#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include<unordered_set>
#include <map>
#include <string>

using namespace std;

struct edge {
    char type1;
    char type2;
    //vector<pair<string,int>>
    int buscost;
    int metrocost;
};

class Graph {
public:
    edge nodee;
    unordered_map<int, vector<pair<int, edge>>> graph;
    map<int, string> mp;
    Graph();
    void setData();
    void dfs(int node, int dest, unordered_map<int, vector<pair<int, edge>>>& graph, vector<pair<int, edge>>& path, vector<vector<pair<int, edge>>>& paths, unordered_set<int>& visited);
    vector<vector<pair<int, edge>>> find_all_passes(int source, int dest);
};

#endif // GRAPH_H
