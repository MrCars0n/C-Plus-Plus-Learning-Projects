#include "llist.h"
#include "SelfOrderedListADT.h"

#pragma once

template <class E>
class SOLTranspose : public SelfOrderedListADT<E> {
private:
	LList<E>* list;
	int compares;
public:
	// Default constructor/destructor
	SOLTranspose() {
		compares = 0;
		list = new LList<E>();
	}

	~SOLTranspose() {
		delete list;
	}

	// Look for 'it'.  If found return true and execute the self-ordering
	//  heuristic used for ordering the list: count, move-to-front, or transpose.
	//  Increments the compare instance variable every time it compares 'it' to
	//  other members of the list-> Returns true if 'it' is found.
	bool find(const E& it) {
		// Move to the start
		list->moveToStart();

		// Looping through till we find 'it' or reach the end of the list
		int curr_pos = list->currPos();

		for (int i = 0; i < list->length(); i++) {
			compares++;
			if (list->getValue() == it)
			{
				break;
			}
			list->next();
		}

		if (list->currPos() < list->length()) {
			// 'it' was found
			//  Move 'it' to the front of the list
			//  compares++;
			reorder();
			return true;
		}
		else {
			add(it);

			// 'it' was not found
			return false;
		}
	}

	// This function assumes that you are at the correct position of the item 
	// that you would like to reorder
	void reorder() {
		// We need to get hold of the frequency of 'it' before we remove it
		int frequency = list->getFrequency();
		E realItElement = list->remove();

		// Move the iterator to the start of the list
		list->prev();

		// Insert 'it' at the start of the list
		list->insert(realItElement);
		list->setFrequency(frequency + 1);
	}

	// Called by find if 'it' is not in the list-> Adds the new 'it' to the list
	//  Can also be called independently when initially loading the list with
	//  unique values and when you want to load the list in the order 'it' is 
	//  read without your re-order method being called (or the number of compares
	//  being incremented.
	void add(const E& it) {
		// No harm in making sure that we are at the start of the list
		list->append(it);
	}
	//Add new 'it' to the list

	// Returns the number of accumulated compares
	int getCompares() const {
		return compares;
	}

	// Returns the size of the list
	int size() const {
		return list->length();
	}       

	// Print the list
	//  In order print of the list->  printlist() prints the entire list
	//  whereas printlist(n) prints n nodes.
	void printlist() {
		list->moveToStart();
		for (int i = 0; i < list->length(); i++) {
			std::cout << list->getValue() << "-" << list->getFrequency() << " ";
			list->next();
		}
		std::cout << std::endl;
	}

	void printlist(int n) {
		list->moveToStart();
		for (int i = 0; i < n; i++) {
			std::cout << list->getValue() << "-" << list->getFrequency() << " ";
			list->next();
		}
		std::cout << std::endl;
	}


};
