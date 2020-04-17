#ifndef BIPARTITE_MATCHING
#define BIPARTITE_MATCHING

#include "FordFulkerson.h"

using namespace std;

/**
 * Class to find the maximum bipartite matching
 */
class BipartiteMatching
{
    long long maxMatchings = 0;
    Graph graph;
    FordFulkerson maxFlowObject;

public:
    /**
     * Parametrized constructor for the max Bipartite matching class
     * @param vertices Total number of vertices in the graph.
     * @param edges Total number of edges in the graph.
     * @param adj Adjacency list of the graph
     * @param capacities Capacities of the edges
     * @param leftSide left side of the graph
     */
    BipartiteMatching(int vertices, int edges, vector<vector<int>> &adj, set<int> leftSide);

    /**
     * Default constructor.
     */
    BipartiteMatching();

    /**
     * Returns the maximum matching of the graph.
     */
    long long getMaxMatching();
};

#endif