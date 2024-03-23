// Caretaker
#pragma once
#include "EditorState.h"
#include <vector>

// Define Message class
class History
{
public:
	// push
	void push(EditorState state)
	{
		states.push_back(state);
	}
	// pop
	EditorState pop()
	{
		EditorState state = states.back();
		states.pop_back();
		return state;
	}
private:
	// Vector of mementos (editorstates)
	std::vector<EditorState> states;
};