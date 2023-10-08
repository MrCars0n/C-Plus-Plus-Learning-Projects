// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.
// 05/15/2023 modification by Prof Sipantzi
// This file includes all of the pieces of the BST implementation

// Include the node implementation
#include "BSTNode.h"

// Include the dictionary ADT
#include "dictionary.h"
#include <iostream>
#include <stack>

#pragma once

using namespace std;

// Binary Search Tree implementation for the Dictionary ADT
template <class Key, class E>
class BST : public Dictionary<Key, E> {
private:
    BSTNode<Key, E>* root;   // Root of the BST

    int nodecount;         // Number of nodes in the BST

    // Private "helper" functions
    void clearhelp(BSTNode<Key, E>*);
    BSTNode<Key, E>* inserthelp(BSTNode<Key, E>*,
        const Key&, const E&);
    BSTNode<Key, E>* deletemin(BSTNode<Key, E>*);
    BSTNode<Key, E>* getmin(BSTNode<Key, E>*);
    BSTNode<Key, E>* removehelp(BSTNode<Key, E>*, const Key&);
    E* findhelp(BSTNode<Key, E>*, const Key&) const;
    void printhelp(BSTNode<Key, E>*, int) const;
    void vist(BSTNode<Key, E>*) const;

public:
    BST() { root = NULL; nodecount = 0; }  // Constructor
    void printInorder() const;
    void printReverse() const;

    //Note from Prof Sipantzi -- I've commented out the destructor
    //since you would have to change clearhelp() to make it work with
    //doubly-threaded trees and that is not part of the assignment.
    //~BST() { clearhelp(root); }            // Destructor

    void clear()   // Reinitialize tree
    {
        clearhelp(root); root = NULL; nodecount = 0;
    }

    // Insert a record into the tree.
    // k Key value of the record.
    // e The record to insert.
    void insert(const Key& k, const E& e) {
        root = inserthelp(root, k, e);
        nodecount++;
    }

    // Remove a record from the tree.
    // k Key value of record to remove.
    // Return: The record removed, or NULL if there is none.
    E* remove(const Key& k) {
        E* temp = findhelp(root, k);   // First find it
        if (temp != NULL) {
            root = removehelp(root, k);
            nodecount--;
        }
        return temp;
    }
    // Remove and return the root node from the dictionary.
    // Return: The record removed, null if tree is empty.
    E* removeAny() {  // Delete min value
        if (root != NULL) {
            E* temp = new E;
            *temp = root->element();
            root = removehelp(root, root->key());
            nodecount--;
            return temp;
        }
        else return NULL;
    }

    // Return Record with key value k, NULL if none exist.
    // k: The key value to find. */
    // Return some record matching "k".
    // Return true if such exists, false otherwise. If
    // multiple records match "k", return an arbitrary one.
    E* find(const Key& k) const { return findhelp(root, k); }

    // Return the number of records in the dictionary.
    int size() { return nodecount; }

    void print() const { // Print the contents of the BST
        if (root == NULL) cout << "The BST is empty.\n";
        else printhelp(root, 0);
    }

};

// Visit -- prints out root
template <typename Key, typename E>
void BST<Key, E>::vist(BSTNode<Key, E>* r) const {
    cout << "Node - " << r->element() << endl;
}

// Clean up BST by releasing space back free store
template <typename Key, typename E>
void BST<Key, E>::
clearhelp(BSTNode<Key, E>* root) {
    if (root == NULL) return;
    clearhelp(root->left());
    clearhelp(root->right());
    delete root;
}

// Insert a node into the BST, returning the updated tree
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::inserthelp(BSTNode<Key, E>* root, const Key& k, const E& it) {

    // If the root is null then insert the node
    if (root == NULL) {
        return new BSTNode<Key, E>(k, it, NULL, NULL);;
    }

    if (k < root->key()) {
        // If the left node is a thread then insert the node
        if (root->getLeftBit() == 0) {
            BSTNode<Key, E>* temp = new BSTNode<Key, E>(k, it, root->left(), root);
            root->setLeft(temp);
            root->setLeftBit(1);
        }
        else {
            // Otherwise traverse the left subtree
            root->setLeft(inserthelp(root->left(), k, it));
        }
    }
    else {
        // If the right node is a thread then insert the node
        if (root->getRightBit() == 0) {
            BSTNode<Key, E>* temp = new BSTNode<Key, E>(k, it, root, root->right());
            root->setRight(temp);
            root->setRightBit(1);
        }
        else {
            // Otherwise traverse the right subtree
            root->setRight(inserthelp(root->right(), k, it));
        }
    }

    return root;
}

// Delete the minimum value from the BST, returning the revised BST
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
getmin(BSTNode<Key, E>* rt) {
    if (rt->left() == NULL)
        return rt;
    else return getmin(rt->left());
}
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
deletemin(BSTNode<Key, E>* rt) {
    if (rt->left() == NULL) // Found min
        return rt->right();
    else {                      // Continue left
        rt->setLeft(deletemin(rt->left()));
        return rt;
    }
}

// Remove a node with key value k
// Return: The tree with the node removed
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
removehelp(BSTNode<Key, E>* rt, const Key& k) {
    if (rt == NULL) return NULL;    // k is not in tree
    else if (k < rt->key())
        rt->setLeft(removehelp(rt->left(), k));
    else if (k > rt->key())
        rt->setRight(removehelp(rt->right(), k));
    else {                            // Found: remove it
        BSTNode<Key, E>* temp = rt;
        if (rt->left() == NULL) {     // Only a right child
            rt = rt->right();         //  so point to right
            delete temp;
        }
        else if (rt->right() == NULL) { // Only a left child
            rt = rt->left();          //  so point to left
            delete temp;
        }
        else {                    // Both children are non-empty
            BSTNode<Key, E>* temp = getmin(rt->right());
            rt->setElement(temp->element());
            rt->setKey(temp->key());
            rt->setRight(deletemin(rt->right()));
            delete temp;
        }
    }
    return rt;
}

// Find a node with the given key value
template <typename Key, typename E>
E* BST<Key, E>::findhelp(BSTNode<Key, E>* root,
    const Key& k) const {
    if (root == NULL) return NULL;          // Empty tree
    if (k < root->key())
        return findhelp(root->left(), k);   // Check left
    else if (k > root->key())
        return findhelp(root->right(), k);  // Check right
    else {
        E* temp = new E;
        *temp = root->element();
        return temp;  // Found it
    }
}

// Print out a BST
template <typename Key, typename E>
void BST<Key, E>::
printhelp(BSTNode<Key, E>* root, int level) const {
    if (root == NULL) return;           // Empty tree

    // If the left node is not a thread then print the left subtree
    if (root->getLeftBit() == 1)
        printhelp(root->left(), level + 1);   // Do left subtree

    for (int i = 0; i < level; i++)         // Indent to level
        cout << "  ";

    cout << root->key() << "\n";        // Print node value

    // If the right node is not a thread then print the right subtree
    if (root->getRightBit() == 1)
        printhelp(root->right(), level + 1);   // Do right subtree
}

// Using a stack we can iteratively print out a BST in order
template <typename Key, typename E>
void BST<Key, E>::printInorder() const {
    if (root == NULL) return; // Empty tree

    BSTNode<Key, E>* current = root;
    while (true) {
        // If there is not a thread to the left then traverse the left subtree
        if (current->getLeftBit() == 1) {
            current = current->left();
            // If the the left node is a thread and the right node is not a thread then print the current node
            // And traverse the right subtree
        }
        else if (current->getLeftBit() == 0 && current->getRightBit() == 1) {
            cout << current->element() << endl;
            current = current->right();
            // Otherwise if the right node is a thread
        }
        else if (current->getRightBit() == 0) {
            // Print out the node and traverse the right subtree
            cout << current->element() << endl;
            current = current->right();

            // If the right node is not a thread then we do this
            // The reason we do it in this order is because we are going back
            // to a previous node and printing the right subtree
            if (current->getRightBit() == 1) {
                cout << current->element() << endl;
                current = current->right();
            }
            else {
                // Otherwise we are at the end of the tree (The farthest right node)
                // Print and exit the loop
                cout << current->element() << endl;
                break;
            }
        }
    }
}

// Print out a BST
template <typename Key, typename E>
void BST<Key, E>::printReverse() const {
    if (root == NULL) return; // Empty tree

    BSTNode<Key, E>* current = root;
    while (true) {
        // If there is not a thread to the right then traverse the right subtree
        if (current->getRightBit() == 1) {
            current = current->right();
            // If the the right node is a thread and the left node is not a thread then print the current node
            // And traverse the left subtree
        }
        else if (current->getRightBit() == 0 && current->getLeftBit() == 1) {
            cout << current->element() << endl;
            current = current->left();
            // Otherwise if the left node is a thread
        }
        else if (current->getLeftBit() == 0) {
            cout << current->element() << endl;
            current = current->left();

            // If current is null then we are at the end of the tree (The leftmost node)
            if (current == NULL) {
                break;
                // If the left node is not a thread then we print the current node
                // And traverse the left subtree
            }
            else if (current->getLeftBit() == 1) {
                cout << current->element() << endl;
                current = current->left();
            }
            else {
                // This is the edge case for the root element
                // You have to force the tree to go left 2 times
                cout << current->element() << endl;
                current = current->left();
                cout << current->element() << endl;
                current = current->left();
            }

        }
    }

}