#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <string>

class AVLNode {
public:
    std::string key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(std::string key) : key(key), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    AVLNode* root;
    
    AVLTree() : root(nullptr) {}

    int getHeight(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    AVLNode* insert(AVLNode* node, std::string key);
    void inorder(AVLNode* node);
    void display();
};

#endif // AVLTREE_H
