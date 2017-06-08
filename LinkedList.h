#ifndef _LINKEDLIST_
#define _LINKEDLIST_
#include "Node.h"
#include <iostream>
#include <fstream>
using namespace std;
template <class ElemType>
class LinkedList
{
private:
	Node<ElemType> *head;
	int numberOfItems;
public:
	
	
	//problems solved during lecture hours

	
	LinkedList() :head(NULL), numberOfItems(0)
	{

	}
	
	bool isEmpty()const { return head == NULL; }
	bool isFull()const { return false; }
	bool LisMember(const ElemType &key)const
	{
		Node<ElemType> *walk = head;
		while (walk != NULL)
		{
			if (walk->data == key)
				return true;
			walk = walk->next;
		}
		return false;
	}
	void updateMember(const ElemType &key)const
	{
		Node<ElemType> *walk=head;
		while(walk!=NULL)
		{
			if(walk->data==key)
			{
				walk->data.setCounter();	
				return;
			}
			walk=walk->next;
		}
	}

	int indexOf(const ElemType &key)const
	{
		Node<ElemType> *walk = head;
		int index = -1;
		while (walk != NULL)
		{
			if (walk->data == key)
				return index;
			walk = walk->next;
			index++;
		}
		return -1;
	}

	int getSize() const
	{
		return numberOfItems;
	}

	
	void insertFront(const ElemType &e)
	{
		Node<ElemType> *t = new Node<ElemType>(e);
		t->next = head;
		head = t;
		numberOfItems++;
	}

	
	void insertEnd(const ElemType &e)
	{
		Node<ElemType> *t = new Node<ElemType>(e);
		Node<ElemType> *walk = head;
		if (head == NULL)
			head = t;
		else
		{
			while (walk->next != NULL)
			{
				walk = walk->next;
			}
			walk->next = t;
		}
		numberOfItems++;
	}

	
	void insertAt(const ElemType &e, int pos)
	{
		if (head != NULL)
		{
			if (pos >= 0 && pos <= numberOfItems)
			{
				Node<ElemType> *t = new Node<ElemType>(e);
				if (pos == 0)//insert to front
				{
					t->next = head;
					head = t;
				}
				else
				{
					Node<ElemType> *prev = head;
					Node<ElemType> *walk = head->next;
					int cnt = 1;
					while (walk != NULL && cnt<pos)
					{
						prev = walk;
						walk = walk->next;
					}
					prev->next = t;
					t->next = walk;
					numberOfItems++;
				}

			}
		}
	}

	void deleteFront()
	{
		if (head != NULL)
		{
			Node<ElemType> *old = head;
			head = head->next;
			delete old;
			numberOfItems--;
		}
	}

	
	void delteEnd()
	{
		if (head != NULL)
		{
			if (head->next == NULL)
			{
				delete head;
				head = NULL;
			}
			else
			{
				Node<ElemType> *walk = head->next;
				Node<ElemType> *prev = head;
				while (walk->next != NULL)
				{
					prev = walk;
					walk = walk->next;
				}
				prev->next = walk->next;
				delete walk;
			}
			numberOfItems--;
		}
	}
	//this method removes a node located at pos
	//pre condition: linked list is not empty, pos is positive value btween 0 and numberOfItems.  The node pointed by head is 0th node
	
	void deleteAt(int pos)
	{
		if (head != NULL)
		{
			if (pos >= 0 && pos < numberOfItems)
			{
				if (pos == 0) //
				{
					Node<ElemType> *old = head;
					head = head->next;
					delete old;
				}
				else
				{
					Node<ElemType> *prev = head;
					Node<ElemType> *walk = head->next;//walk will be pointing the node to be deleted
					int cnt = 1; //we have already checked 0th node, therefore start with 1
					while (walk != NULL && cnt < pos)//traverse until cnt becomes equal to pos
					{
						cnt++;
						prev = walk;
						walk = walk->next;
					}
					//remove node pointed by walk
					prev->next = walk->next;
					delete walk;
				}
				numberOfItems--;
			}
		}
	}

	
	void remove(const ElemType& key)
	{
		if (head != NULL)
		{
			if (key == head->data) //check if the key in the first node, => remove first
			{
				Node<ElemType> *old = head;
				head = head->next;
				delete old;
				numberOfItems--;
			}
			else //key might be in rest of the linked list, keep looking for until the end of linked list
			{
				Node<ElemType> *prev = head;
				Node<ElemType> *walk = head->next;
				while (walk != NULL)
				{
					prev = walk;
					walk = walk->next;
				}
				//walk becomes NULL if the key is not in any of nodes
				if (walk != NULL) {
					prev->next = walk->next;
					delete walk;
					numberOfItems--;
				}
			}
		}
	}

	
	const ElemType & getFirst()const
	{
		if (head != NULL)
			return head->data;
		exit(0);
	}

	
	const ElemType & getLast()const
	{
		if (head != NULL)
		{
			if (head->next == NULL)
			{
				return head->data;
			}
			else {
				Node<ElemType> *walk = head->next;
				while (walk->next != NULL)
				{
					walk = walk->next;
				}
				return walk->data;
			}
		}
		else
			exit(0);
	}

	
	const ElemType & itemAt(int pos)const
	{
		if (head != NULL)
		{
			if (pos >= 0 && pos < numberOfItems)
			{
				if (pos == 0) //
				{
					return head->data;
				}
				else
				{
					Node<ElemType> *prev = head;
					Node<ElemType> *walk = head->next;//walk will be pointing the node to be deleted
					int cnt = 1; //we have already checked 0th node, therefore start with 1
					while (walk != NULL && cnt < pos)//traverse until cnt becomes equal to pos
					{
						cnt++;
						prev = walk;
						walk = walk->next;
					}
					//remove node pointed by walk
					return walk->data;
				}
			}
		}
	}

	
	void print()const
	{
		Node<ElemType> *walk = head;
		ofstream file;

		file.open("output.txt", std::ios_base::app);
		while (walk != NULL)
		{
			file << walk->data.word << "   " << walk ->data.count << endl;
			walk = walk->next;
		}
		file.close();
	}

	
	const ElemType & getMin() const
	{
		if (head == NULL) //if linked list is empty nothing to return just terminate the program execution.  To do: more elegant implementaion with exection is required
			exit(0);
		Node<ElemType> *nodeMin = head;
		Node<ElemType> *walk = head->next;
		while (walk != NULL)
		{
			if (walk->data < nodeMin->data)
				nodeMin = walk;
			walk = walk->next;
		}
		return nodeMin->data;
	}

	
	void deleteMin()
	{
		if (head != NULL)
		{
			if (head->next == NULL)//if there is only one 
			{
				delete head;
				head = NULL;
				numberOfItems--;
			}
			else
			{
				Node<ElemType> *nodeMin, *prevMin;
				Node<ElemType> *walk, *prev;
				nodeMin = head;
				prevMin = NULL;
				prev = head;
				walk = head->next;
				while (walk != NULL)
				{
					if (nodeMin->data > walk->data)
					{
						prevMin = prev;
						nodeMin = walk;
					}
					prev = walk;
					walk = walk->next;
				}
				if (nodeMin == head)//if the minimum element is in node poited by head apply remove first algorithm
				{
					Node *old = head;
					head = head->next;
					delete head;
				}
				else
				{
					prevMin->next = nodeMin->next;
					delete nodeMin;
				}
				numberOfItems--;
			}
		}
	}
	LinkedList sum(LinkedList l1, LinkedList l2)
	{
		LinkedList res;
		int carry, digit, total;
		Node <ElemType> *walk, *w1=l1.head, *w2=l2.head;
		total=(w1!=NULL?w1->data:0)+(w2!=NULL?w2->data:0);
		digit = total % 10;
		carry = total / 10;
		if (total > 0)
			res.head = new Node<ElemType>(total);
		else
			return res;
		walk = res.head;
		w1 = (w1 != NULL ? w1->next : w1);
		w2 = (w2 != NULL ? w2->next : w2);
		while (w1 != NULL || w2 != NULL)
		{
			total=carry+ (w1 != NULL ? w1->data : 0) + (w2 != NULL ? w2->data : 0);
			digit = total % 10;
			carry = total / 10;
			walk->next = new Node<ElemType>(digit);
			walk = walk->next;
			w1 = (w1 != NULL ? w1->next : w1);
			w2 = (w2 != NULL ? w2->next : w2);
		}
		if(carry>0)
			walk->next= new Node<ElemType>(carry);
		return res;
	}

};


#endif
