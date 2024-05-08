#include "graph.h"
#include"edge.h"
#include <vector>
#include<map>
#include<iostream>
#define MOD 100007
#include <utility>
#include <unordered_set>
#include <unordered_map>
Graph::Graph()
{

}
void Graph::setData(string sor,string des,vector<pair<string,int>>dataa) {
    edge ed(dataa);
    graph[sor].push_back({des,ed});
    graph[des].push_back({sor,ed});

}



void Graph::dfs(string node, string dest, unordered_map<string, vector<pair<string, edge>>>& graph, vector<pair<string, edge>>& path, vector<vector<pair<string, edge>>>& paths, unordered_set<string>& visited) {

    path.push_back({ node ,data }); //temp vector

    if (node == dest) //once i found path i will push in paths vector
    {
        paths.push_back(path);
    } 
    else {
        for (auto child : graph[node]) {
            if (visited.find(child.first) == visited.end() )// if child not visited it will return visited.end()
            {
                //iam here that means the kid that iam looking for is not visited
                visited.insert(child.first);
                data = child.second; //now i save the node and the edge to return to vector path to push
                dfs(child.first, dest, graph, path, paths, visited);
                visited.erase(child.first);
            }
        }
    }
    // for(auto i:path)
    // cout<<i.first<<" <<inn "<<endl;

    path.pop_back(); // i reach here if (node==dest) or (all adjacent nodes have been explored )

    // for(auto i:path)
    //     cout<<i.first<<" <<out "<<endl;
}
vector<vector<pair<string, edge>>> Graph::find_all_passes(string source, string dest) {
    vector<vector<pair<string, edge>>> paths;
    vector<pair<string, edge>> path;
    unordered_set<string> visited;
    visited.insert(source);
    dfs(source, dest, graph, path, paths, visited);
    return paths;
}
