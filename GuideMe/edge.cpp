#include "edge.h"

Edge::Edge()
{
}

Edge::Edge(string n1, string n2)
{
    startNode = n1;
    endNode = n2;
}

Edge::Edge(string n1, string n2, string v, float c)
{
    startNode = n1;
    endNode = n2;
    vehicle = v;
    cost = c;
}

