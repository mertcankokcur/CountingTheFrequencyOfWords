#include <iostream>
#include "WordType.h"

using namespace std;
WordType::WordType(string str)
{
	word=str;
	count=1;
}

void WordType::setCounter()
{
	count++;
}
