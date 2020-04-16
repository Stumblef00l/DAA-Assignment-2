#include "Graph.h"

Graph::Graph(int nodes, int edges) : n(nodes), m(edges)
{
    vector<int> v;
    capacities.push_back(v);
    visited.resize(n + 1, false);
    vector<int> zeroCap(n + 1, 0);
    for (int i = 1; i <= n + 1; i++)
    {
        adj.push_back(v);
        capacities.push_back(zeroCap);
    }

    cout << "Enter " << m << " edges:\n";
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        capacities[u][v] = w;
    }
}
Graph::Graph() {}