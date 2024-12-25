#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <conio.h> // For _getch() to handle input
#include <iomanip> // For std::setw


// Node structure for Binary Search Tree
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BinarySearchTree {
private:
    TreeNode* root;

    // Helper function to insert a value into the BST
    TreeNode* insert(TreeNode* node, char value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Helper function to visualize the tree
    void visualizeTree(TreeNode* node, int depth, std::string prefix = "") {
        if (node == nullptr) return;

        visualizeTree(node->right, depth + 1, prefix + "       ");

        std::cout << prefix;
        if (depth == 0) {
            std::cout << "Root: ";
        } else {
            std::cout << "      ";
        }
        std::cout << node->data << std::endl;

        visualizeTree(node->left, depth + 1, prefix + "       ");
    }

    // Helper function to calculate the total value of the tree
    int calculateTreeValue(TreeNode* node) {
        if (node == nullptr) return 0;
        return node->data + calculateTreeValue(node->left) + calculateTreeValue(node->right);
    }

    // Helper function to mirror the tree
    void mirrorTree(TreeNode* node) {
        if (node == nullptr) return;
        std::swap(node->left, node->right);
        mirrorTree(node->left);
        mirrorTree(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        deleteTree(root);
    }

    // Insert a value into the BST
    void insert(char value) {
        root = insert(root, value);
    }

    // Visualize the tree
    void displayTreeVisually() {
        visualizeTree(root, 0);
    }

    // Get the total value of the tree
    int getTreeValue() {
        return calculateTreeValue(root);
    }

    // Mirror the tree
    void mirror() {
        mirrorTree(root);
    }

    TreeNode* getRoot() {
        return root;
    }

private:
    // Helper function to delete the tree
    void deleteTree(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
};



#endif