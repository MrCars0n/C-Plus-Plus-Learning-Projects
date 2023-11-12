#include "llist.h"
#include "SelfOrderedListADT.h"

#pragma once

template <class E>
class SOLCount : public SelfOrderedListADT<E> {
private:
	LList<E>* list;
	int compares;
public:
	// Default constructor/destructor
	SOLCount() {
		compares = 0;
		list = new LList<E>();
	}

	~SOLCount() {
		delete list;
	}

	// Look for 'it'.  If found return true and execute the self-ordering
	//  heuristic used for ordering the list: count, move-to-front, or transpose.
	//  Increments the compare instance variable every time it compares 'it' to
	//  other members of the list-> Returns true if 'it' is found.
	bool find(const E& it) {
		// Move to start
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

		// If we found 'it' then we need to reorder the list
		if (list->currPos() < list->length()) {
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
	//  that you would like to reorder
	void reorder() {
		int frequency = list->getFrequency() + 1;
		E realItElement = list->remove();

		// We need to find the correct position to insert 'it' back into the list
		list->moveToStart();
		int curr_pos = list->currPos();
		while (curr_pos < list->length() && list->getFrequency() >= frequency) {
			list->next();
			curr_pos++;
		}

		// We have found the correct position to insert 'it' back into the list
		list->insert(realItElement);
		list->setFrequency(frequency);
	}

	// Called by find if 'it' is not in the list-> Adds the new 'it' to the list
	//  Can also be called independently when initially loading the list with
	//  unique values and when you want to load the list in the order 'it' is 
	//  read without your re-order method being called (or the number of compares
	//  being incremented.
	void add(const E& it) {
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
