// Linked List Header File

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#pragma once
#include<iostream>
#include<string>
using namespace std;

// Node contains the song info & what's next
//		Next song is currelty "nothing", until set laters
struct node
{
	string song;
	string artist;
	node *next = 0;
};

// Our playlist (linked list) contains a seris of nodes (songs)
class LinkedList
{
private:
	int listLength;
	node *head;
public:
	// Creates a new empy playlist
	LinkedList();

	// Insert a song at a position (false if position is invalid)
	bool insertNode(node *newNode, int position);

	// Remove a song at a position (falst if position is invalid)
	bool removeNode(int position);

	void printList();

	// Remove the playlist from memory (destructor)
	~LinkedList();
};

// Creates a new empy playlist
LinkedList::LinkedList()
{
	listLength = 0;
	head = nullptr;
}

bool LinkedList::insertNode(node *newNode, int position)
{
	// Check for invalid positions
	if (position < 0 || position > listLength + 1)
	{
		cout << "Error: invalid position" << endl;
		return false;
	}

	// Brand new list?
	if (head == nullptr)
	{
		listLength++;
		head = newNode;
		return true;
	}

	// Inserting a song into the list (except for the end)
	int count = 0;
	node *p = head;
	node *q = head;

	while (q)
	{
		if (count == position)
		{
			p->next = newNode;
			newNode->next = q;
			listLength++;
			return true;
		}

		p = q;
		q = p->next;
		count++;
	}

	if (count == position)
	{
		p->next = newNode;
		newNode->next = q;
		listLength++;
		return true;
	}

	return false;		// It should never get to this line
}

bool LinkedList::removeNode(int position)
{
	// Check for position errors
	if (position < 0 || position > listLength)
	{
		cout << "Error: position out of range" << endl;
		return false;
	}

	// If there are no songs, we can't remove any
	if (head->next == nullptr)
	{
		cout << "Error: no songs to remove" << endl;
		return false;
	}

	int count = 0;
	node *p = head;
	node *q = head;
	
	while (q)
	{
		if (count == position)
		{
			p->next = q->next;
			delete q;
			listLength--;
			return true;
		}

		p = q;
		q = p->next;
		count++;
	}

	return false;		// Never should get here
}

void LinkedList::printList()
{
	int count = 0;
	node *p = head;

	while (p != nullptr)
	{
		cout << "Track #" << count << endl;
		cout << p->song << " by " << p->artist << endl;
		count++;
		p = p->next;
	}

	cout << endl << endl;
}

LinkedList::~LinkedList()
{
	node *p = head;
	node *q = head;

	while (q)
	{
		p = q;
		q = p->next;
		if (q) delete p;
	}
}
#endif
