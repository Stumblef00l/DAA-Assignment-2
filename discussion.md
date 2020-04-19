# Discussion

Results on various Tests can be found in the `Tests` file on the _Related Pages_ tab.\n

## Algorithm Discussion

This assignment implements the Ford Fulkerson algorithm for finding Maximum flow in a directed graph network.

A flow network is a directed weighted graph where the weight of an edge is called its capactiy. As the name intuitively suggests, the capacity implies the maximum flow of the quantity being passes through the network that edge can hold. In addition to this, each network has a single source vertex and a single sink vertex. As the name suggests, the flow starts at the source vertex and is collected at the destination sink vertex. The source has no incoming edge and the sink has no outgoing edge.

The Ford Fulkerson finds the maximum flow of the network from source to sink. In brief, it runs on an auxillary graph of the original network called the residual graph. It runs as long as it can find an augmenting path from the source to the sink with each edge leftover capacity > 0. After that, the flow in each of the edges on the path is increased by the minimum leftover capacity on the path. The algorithm terminates, as the maximum flow cannot exceed the sum of capacities of the capacities of the edges originating at the source vertex. This is however, a very generous bound.

The minimum cut of a graph is the partition of vertices of the graph with minimum sum of net capacities such that one partition constists of the source vertex and the other contains the sink vertex.

After Ford Fulkerson is run, it can be proven that the minimum cut of the network is a partition such that one half consists of vertices to which an augmenting path from the source vertex still exists, and the other half has the remaining vertices.

Bipartite matching is a problem in which we have vertices of two colours, and vertices of colour 1 are connected to some or all vertices of colour 2 (bipartite graph) and a subset of vertices such that each vertex has indegree and outdegree <= 1. Maximum bipartite matching is the problem of finding maximum such matchings.

Max flow can be used to find maximum matching of a bipartite graph, by assigning each edge a weight of 1, declaring an auxillary source and connecting it to all nodes of colour 1, and similarly all nodes of colour 2 connecting to an auxillary sink. The maximum matching is the max flow of this graph.

## Runtime Analysis

The Ford Fulkerson algorithm implemented here takes O((m^2) \* log(C)). Here, m is the number of edges in the graph and C is the max capacity edge originating at the the source vertex.

In each step, we find an augmenting path which takes O(m) time. The max number of edges which need to be exhausted before termination is also O(m). Lastly, we use the delta optimizations to find good augmenting paths. This brings down the time from an extra O(C) to O(log(C)). Hence the runtime.

The space complexity of the algorithm is O(n+m). The dominating space occupation are the graph and the corresponding auxillary graph, which are stores in adjacency lists and henc take up O(n+m) space.

## References, Issues, and Remarks

References: Lecture slides.

Issues while coding: The major issue while coding was storing the edge capacities optimally. This was a problem as a direct adjacency list implementation using an array of vectors, although would occupy O(n+m) memory but would require O(n) for lookup for the capacity values. The other option was using an adjacency matrix, which allows O(1) lookup but would need O(n^2) memory. The third option was using an ordered map (binary search tree), which has O(logn) lookup and O(n+m) storage. Finally, the option we ended up using was using an unordered hashmap which has O(1) lookup and O(n+m) memory.
