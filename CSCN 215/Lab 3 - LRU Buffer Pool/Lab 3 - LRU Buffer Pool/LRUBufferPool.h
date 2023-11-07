#pragma once

#include <string>
#include <fstream>
#include "BufferPoolADT.h"
#include "LRUBufferBlock.h"
#include "constants.h"

class LRUBufferPool : public BufferPoolADT
{
private:
	//The buffer pool consists of X number of buffer blocks
	// Use POOL_SIZE global variable to prevent going out of bounds
	LRUBufferBlock* bufferPool[POOL_SIZE];
	string globalFileName;
public:
	//Constructor gets the filename of the file to be buffered,
	//opens the file, and instantiates poolSize buffer blocks by
	//reading the file and filling the blocks in order.  When the constructor
	//is done the buffer pool blocks should be full with the beginning
	//contents of the input file.
	LRUBufferPool() {}
	LRUBufferPool(string filename, int poolSize = 5, int blockSize = 4096) 
	{
		// Set global file name for later use
		globalFileName = filename;

		// Open file
		fstream file;
		file.open(filename.c_str(), fstream::in | fstream::binary);

		for (int i = 0; i < poolSize; i++)
		{
			file.seekg(i * blockSize);
			//char* data = new char[blockSize];
			char* data = getCharArray(blockSize);

			file.read(data, blockSize);

			// Instantiate the buffer block
			bufferPool[i] = new LRUBufferBlock(data, blockSize);

			// Set the ID of the block
			bufferPool[i]->setID(i);

			// Delete the data
			delete[] data;
		}
	}
	~LRUBufferPool() 
	{
		delete[] bufferPool;
	}

	// Copy "sz" bytes from position "pos" of the buffered
	//   storage to "space".
	void getBytes(char* space, int sz, int pos)
	{
		bool foundID;
		int currentIndex;

		// Round down to the nearest block
		int startBlockIndex = pos / BLOCKSIZE;

		// Get the data from the start block
		// Check if the ID for the block is in the pool
		for (int i = 0; i < POOL_SIZE; i++)
		{
			if (bufferPool[i]->getID() == startBlockIndex)
			{
				foundID = true;
				currentIndex = i;
				break;
			}
			else
			{
				foundID = false;
			}
		}

		// If the ID is found
		if (foundID)
		{
			// Create temporary variable of char array being moved
			char* temp = new char[sz];
			temp = bufferPool[currentIndex]->getBlock();

			// Move down blocks from beginning to make space at the front of the list for LRU
			for (int i = currentIndex; i > 0; i--)
			{
				bufferPool[i] = bufferPool[i - 1];
			}

			// Set the first block to the temp block
			bufferPool[0] = new LRUBufferBlock(temp, BLOCKSIZE);
			bufferPool[0]->setID(startBlockIndex);
		}
		else // If it is not found
		{
			// Move down blocks from beginning to make space at the front of the list for LRU
			for (int i = POOL_SIZE - 1; i > 0; i--)
			{
				bufferPool[i] = bufferPool[i - 1];
			}

			// Reopen the file to get the new data not in the pool (redo of whats done in the constructor)
			fstream file;
			file.open(globalFileName.c_str(), fstream::in | fstream::binary);

			// Creating temp char array to hold the data
			file.seekg(startBlockIndex * BLOCKSIZE);
			char* data = getCharArray(BLOCKSIZE);

			file.read(data, BLOCKSIZE);

			// Instantiate the buffer block
			bufferPool[0] = new LRUBufferBlock(data, BLOCKSIZE);

			// Set the ID of the block
			bufferPool[0]->setID(startBlockIndex);
		}

		// Get the data from the end block
		bufferPool[0]->getData(pos % BLOCKSIZE, sz, space);
	}

	// Print the order of the buffer blocks using the block id numbers.
	void printBufferBlockOrder()
	{
		// Get the size of the buffer pool
		int size = sizeof(bufferPool) / sizeof(bufferPool[0]);

		// Print the order of the buffer blocks
		for (int i = 0; i < size; i++)
		{
			cout << bufferPool[i]->getID() << " ";
		}
		cout << endl;
	}

	// Get the block id number of the least recently used 
	//	 buffer block.
	int getLRUBlockID()
	{
		// Get the esize of the buffer pool
		int size = sizeof(bufferPool) / sizeof(bufferPool[0]);

		return bufferPool[size - 1]->getID();
	}
};