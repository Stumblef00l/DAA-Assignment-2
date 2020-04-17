#ifndef GRAPH
#define GRAPH

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Graph
{
public:
    /** 
     * Adjacency list
     */
    vector<vector<int>> adj;

    /**
     * Capacities
     */
    vector<unordered_map<int, int>> capacities;
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
    Graph(int nodes, int edges, vector<vector<int>> &adjList, vector<unordered_map<int, int>> &capList);

    /**
     * Default constructor for the class.
     */
    Graph();
};

#endif