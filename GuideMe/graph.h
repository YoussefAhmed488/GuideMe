#ifndef GRAPH_H
#define GRAPH_H
#pragma once
#include <iostream>
#include<queue>
#include <fstream>
#include <unordered_map>
#include <map>
#include<set>
#include <vector>
#include "edge.h"

//undirected graph using
//hash table as adjacency list representation
class Graph {

private:

    static Graph* instance; // Pointer to the single instance of the class

    // Private constructor to prevent instantiation outside the class
    Graph();

public:

    string dijkestraRoad;
    int dijkestraCost;
    unordered_map<string, vector<Edge>> adj;// hashtable as every cell contains vector of edges
        //adjacency lists
    map<int,vector<Edge>> road;
    static Graph* getInstance();
    //Cost for Dijkstra
    unordered_map<string,float>cost;
    //A recursive function used by getAllPaths

    map<pair<string,string>,set<pair<string,int>>>to_save;

    void addEdge(string u, string v, string t, int cost);
    // this fun choose which algorithms to use
    void findAllPathsDFS( string, string, map<string, bool>visited, vector<Edge>, Edge, int&);
    void getAllPaths(string s, string d,int b);
    void findAllPathsBFS(string source, string dest);
    void dijkstra(string source,string dest);
    void updateEdgeCost(string start, string end, string type, int newCost);
    void deleteEdge(string start, string end, string type);
    bool isComplete();
    bool isConnected();
    void isConnectedDFS(map<string, bool> &vis, string node);
    void returnToFile();
    void printGraph();

};
#endif // GRAPH_H
