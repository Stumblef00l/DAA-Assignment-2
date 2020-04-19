#include "BipartiteMatching.h";
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    cout << "Enter number of nodes: ";
    int n;
    cin >> n;
    cout << "Enter number of edges: ";
    int m;
    cin >> m;
    clock_t beg, fin;
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
    beg = clock();
    BipartiteMatching ansObject = BipartiteMatching(n, m, adj, leftSide);
    fin = clock();
    cout << "Time take: " << (double(fin - beg)) / (double(CLOCKS_PER_SEC)) << " seconds\n";
    cout << "Maximum Matching: " << ansObject.getMaxMatching();
}