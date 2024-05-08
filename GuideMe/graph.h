#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include<unordered_set>
#include <map>
#include"edge.h"
#include <string>

using namespace std;



class Graph {
public:
    Graph();
    edge data;
    unordered_map<string, vector<pair<string, edge>>> graph;
    map<int, string> mp;
    void setData(string sor,string des,vector<pair<string,int>>data);
    void dfs(string node, string dest, unordered_map<string , vector<pair<string, edge>>>& graph, vector<pair<string, edge>>& path, vector<vector<pair<string, edge>>>& paths, unordered_set<string>& visited);
    vector<vector<pair<string, edge>>> find_all_passes(string source, string dest);
};

#endif // GRAPH_H
