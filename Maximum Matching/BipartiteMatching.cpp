#include "BipartiteMatching.h"

BipartiteMatching::BipartiteMatching() {}

long long BipartiteMatching::getMaxMatching()
{
    return maxMatchings;
}

BipartiteMatching::BipartiteMatching(int vertices, int edges, vector<vector<int>> &adj, set<int> leftSide)
{
    int source = vertices + 1;
    int sink = vertices + 2;
    vector<int> sourceAdj, sinkAdj;
    for (int i = 1; i <= vertices; i++)
    {
        if (leftSide.find(i) == leftSide.end())
            adj[i].push_back(sink);
        else
            sourceAdj.push_back(i);
        edges++;
    }
    vertices += 2;
    adj.push_back(sourceAdj);
    adj.push_back(sinkAdj);
    vector<unordered_map<int, int>> capacities;
    unordered_map<int, int> newCap;
    for (int i = 1; i <= vertices + 1; i++)
        capacities.push_back(newCap);
    for (int i = 1; i <= vertices; i++)
    {
        for (auto it : adj[i])
            capacities[i][it] = 1;
    }
    graph = Graph(vertices, edges, adj, capacities);
    maxFlowObject = FordFulkerson(graph, source, sink);
    maxMatchings = maxFlowObject.getMaxFlow();
}
