#include "FordFulkerson.h"

FordFulkerson::FordFulkerson()
{
    flow = 0;
    source = -1;
    sink = -1;
}

FordFulkerson::FordFulkerson(Graph &inputGraph, int s, int t) : graph(inputGraph), flow(0), source(s), sink(t)
{
    residual.n = graph.n;
    residual.m = 0;
    residual.visited.resize(graph.n + 1, false);
    for (int i = 1; i <= graph.n; i++)
        tcut.insert(i);
    for (int i = 1; i <= graph.n; i++)
    {
        for (auto it : graph.adj[i])
        {
            residual.adj[i][it.first] = it.second;
            residual.adj[it.first][i] = 0;
            residual.m += 2;
        }
    }
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
        if (residual.visited[it.first] || (it.second == 0))
            continue;
        FordFulkerson::findReachable(it.first);
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
        if (residual.visited[it.first] || (it.second < delta))
            continue;
        FordFulkerson::getAugmentingPath(path, it.first, delta);
        if (path.back() == sink)
            return;
    }
    path.pop_back();
}