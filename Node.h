#ifndef _NODE_
#define _NODE_
#include <iostream>
//using namespace std;
template <class ElemType>
class Node
{
public:
	ElemType data;
	Node *next;
	Node(){next=NULL;}
	Node(const ElemType &e):data(e),next(NULL){}
};
#endif