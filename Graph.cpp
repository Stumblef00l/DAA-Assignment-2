#include "Graph.h"

Graph::Graph(int nodes, int edges, vector<vector<int>> &adjList, vector<unordered_map<int, int>> &capList) : n(nodes), m(edges), adj(adjList), capacities(capList)
{
    visited.resize(n + 1, false);
}
Graph::Graph() {}