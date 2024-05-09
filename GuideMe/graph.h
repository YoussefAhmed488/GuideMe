#ifndef GRAPH_H
#define GRAPH_H
#pragma once
#include <iostream>
#include<bits\stdc++.h>
#include <fstream>
#include <unordered_map>
#include <map>
#include<set>
#include <vector>
#include "edge.h"

//undirected graph using
//hash table as adjacency list representation
class Graph {

    unordered_map<string, vector<Edge>> adj;// hashtable as every cell contains vector of edges
        //adjacency lists


    //Cost for Dijkstra
    unordered_map<string,float>cost;
    //A recursive function used by getAllPaths

public:
    Graph();
    void addEdge(string u, string v, string t, float cost);
    // this fun choose which algorithms to use
    void findAllPathsDFS(string, string, string, map<string, bool>visited, vector<Edge>, Edge, int&);
    void getAllPaths(string s, string d);
    void findAllPathsBFS(string source, string dest);
    bool findEdge(vector<Edge>, string nodeName, string vehicleName);
    void dijkstra(string source,string dest);
};

#endif // GRAPH_H
