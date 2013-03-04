#ifndef MYQ_H
#define MYQ_H

#include <iostream>
using namespace std;

template <class T> class myQ {
	
	public:
		// inner node class
		class Node	{
			public:
				T* data;
				Node* next;
				
				Node() {
					next = 0;
					data = 0;
				}	
		};
		// instance variables
		Node *head;
		Node *tail;

		// constructor
		myQ() {  
		        head = 0;
			tail = 0;
		};

		// destructor
		~myQ()	{
			Node *currNode, *nextNode;

			currNode = head;
			while (currNode != 0) {
				nextNode = currNode->next;
				delete currNode;
				currNode = nextNode;
			}
		};

		// queue methods
		void pushBack(T*); //adds to tail
    		void popFront(); //removes from head
		T* front();
		T* back();
		bool isEmpty(); 
		int length();
		void deleteTail();
		void clear();	
		void save();

};

template <class T>
 bool myQ<T>::isEmpty()	{
	return (head == 0);
}

template<class T>
int myQ<T>::length()	{
	int counter = 0;
	Node* curr = 0;

	curr = head;
	while(curr != 0)	{
		counter++;
		curr = curr->next;
	}

	return counter;
}

template <class T>
T* myQ<T>::front()	{
	if (isEmpty())
		return 0;
	return (head->data);
}

template<class T>
void myQ<T>::pushBack(T* ele)	{
	Node* tmpNode = new Node;
  	tmpNode->data = ele;

	if (isEmpty())	{
		head = tmpNode;
	} else {
	  tail->next = tmpNode;
	}

	tail = tmpNode;
}

template <class T>
void myQ<T>::popFront(){
	if (isEmpty()) {
		return;
	}
	Node* newHead = head;
	head = head->next;
	delete newHead;
}

template<class T>
void myQ<T>::deleteTail()	{
	Node *curr = 0;
	Node *prev = 0;

	if(isEmpty()) return;
	cout << length() << endl;
	if(length() == 1)	{
		delete head->data;
		delete head;
		head = 0;
		tail = 0;
		return;
	}
	curr = head;
	while(curr->next != 0)	{
		prev = curr;
		curr = curr->next;
	}
	
	delete curr->data;
	delete curr;
	prev->next = 0;
	tail = prev;	
}

template<class T>
T* myQ<T>::back()	{
	if(!isEmpty())	return tail->data;
	return 0;
}

template<class T>
void myQ<T>::clear()	{
	Node* curr = 0;
	
	curr = head;
	while(curr != 0)	{
		delete curr->data;
		curr->data = 0;
		curr = curr->next;
	}
}

template<class T>
void myQ<T>::save()	{
	Node* curr = 0;

	curr = head;
	while(curr != 0)	{
		curr->data->save();
		curr = curr->next;
	}
}

#endif







