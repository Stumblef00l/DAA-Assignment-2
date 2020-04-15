#include "Graph.h"

Graph::Graph(int nodes, int edges) : n(nodes), m(edges)
{
    map<int, int> v;
    adj.push_back(v);
    visited.resize(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        map<int, int> newList;
        adj.push_back(newList);
    }
    cout << "Enter " << m << " edges:\n";
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
}

Graph::Graph()
{
    n = 0;
    m = 0;
}