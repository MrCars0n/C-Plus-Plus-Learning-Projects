#include "Editor.h"
#include "History.h"
#include <iostream>

using namespace std;

int main()
{
	Editor editor;
	History history;

	editor.setContent("a");
	history.push(editor.createState());
	cout << editor.getContent() << endl;

	editor.setContent("b");
	history.push(editor.createState());
	cout << editor.getContent() << endl;

	editor.setContent("c");
	cout << editor.getContent() << endl;
	editor.restore(history.pop());
	cout << editor.getContent() << endl;
	editor.restore(history.pop());

	cout << editor.getContent() << endl;

	return 0;
}