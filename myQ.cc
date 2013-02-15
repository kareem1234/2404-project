#ifndef MYQ_H
#define MYQ_H

#include <iostream>
using namespace std;
template <class T> class myQ {
	
	 public:
		// inner node class
		 class Node{
			public:
				T data;
				Node* next;
				Node(){
				  next = 0;
				}
				~Node(){
				  						
				}	
		};
		// instance variables
		Node *head;
		Node *tail;
		int l;

		// constructor
		myQ(){  
		        head = 0;
			tail = 0;
			l=0;
		};

		// destructor
		~myQ(){
			Node* currentNode = 0;
			cout<<"length is l: "<<l;
			while(head != 0)  {
				currentNode = head;
				head = head->next;
				//delete currentNode;
			}
		};

		// queue methods
		bool pushBack(T* element);
		bool popFront(T* element);
		bool front(T* element);
		bool isEmpty();
		int length();
		void deleteTail();	
		T* getTail();

};

template <class T>
 bool myQ<T>::isEmpty(){

	if(l == 0) return false;


	return true;
}

template<class T>
int myQ<T>::length(){
	return l;

}

template <class T>
bool myQ<T>::front(T* element){
	if(l == 0)return false;

	else *element = head->data;
	return true;
	

}
template<class T>
bool myQ<T>::pushBack(T* ele){
		if(head == 0){ // empty list
			head = new Node;
			head->data = *ele;
			l++;
			return true;
		}else if(tail == 0){ // tail not initialised
			tail = new Node;
			tail->data = *ele;
			head->next = tail;
			l++;
			return true;
			
		}else{ // add to back
			Node* newTail = new Node;
			newTail->data = *ele;
			tail->next = newTail;
			tail= newTail;
			l++;
			return true;

		}
	 return false;	
}

//
template <class T>
bool myQ<T>::popFront(T* element){
	if(head != 0){
		Node *de = head;
		*element = head->data;
		head = head->next;
		delete(de);
		de = 0;
		l--;
		if(l == 0){
			head = 0;
			tail = 0;
		}
		if(l==1){
			tail = 0;
			head->next = tail;
		}
		return true;
	}
	return false;
}

template<class T>
void myQ<T>::deleteTail()	{
	Node *current = 0;
	Node *prev = 0;

	if(l == 0)	return;

	current = head;
	while(current->next != 0)	{
		prev = current;
		current = current->next;
	}
	
	if(prev == 0)	{
		delete current;
		l--;
		head = 0;
		tail = 0;
	} else	{
		delete current;
		l--;
		prev->next = 0;
		if(l >= 2)	tail = prev;
		else	tail = 0;
	}
	
}

template<class T>
T* myQ<T>::getTail()	{
	if(tail != 0){
		return &(tail->data);
	}else if(head != 0 ){
			return &(head->data);
	}
	
	return 0;

}

#endif
