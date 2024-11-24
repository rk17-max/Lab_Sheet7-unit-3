#include "AVLTree.h"
#include <gtest/gtest.h>

TEST(AVLTreeTest, Insertion) {
    AVLTree avl;
    avl.root = avl.insert(avl.root, "10");
    avl.root = avl.insert(avl.root, "20");
    avl.root = avl.insert(avl.root, "30");
    EXPECT_EQ(avl.root->key, "20"); // Check root after rotations
}

TEST(AVLTreeTest, Display) {
    AVLTree avl;
    avl.root = avl.insert(avl.root, "30");
    avl.root = avl.insert(avl.root, "20");
    avl.root = avl.insert(avl.root, "10");
    testing::internal::CaptureStdout();
    avl.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10 20 30 \n"); // Check inorder display
}
