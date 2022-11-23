// LinkedList Test File

#include"LinkedList.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	LinkedList playlist;

	node *song1 = new node;
	song1->song = "Never Gonna Give You Up";
	song1->artist = "Rick Astley";

	node *song2 = new node;
	song2->song = "Party in the USA";
	song2->artist = "Miley Cyrus";

	node *song3 = new node;
	song3->song = "Wheels on the Bus";
	song3->artist = "Sming";

	playlist.insertNode(song1, 0);
	playlist.insertNode(song2, 1);
	playlist.printList();

	playlist.insertNode(song3, 1);
	playlist.printList();

	playlist.removeNode(2);
	playlist.printList();



	return 0;
}