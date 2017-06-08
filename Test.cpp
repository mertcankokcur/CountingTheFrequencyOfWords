#include "Node.h"
#include "LinkedList.h"
#include "WordType.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

bool isItWrongCharacter(char c)
{
	if(( c >= 'A' && c <='Z') || (c >='a' && c <='z')) return true;
	else
		return false;
}

bool isExists(string str, vector <WordType> arr)
{
	bool flag=false;
	for(int i=0; i < (unsigned)arr.size(); i++)
	{
		if(arr[i].word==str)
		{
			flag=true;
			break;
		}
	}
	return flag;
	
}

void insert(string str, vector <WordType> & arr,LinkedList<WordType> list[])
{
	WordType word(str);
	int indx=str[0]-'a';

	if(isExists(str,arr))
	{
		list[indx].updateMember(word);
	}
	else
	{
		arr.push_back(word);
		list[indx].insertEnd(word);
	}
}

char toLower(char in)
{
	if(in <= 'Z' && in >='A')
		return in + 32;
	return in;
}
void main()
{
	LinkedList<WordType> list[26];
	vector<WordType> arr;
	fstream f;
	string temp;
	char c;

	f.open("input.txt");

	if(f.is_open())
	{
		while(!f.eof())
		{
			f.get(c);
			if(isItWrongCharacter(c))
			{
				c=toLower(c);
				temp.push_back(c);
			}
			else
			{
			if(temp[0]) insert(temp,arr,list);
				temp="";
			}
		}
		f.close();
	}
	remove("output.txt");
	for(int i=0; i < 26; i++)
	{
		list[i].print();
	}


}

