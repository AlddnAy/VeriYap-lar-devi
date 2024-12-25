#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "BST.hpp"


// Node structure for Linked List
struct ListNode {
    BinarySearchTree* bst;
    int totalValue;
    ListNode* next;

    ListNode(BinarySearchTree* tree) : bst(tree), totalValue(0), next(nullptr) {}
};

// Linked List class
class LinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp->bst;
            delete temp;
        }
    }

    // Add a new BST to the list
    void addTree(BinarySearchTree* bst) {
        ListNode* newNode = new ListNode(bst);
        newNode->totalValue = bst->getTreeValue();
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Get the head of the list
    ListNode* getHead() {
        return head;
    }

    void displayTreeBlocks(ListNode* currentNode, int startIndex, int maxPerPage = 10) {
    ListNode* temp = head;
    int index = 0;

    // Skip to the starting index
    while (temp != nullptr && index < startIndex) {
        temp = temp->next;
        ++index;
    }

    int count = 0;

    // Display tree blocks in a row
    while (temp != nullptr && count < maxPerPage) {
        std::cout << "+-------------+  ";
        temp = temp->next;
        ++count;
    }
    std::cout << "\n";

    temp = head;
    index = 0;
    while (temp != nullptr && index < startIndex) {
        temp = temp->next;
        ++index;
    }

    count = 0;
    while (temp != nullptr && count < maxPerPage) {
        std::cout << "|";
        std::cout << std::setw(7) << temp->totalValue << std::setw(6) << "|  ";
        temp = temp->next;
        ++count;
    }
    std::cout << "\n";

    temp = head;
    index = 0;
    while (temp != nullptr && index < startIndex) {
        temp = temp->next;
        ++index;
    }

    count = 0;
    while (temp != nullptr && count < maxPerPage) {
        std::cout << "+-------------+  ";
        temp = temp->next;
        ++count;
    }
    std::cout << "\n";

    // Display cursor under the current block
    temp = head;
    index = 0;
    while (temp != nullptr && index < startIndex) {
        temp = temp->next;
        ++index;
    }

    count = 0;
    while (temp != nullptr && count < maxPerPage) {
        if (temp == currentNode) {
            std::cout << "      ^         ";
        } else {
            std::cout << "                ";
        }
        temp = temp->next;
        ++count;
    }
    std::cout << "\n";
}


    // Display only the current tree visually
    void displayCurrentTree(ListNode* currentNode) {
        if (currentNode != nullptr) {
            currentNode->bst->displayTreeVisually();
        }
    }

    // Delete the current tree
    void deleteCurrentTree(ListNode*& currentNode) {
        if (currentNode == nullptr) return;

        if (currentNode == head) {
            head = head->next;
            delete currentNode->bst;
            delete currentNode;
            currentNode = head;
        } else {
            ListNode* prev = head;
            while (prev->next != currentNode) {
                prev = prev->next;
            }
            prev->next = currentNode->next;
            if (currentNode == tail) {
                tail = prev;
            }
            delete currentNode->bst;
            delete currentNode;
            currentNode = prev->next;
        }
    }
};

#endif