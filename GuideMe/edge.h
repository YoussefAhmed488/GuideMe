#ifndef EDGE_H
#define EDGE_H

#pragma once
#include<iostream>
#include<vector>
#include <string>
using namespace std;
class Edge
{
public:
    string startNode,endNode,vehicle;
    float cost;
    Edge();
    Edge(string n1, string n2);
    Edge(string n1, string n2, string v, int c);


};



#endif // EDGE_H
