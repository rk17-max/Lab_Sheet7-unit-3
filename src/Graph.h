#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <utility>

class Graph {
public:
    int V; // Number of vertices
    std::vector<std::list<std::pair<int, int>>> adj;

    Graph(int V);
    void addEdge(int u, int v, int weight = 1);
    void BFS(int start);
    void Dijkstra(int start);
};

#endif // GRAPH_H
