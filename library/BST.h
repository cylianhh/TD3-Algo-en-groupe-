#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct BinaryTreeNode {
    int key;
    struct BinaryTreeNode *left, *right;
};

// Function to create a new node with a given value
struct BinaryTreeNode* newNodeCreate(int value) ;
// Function to search for a node with a specific key in the
// tree
struct BinaryTreeNode* searchNode(struct BinaryTreeNode* root, int target) ;
// Function to insert a node with a specific value in the
// tree
struct BinaryTreeNode* insertNode(struct BinaryTreeNode* node, int value) ;
// Function to perform post-order traversal
void postOrder(struct BinaryTreeNode* root) ;
// Function to perform in-order traversal
void inOrder(struct BinaryTreeNode* root) ;
// Function to perform pre-order traversal
void preOrder(struct BinaryTreeNode* root) ;
// Function to find the minimum value
struct BinaryTreeNode* findMin(struct BinaryTreeNode* root) ;
// Function to delete a node from the tree
struct BinaryTreeNode* delete (struct BinaryTreeNode* root, int x) ;
