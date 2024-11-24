#include "Graph.h"
#include <iostream>
#include <queue>
#include <climits>

Graph::Graph(int V) : V(V) {
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int weight) {
    adj[u].emplace_back(v, weight);
    adj[v].emplace_back(u, weight); // For undirected graph
}

void Graph::BFS(int start) {
    std::vector<bool> visited(V, false);
    std::queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        std::cout << node << " ";

        for (auto& neighbor : adj[node]) {
            if (!visited[neighbor.first]) {
                visited[neighbor.first] = true;
                q.push(neighbor.first);
            }
        }
    }
    std::cout << std::endl;
}

void Graph::Dijkstra(int start) {
    std::vector<int> dist(V, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    dist[start] = 0;
    pq.push(std::make_pair(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(std::make_pair(dist[v], v));
            }
        }
    }

    for (int i = 0; i < V; ++i)
        std::cout << "Distance from " << start << " to " << i << " is " << dist[i] << std::endl;
}
