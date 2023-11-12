#ifndef LINK_H
#define	LINK_H

#include <cstdlib>

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.
// Modified 05/15/2023 -- Prof Sipantzi

// Singly linked list node
template <class E> 
class Link {
public:
  E element;      // Value for this node
  Link *next;     // Pointer to next node in list
  int freq;   // Frequency of the element
  // Constructors
  // Set the frequency to zero by default
  Link(const E& elemval, Link* nextval =NULL)
    { element = elemval;  next = nextval; freq = 0;}
  Link(Link* nextval =NULL) { next = nextval; freq = 0;}
};

#endif