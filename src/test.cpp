#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#include <cmath>
#include "LinkedList.hpp"
#include "BST.hpp"

using namespace std;

int main() {
        std::ifstream inputFile("./doc/agaclar.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open agac.txt" << std::endl;
        return 1;
    }

    LinkedList treeList;
    std::string line;

    while (std::getline(inputFile, line)) {
        BinarySearchTree* bst = new BinarySearchTree();
        for (char ch : line) {
            bst->insert(ch);
        }
        treeList.addTree(bst);
    }

    inputFile.close();

    ListNode* currentNode = treeList.getHead();
    char choice;
    int startIndex = 0;
    const int maxPerPage = 10;

    while (true) {
        std::cout << "\nAll Trees in List:\n";
        treeList.displayTreeBlocks(currentNode, startIndex, maxPerPage);

        std::cout << "\nCurrent Tree Visualization:\n";
        treeList.displayCurrentTree(currentNode);

        std::cout << "\nOptions: \n";
        std::cout << "a: Previous Tree\nd: Next Tree\nm: Mirror Current Tree\ns: Delete Current Tree\nq: Quit\n";
        std::cout << "Enter choice: ";

        choice = _getch();
        std::cout << choice << std::endl;

        if (choice == 'q') {
            break;
        } 
        if (choice == 'a') {
    if (currentNode != treeList.getHead()) {
        ListNode* temp = treeList.getHead();
        while (temp->next != currentNode) {
            temp = temp->next;
        }
        currentNode = temp;

        if (startIndex > 0 && startIndex % maxPerPage == 0) {
            --startIndex;
        }
    }
} else if (choice == 'd') {
    if (currentNode->next != nullptr) {
        currentNode = currentNode->next;

        if ((startIndex + 1) % maxPerPage == 0) {
            ++startIndex;
        }
    }
}
        else if (choice == 's') {
            // Delete the current tree
            treeList.deleteCurrentTree(currentNode);
            if (currentNode == nullptr) {
                std::cout << "All trees have been deleted. Exiting...\n";
                break;
            }
        } 
        else if (choice == 'm') {
            // Mirror the current tree
            if (currentNode != nullptr) {
                currentNode->bst->mirror();
                std::cout << "Current tree mirrored.\n";
            }
        } 
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    std::cout << "Program terminated.\n";
    return 0;
}
