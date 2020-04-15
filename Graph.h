#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:
    /** 
     * Adjacency list
     */
    vector<vector<int>> adj;

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
     * Constructor for the class
     * @param nodes The number of nodes.
     * @param edges The number of edges.
     */
    Graph(int nodes, int edges);
};

#endif