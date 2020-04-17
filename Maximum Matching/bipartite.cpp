#include "BipartiteMatching.h";
#include <iostream>

using namespace std;

int main()
{
    cout << "Enter number of nodes: ";
    int n;
    cin >> n;
    cout << "Enter number of edges: ";
    int m;
    cin >> m;
    vector<vector<int>> adj;
    vector<int> tempAdj;
    for (int i = 1; i <= n + 1; i++)
        adj.push_back(tempAdj);
    set<int> leftSide;
    cout << "Enter the edges:\n";
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        leftSide.insert(u);
    }
    BipartiteMatching ansObject = BipartiteMatching(n, m, adj, leftSide);
    cout << "Maximum Matching: " << ansObject.getMaxMatching();
}