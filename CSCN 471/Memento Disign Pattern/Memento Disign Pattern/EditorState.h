// Memento
#pragma once

#include <string>

class EditorState
{
public:
	// setContent()
	EditorState(std::string content)
	{
		this->content = content;
	}
	// getContent()
	std::string getContent()
	{
		return content;
	}
private:
	std::string content;
};