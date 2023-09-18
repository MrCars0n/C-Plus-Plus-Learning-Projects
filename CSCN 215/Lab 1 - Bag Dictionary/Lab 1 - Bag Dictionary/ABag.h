#pragma once

#include "bagADT.h"
#include <memory>

template <typename E>
class ABag : public Bag<E>
{
private:
	// This is our unique pointer "List" of items of type E
	std::unique_ptr<E[]> bag;
	int bagSize; // Current size of list
	int capacityOfBag; // Capacity variable

public:
	// Initialize our bag with the const bag capacity
	// Default constructor
	ABag()
	{
		// Initialize variables
		bagSize = 0;
		capacityOfBag = 10;

		// Initialize our bag with the capcity
		bag = std::make_unique<E[]>(capacityOfBag);
	}
	// Constructor 
	ABag(int capacity)
	{
		// Initialize our bag with the bag capacity
		bagSize = 0;
		capacityOfBag = capacity;

		// Initialize our bag with the capcity
		bag = std::make_unique<E[]>(capacityOfBag);
	}  

	~ABag() {} // base destructor
	
	// Insert a new item into the bag -- return false if fails and true if
	// successful
	bool addItem(const E& item)
	{
		// If the bag is full , return false
		if (bagSize == bagCapacity())
		{
			return false;
		}

		// Other wise, add the item to the bag
		// Increment bag size after adding the item
		bag[bagSize++] = item;
		return true;
	}

	// Looks for 'item' in the bag and if found updates 'item' with the 
	// bag value and returns true.  Otherwise 'item' is left unchanged
	// and the method returns false.
	bool remove(E& item)
	{
		// Checking if bag is greather than zero
		if (bagSize <= 0)
		{
			return false;
		}
		else
		{
			// Loop through the bag
			for (int i = 0; i < bagSize; i++)
			{
				// If the current element (bag[i]) is equal to the parameter, returnValue
				if (bag[i] == item)
				{
					// Update returnValue
					item = bag[i];

					// Decrement total bag size
					bagSize--;

					// Shift all the elements to the left
					for (int j = i; j < bagSize; j++)
					{
						bag[j] = bag[j + 1];
					}

					return true;
				}
			}
			return false;
		}
	}

	// Removes the top record from the bag, puts it in returnValue, and
	// returns true if the bag is not empty.  If the bag is empty the 
	// function returns false and returnValue remains unchanged.
	bool removeTop(E& returnValue)
	{
		// If bag is zero or less than, return false
		if (bagSize <= 0)
		{
			return false;
		}
		else
		{
			// Set item to the last (top) element in the bag
			returnValue = bag[bagSize - 1];

			// Decrement bagSize so the top element will eventually be written over
			bagSize--;

			return true;
		}
	}

	// Finds the record using returnValue and if the record is found updates
	// returnValue based on the contents of the bag and returns true.  If the
	// record is not found the function returns false.  Works just like remove()
	// except that the found record is not removed from the bag.
	bool search(E& returnValue) const
	{
		// Checking bag size is greater than zero
		if (bagSize <= 0)
		{
			return false;
		}
		else
		{
			// Loop through the bag
			for (int i = 0; i < bagSize; i++)
			{
				// If the current element (bag[i]) is equal to the parameter, returnValue
				if (bag[i] == returnValue)
				{
					// Update returnValue
					returnValue = bag[i];
					return true;
				}
			}
			return false;
		}
	}

	// Inspect the top of the bag.  If the bag is empty return
	// false and leave 'item' unchanged; otherwise, return true and update 
	// 'item' with the contents of the bag.
	bool inspectTop(E& item) const
	{
		// If bag is empty, return false
		if (bagSize <= 0)
		{
			return false;
		}
		else
		{
			// Set item to the last (top) element in the bag
			item = bag[bagSize - 1];
			return true;
		}
	}

	// empties the bag
	void emptyBag()
	{
		// Reset set counter to 0
		bagSize = 0;

		// Reassign the smart pointer to a new array to reset memory
		bag = std::make_unique<E[]>(bagCapacity());
	}

	// use the += operator to add an item to the bag
	bool operator+=(const E& addend)
	{
		return addItem(addend);
	}

	// get the number of items in the bag
	int numItems() const
	{
		return bagSize;
	}

	// get the capacity of the bag (size of your bag's array)
	int bagCapacity() const
	{
		// According to the slides, the capacity is 10
		return capacityOfBag;
	}
};