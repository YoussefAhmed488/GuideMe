#include <iostream>
#include<queue>
#include <fstream>
#include <unordered_map>
#include <map>
#include<set>
#include <vector>
#include "edge.h"
#include "graph.h"
#include"mainwindow.h"
#include <sstream>

using namespace std;

Graph* Graph::instance = nullptr;

// Get the singleton instance of the Graph.
Graph* Graph::getInstance() {
    if (!instance) {
        instance = new Graph();
    }
    return instance;
}

// Private constructor definition (empty, since private and no other logic is needed)
Graph::Graph() {
    // Initialization code here if necessary.
    // For instance, if there were any default values or setup needed for the adjacency list or costs.
}

void Graph::addEdge(string u, string v,string t,int cost)
{
    Edge e1(u, v, t, cost);
    Edge e2(v, u, t, cost);
    adj[u].push_back(e1); // Add u to v’s list.
    adj[v].push_back(e2); // Add v to u’s list.

}

//Prints all paths from 's' to 'd'

void Graph::getAllPaths(string s, string d,int b)
{

    //map to initialize all nodes as not visited
    map<string,bool>visited;
    //Create vector to store paths
    vector<Edge>paths;
    Edge path;
    int path_index = 0;

    if(b==1){

        // Call the iterative function to print all paths

        findAllPathsBFS(s, d);

    }
    if(b==2){

        //Call the recursive function to print all paths
        findAllPathsDFS( s, d, visited, paths,path, path_index);
    }
    if(b==3){

        dijkstra(d,s);

    }

}
void Graph::findAllPathsBFS(string source, string dest) {

    //queue to store all paths
    queue<vector<string>> q;
    //to store the path as nodes in the first
    vector<string> path;

    //followed by q, qEdge does store all pathes as edges
    queue<vector<Edge>> qEdge;
    //to store the path as edge
    vector<Edge> pathEdge;

    path.push_back(source);
    q.push(path);
    while (q.size())
    {
        if (!qEdge.empty())
        {
            pathEdge = qEdge.front();
            qEdge.pop();
        }
        path = q.front();
        q.pop();
        string last = path.back();

        if (last == dest)
        {
            string s;
            int sz = (int)path.size();//(int) fix warning
            float sumCost = 0;
            for (auto e : pathEdge)
            {
                s += e.startNode + " (" + e.vehicle+ ") ";

                sumCost += e.cost;
            }

            s+=pathEdge.back().endNode +" " ;

            road[sumCost] = pathEdge;
        }

        for (auto child : adj[last])
        {
            bool b = find(path.begin(), path.end(), child.endNode) == path.end();
            if (b)
            {
                vector<string>newpath(path);
                vector<Edge>newpathEdge(pathEdge);

                newpath.push_back(child.endNode);
                newpathEdge.push_back(child);

                q.push(newpath);
                qEdge.push(newpathEdge);
            }
        }
    }

}

//A recursive function to print all paths from 'u' to 'd'.
void Graph::findAllPathsDFS(string u, string d, map<string, bool>visited ,
                            vector<Edge>paths,Edge path, int& path_index)
{
    //Mark the current node as visited
    visited[u] = true;
    string s;

    if (path_index > 0) { paths.push_back(path); }
    path_index++;

    //If current vertex is same as destination
    if (u == d) {
        float sum_cost = 0;
        for (int i = 0; i < path_index - 1; i++) {
            s= paths[i].startNode + " (" + paths[i].vehicle + ") ";
            sum_cost += paths[i].cost;
        }

        s+=paths.back().endNode +" " ;

        road[sum_cost] = paths;
    }
    else //if current vertex is not destination
    {
        //Recurse for all the vertices adjacent to current vertex
        for (auto child : adj[u]) {
            if (!visited[child.endNode])
            {
                findAllPathsDFS( child.endNode, d, visited, paths,child, path_index);
            }
        }
    }


    //mark current node as unvisited
    path_index--;
    visited[u] = false;
}

void Graph::dijkstra(string start,string end)
{
    bool found = 0;
    string node;
    priority_queue<pair<float,string>>pq;
    unordered_map<string,pair<string,pair<string,int>>>parent;
    //Max The Distance
    for(auto i : adj)
        cost[i.first] = 1e9;

    pq.push({0,start});
    cost[start] = 0;

    while(!pq.empty())
    {
        //Getting The Best Choice To Try (top)
        node = pq.top().second;
        double cur_cost = -pq.top().first;
        pq.pop();

        //If Found Better path Continue
        if(cur_cost > cost[node])
            continue;

        //Loop on The Edge
        for(auto child : adj[node])
        {
            //If Found A better Path Save it And push THe dest Node To The pq
            if(cur_cost+child.cost < cost[child.endNode])
            {
                //Save The Parent For The Node And The Type of Transportaion
                parent[child.endNode] = {child.startNode,{child.vehicle,child.cost}};
                //Update The Old Cost By The Better One
                cost[child.endNode] = cur_cost + child.cost;
                pq.push({-cost[child.endNode],child.endNode});
                if(end == child.endNode)
                    found = 1;

            }
        }
    }
    int sum=0;
    string s;
    if(!found)
        s = "NOT Found \n";
    while (start != end and found) {
        sum+=parent[end].second.second;
        s += "From " + end +" To "+ parent[end].first+" by "+parent[end].second.first +" "+ std::to_string(parent[end].second.second) + " ";
        end = parent[end].first;
    }
    dijkestraCost = sum;

    dijkestraRoad = s;
}
void Graph::updateEdgeCost(string start, string end, string type, int newCost)
{
    deleteEdge(start,end,type);
    addEdge(start,end,type,newCost);
}
void Graph::deleteEdge(string start, string end, string type)
{
    //for(auto i : adj[start])
    for(auto i = adj[start].begin(); i != adj[start].end(); i++)
    {
        if(i->endNode == end && i->vehicle == type)
        {
            adj[start].erase(i);
            break;
        }
    }
    //for(auto i : adj[end])
    for(auto i = adj[end].begin(); i != adj[end].end(); i++)
    {
        if(i->endNode == start && i->vehicle == type)
        {
            adj[end].erase(i);
            break;

        }

    }









}

bool Graph::isComplete()
{
    int n = adj.size();
    // for (auto i : adj)
    //     cout << "node: " << i.first << " children: " << i.second.size() << endl;
    // for(auto i : adj["a"])
    // {
    //     cout << "child: " << i.endNode << endl;
    // }
    for (auto i : adj)
    {
        //cout << "size: " <<  i.second.size() << endl;
        set<string> s;
        for (auto j : i.second)
            s.insert(j.endNode);

        if(s.size() != n - 1)
            return false;
    }
    return true;
}

bool Graph::isConnected()
{
    map<string, bool> vis;
    isConnectedDFS(vis, (*adj.begin()).first);
    if(vis.size() == adj.size())
        return true;
    else
        return false;

}

void Graph::isConnectedDFS(map<string, bool> &vis, string node)
{
    vis[node] = true;
    for(auto child : adj[node])
        if(!vis[child.endNode])
            isConnectedDFS(vis, child.endNode);
}
void Graph::returnToFile()
{

    for(auto i:adj)
    {

        for(auto it : i.second)
        {
            vector<string>v(2);
            v[0]=it.startNode;v[1]=it.endNode;
            sort(v.begin(),v.end());
            to_save[{v[0],v[1]}].insert({it.vehicle,it.cost});
        }
    }

}

void Graph::printGraph()
{
    for(auto i : adj)
    {
        cout << i.first << ": ";
        for (auto j : i.second)
            cout << j.endNode << " ";
        cout << endl;
    }
}
