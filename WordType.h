#pragma once

#include <iostream>
#include <string>
using namespace std;
class WordType
{
public:

	string word;
	int count;
	WordType(string);
	void setCounter();
	bool operator == (WordType sec)
	{
		if(word==sec.word) return true;
		return false;
	}
};

