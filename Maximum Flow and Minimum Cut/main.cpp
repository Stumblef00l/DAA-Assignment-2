#include "FordFulkerson.h"

using namespace std;

int main()
{
    freopen("test3.txt", "r", stdin);
    freopen("output_test3.txt", "w", stdout);
    cout << "Enter number of nodes: ";
    int n;
    cin >> n;
    cout << "Enter number of edges: ";
    int m;
    cin >> m;
    vector<vector<int>> adj;
    vector<unordered_map<int, int>> capacities;
    vector<int> tempAdj;
    unordered_map<int, int> tempCap;
    for (int i = 1; i <= n + 1; i++)
    {
        adj.push_back(tempAdj);
        capacities.push_back(tempCap);
    }
    cout << "Enter the edges:\n";
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        capacities[u][v] = w;
    }
    Graph inputGraph = Graph(n, m, adj, capacities);
    cout << "Enter source vertex: ";
    int srcVertex;
    cin >> srcVertex;
    cout << "Enter sink vertex: ";
    int sinkVertex;
    cin >> sinkVertex;
    FordFulkerson solutionObject = FordFulkerson(inputGraph, srcVertex, sinkVertex);
    cout << "Max Flow: " << solutionObject.getMaxFlow() << "\n";
    cout << "Min Cut:\n";
    solutionObject.displayMinCut();
}