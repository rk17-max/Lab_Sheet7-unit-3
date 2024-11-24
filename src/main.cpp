#include <iostream>
#include "AVLTree.h"
#include "Graph.h"

int main() {
    // AVL Tree Example
    AVLTree avl;
    avl.root = avl.insert(avl.root, "Region3");
    avl.root = avl.insert(avl.root, "Region1");
    avl.root = avl.insert(avl.root, "Region2");

    std::cout << "Inorder traversal of AVL Tree: ";
    avl.display();

    // Graph Example
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 4, 4);

    std::cout << "BFS starting from vertex 0: ";
    g.BFS(0);

    std::cout << "Dijkstra's algorithm starting from vertex 0:\n";
    g.Dijkstra(0);

    return 0;
}
