// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.
// 05/15/2023 modification by Prof Sipantzi
// This is the file to include for access to the complete binary node
// template implementation

#include "book.h"
#include "BinNode.h"

#pragma once

// Simple binary tree node implementation
template <class Key, class E>
class BSTNode : public BinNode<E> {
private:
    Key k;                  // The node's key
    E it;                   // The node's value
    BSTNode* lc;            // Pointer to left child
    BSTNode* rc;            // Pointer to right child
    unsigned int nodeBitField : 2; // Bit field for left and right threads (0 = thread, 1 = child)

public:
    // Two constructors -- with and without initial values
    BSTNode() { lc = rc = NULL; nodeBitField = 0; }
    BSTNode(Key K, E e, BSTNode* l = NULL, BSTNode* r = NULL)
    {
        k = K; it = e; lc = l; rc = r; nodeBitField = 0;
    }
    ~BSTNode() {}             // Destructor

    // Functions to set and return the value and key
    E& element() { return it; }
    void setElement(const E& e) { it = e; }
    Key& key() { return k; }
    void setKey(const Key& K) { k = K; }

    // Functions to set and return the children
    inline BSTNode* left() const { return lc; }
    void setLeft(BinNode<E>* b) { lc = (BSTNode*)b; }
    inline BSTNode* right() const { return rc; }
    void setRight(BinNode<E>* b) { rc = (BSTNode*)b; }

    // Return true if it is a leaf, false otherwise
    bool isLeaf() { return (lc == NULL) && (rc == NULL); }

    // Return the value of the right bit of the two bits in nodeBitField
    bool getRightBit() {
        // 1 is 01 in binary so we can just do a bitwise AND to get the right bit
        return nodeBitField & 1;
    }

    // Return the value of the left bit of the two bits in nodeBitField
    bool getLeftBit() {
        // 2 is 10 in binary so we can just do a bitwise AND to get the left bit
        return nodeBitField & 2;
    }

    // Set the right bit to be a 1 or 0
    void setRightBit(bool b) {
        // if b is true, set the right bit to 1, otherwise set it to 0
        if (b) {
            nodeBitField |= 1;
        }
        else {
            // Using the bitwise AND operator with 2 will set the right bit to 0
            // This is because 2 is 10 in binary and it will set the right bit to 0 and not modify the left bit
            nodeBitField &= 2;

        }
    }

    // Set the left child to be a thread or not
    void setLeftBit(bool b) {
        // if b is true, set the left bit to 1, otherwise set it to 0
        if (b) {
            nodeBitField |= 2;
        }
        else {
            // Using the bitwise AND operator with 1 will set the left bit to 0
            // This is because 1 is 01 in binary and it will set the left bit to 0 and not modify the right bit
            nodeBitField &= 1;
        }
    }
};