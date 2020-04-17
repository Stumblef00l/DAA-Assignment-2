#include "FordFulkerson.h"

FordFulkerson::FordFulkerson() {}

FordFulkerson::FordFulkerson(Graph &inputGraph, int s, int t) : graph(inputGraph), flow(0), source(s), sink(t)
{
    residual.n = graph.n;
    residual.m = 0;
    residual.visited.resize(graph.n + 1, false);
    for (int i = 1; i <= graph.n; i++)
        tcut.insert(i);
    vector<int> v;
    unordered_map<int, int> zeroCap;
    for (int i = 1; i <= residual.n + 1; i++)
    {
        residual.adj.push_back(v);
        residual.capacities.push_back(zeroCap);
    }
    for (int i = 1; i <= graph.n; i++)
    {
        for (auto it : graph.adj[i])
        {
            residual.adj[i].push_back(it);
            residual.adj[it].push_back(i);
            residual.capacities[i][it] += graph.capacities[i][it];
            residual.m += 2;
        }
    }
    FordFulkerson::calculateMaxFlow();
    FordFulkerson::getSCutVertices();
}

void FordFulkerson::displayMinCut()
{
    cout << "s - cut: ";
    for (auto it : scut)
        cout << it << " ";
    cout << "\n";
    cout << "t - cut: ";
    for (auto it : tcut)
        cout << it << " ";
    cout << "\n";
}

long long FordFulkerson::getMaxFlow()
{
    return flow;
}

void FordFulkerson::getSCutVertices()
{
    fill(residual.visited.begin(), residual.visited.end(), false);
    FordFulkerson::findReachable(source);
}

void FordFulkerson::findReachable(int node)
{
    tcut.erase(node);
    scut.insert(node);
    residual.visited[node] = true;
    for (auto it : residual.adj[node])
    {
        if (residual.visited[it] || (residual.capacities[node][it] == 0))
            continue;
        FordFulkerson::findReachable(it);
    }
}

void FordFulkerson::getAugmentingPath(vector<int> &path, int node, int delta)
{
    path.push_back(node);
    if (path.back() == sink)
        return;
    residual.visited[node] = true;
    for (auto it : residual.adj[node])
    {
        if (residual.visited[it] || (residual.capacities[node][it] < delta))
            continue;
        FordFulkerson::getAugmentingPath(path, it, delta);
        if (path.back() == sink)
            return;
    }
    path.pop_back();
}

void FordFulkerson::calculateMaxFlow()
{
    int maxWeight = 0;
    for (auto it : graph.adj[source])
        maxWeight = max(maxWeight, graph.capacities[source][it]);
    int delta = 1;
    while (delta <= maxWeight)
        delta *= 2;
    delta /= 2;
    vector<int> path;
    while (delta)
    {
        fill(residual.visited.begin(), residual.visited.end(), false);
        FordFulkerson::getAugmentingPath(path, source, delta);
        if ((path.empty()) || (path.back() != sink))
        {
            path.clear();
            delta /= 2;
            continue;
        }
        int minWeight = INF;
        for (int i = 0; i < path.size() - 1; i++)
            minWeight = min(minWeight, residual.capacities[path[i]][path[i + 1]]);
        flow += minWeight;
        for (int i = 0; i < path.size() - 1; i++)
        {
            residual.capacities[path[i]][path[i + 1]] -= minWeight;
            residual.capacities[path[i + 1]][path[i]] += minWeight;
        }
        path.clear();
    }
}