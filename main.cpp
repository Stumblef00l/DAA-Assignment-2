#include "FordFulkerson.h"

using namespace std;

int main()
{
    cout << "Enter number of nodes: ";
    int n;
    cin >> n;
    cout << "Enter number of edges: ";
    int m;
    cin >> m;
    Graph inputGraph = Graph(n, m);
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