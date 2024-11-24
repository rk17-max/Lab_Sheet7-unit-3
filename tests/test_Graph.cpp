#include "Graph.h"
#include <gtest/gtest.h>

TEST(GraphTest, BFS) {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    
    testing::internal::CaptureStdout();
    g.BFS(0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0 1 2 3 "); // Check BFS output
}

TEST(GraphTest, Dijkstra) {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 2);
    
    testing::internal::CaptureStdout();
    g.Dijkstra(0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Distance from 0 to 1 is 1") != std::string::npos); // Check specific distance
}
