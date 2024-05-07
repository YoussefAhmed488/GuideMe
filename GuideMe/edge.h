#ifndef EDGE_H
#define EDGE_H

#include <bits/stdc++.h>
using namespace std;

class edge
{
public:
    edge();
    edge(vector<pair<string ,int>>dataa);
    vector<pair<string,int>>dirction;
    void add_Edge(string start,string end,string type,int price);
    void delete_Edge(string start,string end,string type,int price);
    void Update_Edge(string start,string end,string type,int price);
};

#endif // EDGE_H
