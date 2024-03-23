// Originator
#pragma once

#include <string>
#include "EditorState.h"

class Editor
{
public:
	// createState()
	EditorState createState()
	{
		return EditorState(content);
	}

	// restore()
	void restore(EditorState state)
	{
		content = state.getContent();
	}

	// Set content
	void setContent(std::string content)
	{
		this->content = content;
	}

	// Get content
	std::string getContent()
	{
		return content;
	}

private:
	std::string content;
};
