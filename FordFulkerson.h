#ifndef FORD_FULKERSON
#define FORD_FULKERSON

#include "Graph.h"
#include <set>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define INF 2000000000

using namespace std;

class FordFulkerson
{
    Graph graph;
    Graph residual;
    long long flow = 0;
    int source;
    int sink;
    set<int> scut;
    set<int> tcut;

    void getAugmentingPath(vector<int> &path, int node, int delta);

    void calculateMaxFlow();

    void getSCutVertices();

    void findReachable(int node);

public:
    /**
     * Parametrized Constructor for the class
     * @param inputGraph The input graph.
     * @param s Source vertex
     * @param t Sink Vertex
     */
    FordFulkerson(Graph &inputGraph, int s, int t);

    /**
     * Default constructor for the class
     */
    FordFulkerson();

    /**
     * Return the maximum flow for the network.
     */
    long long getMaxFlow();

    /**
     * Display minimum cut of the network.
     */
    void displayMinCut();
};

#endif