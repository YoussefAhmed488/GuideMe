#ifndef GRAPH_H
#define GRAPH_H
#pragma once
#include <iostream>
//#include<bits\stdc++.h>
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

    // Private Copy Constructor and Assignment Operator
    Graph(const Graph&) = delete;
    Graph& operator=(const Graph&) = delete;
public:
    unordered_map<string, vector<Edge>> adj;// hashtable as every cell contains vector of edges
        //adjacency lists

    vector<pair<int,string>> road;

    static Graph* getInstance();

    //Cost for Dijkstra
    unordered_map<string,float>cost;
    //A recursive function used by getAllPaths


    void addEdge(string u, string v, string t, float cost);
    void deleteEdge(string start, string end, string type);
    void updateEdgeCost(string start, string end, string type, float newCost);
    void printGraph();
    // this fun choose which algorithms to use
    void findAllPathsDFS(string, string, string, map<string, bool>visited, vector<Edge>, Edge, int&);
    void getAllPaths(string s, string d,int b);
    void findAllPathsBFS(string source, string dest);
    bool findEdge(vector<Edge>, string nodeName, string vehicleName);
    void dijkstra(string source,string dest);
};
#endif // GRAPH_H
