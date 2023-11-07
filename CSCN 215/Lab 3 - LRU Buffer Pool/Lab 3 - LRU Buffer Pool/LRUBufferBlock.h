#pragma once

#include <iostream>
#include <string>
#include "BufferBlockADT.h"
#include "constants.h"

class LRUBufferBlock : public BufferblockADT
{
private:
	//Instance variables:
	int blockID;
	char* block;

public:
    //sz is the size of the character array data
    //points to.
    LRUBufferBlock() 
    {
        setID(0);
		block = new char[4096];
    }
    LRUBufferBlock(char* data, int sz = 4096) 
    {
        setID(0);
        //block = new char[4096];
        block = getCharArray(sz);

        // Copy the data into the block
        for (int i = 0; i < sz; i++)
		{
			block[i] = data[i];
		}
    }
    ~LRUBufferBlock() 
    {
       delete[] block;
    }

    //read the block to the end of the block
    void getData(int pos, int sz, char* data)
    {
        // Check if the overall position is within the bounds of the block
        for (int i = 0; (i < sz) && ((i + pos) % BLOCKSIZE != 0); i++)
        {
            data[i] = block[pos + i];
        }
    }

    //setID
    void setID(int id)
    {
        blockID = id;
    }

    //getID
    int getID() const
    {
        return blockID;
    }

    //getBlocksize
    int getBlockSize() const
    {
        return sizeof(block);
    }

    //return the block
    char* getBlock() const
    {
        return block;
    }

    //set the block
    void setBlock(char* blk)
    {
        block = blk;
    }
};