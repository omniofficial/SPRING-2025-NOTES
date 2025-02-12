# LECTURE 4:

## Complete Graphs

A complete graph is a graph in which every pair of vertices is connected.

## Adjacency list

-   Uses linked list of vertex objects
-   Each element in the list will have two values
    -   First one is the destination node
    -   Second one is the weight between the two nodes
-   Adding a vertex/edge takes O(1); removing a vertex takes O(deg v).

For example, if node 1 is connected to node 2, and it carries a 25 weight then it would be:
1 -> 2 | 25

Otherwise, the weight would be replaced by either a 0 (no connection) or a 1 (connection between nodes) for undweighted graphs.

## Sparse, Dense, and Planar Graphs

**Sparse Graph:** A graph in which the number of edges is close tothe minimal number of edges (0).

**Dense Graph:** A graph in which the number of edges is close to the maximal number of edges (n(n-1)) / 2, where n is the number of nodes.

**Planar Graph:** A graph that can be embedded in a plane, such that no edge crosses each other.


