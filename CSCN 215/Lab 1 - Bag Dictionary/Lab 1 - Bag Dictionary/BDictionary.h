#pragma once

#include "dictionaryADT.h"
#include "ABag.h"
#include "kvpair.h"

template <typename Key, typename E>
class BDictionary : public Dictionary<Key, E>
{
private:
	ABag<KVpair<Key, E>>* kvPairBag;

public:
	// Default constructor
	BDictionary()
	{
		kvPairBag = new ABag<KVpair<Key, E>>();
	}
	// Constructor
	BDictionary(int capacity)
	{
		kvPairBag = new ABag<KVpair<Key, E>>(capacity);
	}
	~BDictionary()  // Base destructor
	{
		delete kvPairBag;
	}

	// Reinitialize dictionary
	void clear()
	{
		kvPairBag->emptyBag();
	}

	// Insert a record
	// k: The key for the record being inserted.
	// e: The record being inserted.
	// Return true if insert is successful and false otherwise
	bool insert(const Key& k, const E& e)
	{
		KVpair<Key, E> temp(k, e);
		return kvPairBag->addItem(temp);
	}

	// Looks for a record using the key and if found does the following:
	// - updates the E& rtnVal
	// - removes the record from the dictionary
	// - returns true
	// If the record is not found the function returns false.
	bool remove(const Key& k, E& rtnVal)
	{
		// Create temporary KVpair for removal
		KVpair<Key, E> temp(k, rtnVal);

		// Call remove function from ABag, to remove the KVpair based on the key
		bool returnBoolean = kvPairBag->remove(temp);

		// Set rtnVal to the value of the KVpair in the bag
		rtnVal = temp.value();

		// Return result of operation
		return returnBoolean;
	}

	// Takes an arbitrary record from the dictionary and does the following:
	// - updates the E& returnValue
	// - removes the record from the dictionary
	// - returns true
	// If the dictionary is empty the function returns false.
	bool removeAny(E& returnValue)
	{
		// If the bag is empty, return false
		if (kvPairBag->numItems() <= 0)
		{
			return false;
		}
		else
		{
			// Create temporary KVpair
			KVpair<Key, E> temp;

			// Remove the top KVpair from the bag
			kvPairBag->removeTop(temp);

			// Set returnValue to the value returned in temp
			returnValue = temp.value();
		
			return true;
		}
	}

	// Looks for a record using the key and if found does the following:
	// - updates the E& returnValue
	// - returns true
	// If the record is not found the function returns false.
	bool find(const Key& k, E& returnValue) const
	{
		// Create temporary KVpair for removal
		KVpair<Key, E> temp(k, returnValue);

		// Call search function from ABag, to search the KVpair based on the key
		bool returnBoolean = kvPairBag->search(temp);

		// Set rtnVal to the value of the KVpair in the bag
		returnValue = temp.value();

		// Return result of operation
		return returnBoolean;
	}

	// Return the number of records in the dictionary.
	int size() const
	{
		return kvPairBag->numItems();
	}
};
