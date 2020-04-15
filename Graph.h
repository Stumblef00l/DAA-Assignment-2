#ifndef GRAPH
#define GRAPH

#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    /** 
     * Adjacency list
     */
    vector<map<int, int>> adj;

    /** 
     * Number of nodes
     */
    int n;

    /**
     * Number of edges
     */
    int m;

    /**
     * Visited array
     */
    vector<bool> visited;

    /**
     * Parametrized Constructor for the class
     * @param nodes The number of nodes.
     * @param edges The number of edges.
     */
    Graph(int nodes, int edges);

    /**
     * Default constructor for the class.
     */
    Graph();
};

#endif