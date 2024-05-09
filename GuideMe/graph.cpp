#include <iostream>
#include<bits\stdc++.h>
#include <fstream>
#include <unordered_map>
#include <map>
#include<set>
#include <vector>
#include "edge.h"
#include "graph.h"

using namespace std;

Graph::Graph()
{

}

void Graph::addEdge(string u, string v,string t,float cost)
{
    Edge e1(u, v, t, cost);
    Edge e2(v, u, t, cost);
    adj[u].push_back(e1); // Add u to v’s list.
    adj[v].push_back(e2); // Add v to u’s list.

}
bool Graph::findEdge(vector<Edge> edges, string nodeName, string vehicleName)
{
    for (auto e : edges)
    {
        if (e.endNode == nodeName && e.vehicle == vehicleName)
        {
            return 1;
        }
    }
    return 0;
}

//Prints all paths from 's' to 'd'
void Graph::getAllPaths(string s, string d)
{
    //map to initialize all nodes as not visited
    map<string,bool>visited;

    //Create vector to store paths
    vector<Edge>paths;
    Edge path;
    int path_index = 0;

    // Call the iterative function to print all paths
    findAllPathsBFS(s, d);//
    cout<< endl;
    //Call the recursive function to print all paths
    findAllPathsDFS("", s, d, visited, paths,path, path_index);
    //dijkstra("Giza","BeniSuef");
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
            int sz = (int)path.size();//(int) fix warning
            float sumCost = 0;
            for (auto e : pathEdge)
            {
                cout << e.startNode <<" ("<<e.vehicle<<") ";
                sumCost += e.cost;
            }
            cout << pathEdge.back().endNode<<" ";
            cout << sumCost;
            cout << endl;
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
void Graph::findAllPathsDFS(string prevNode,string u, string d, map<string, bool>visited ,
                            vector<Edge>paths,Edge path, int& path_index)
{
    //Mark the current node as visited
    visited[u] = true;
    if (path_index > 0) { paths.push_back(path); }
    path_index++;

    //If current vertex is same as destination
    if (u == d) {
        float sum_cost = 0;
        for (int i = 0; i < path_index - 1; i++) {
            cout << paths[i].startNode << " (" << paths[i].vehicle << ") ";
            sum_cost += paths[i].cost;
        }
        cout << paths.back().endNode<<" ";
        cout << sum_cost;
        cout << endl;
    }
    else //if current vertex is not destination
    {
        //Recurse for all the vertices adjacent to current vertex
        for (auto child : adj[u]) {
            if (!visited[child.endNode])
            {
                findAllPathsDFS(u, child.endNode, d, visited, paths,child, path_index);
            }
        }
    }

    //mark current node as unvisited
    path_index--;
    visited[u] = false;
}

void Graph::dijkstra(string start,string end)
{
    string node;
    priority_queue<pair<float,string>>pq;
    unordered_map<string,pair<string,string>>parent;
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
                parent[child.endNode] = {child.startNode,child.vehicle};
                //Update The Old Cost By The Better One
                cost[child.endNode] = cur_cost + child.cost;
                pq.push({-cost[child.endNode],child.endNode});
            }
        }
    }
    while (start != end) {
        cout <<"From "<< end <<" To "<< parent[end].first<<" by "<<parent[end].second<<" ";
        end = parent[end].first;
    }
    cout << end;
}
