#include "Graph.h"

Graph::Graph(int nodes, int edges) : n(nodes), m(edges)
{
    vector<int> v;
    adj.push_back(v);
    visited.resize(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        vector<int> newList;
        adj.push_back(newList);
    }
    cout << "Enter " << m << " edges:\n";
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}