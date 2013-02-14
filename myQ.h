#ifndef MYQ_H
#define MYQ_H

#include<iostream>
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
			while(head != 0)  {
				currentNode = head;
				head = head->next;
				delete currentNode;
			}
		};

		// queue methods
		bool pushBack(T* element);
		bool popFront(T* element);
		bool front(T* element);
		bool isEmpty();
		int length();	
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
			cout << "Hi there!" << endl;
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
	cout<<"popping front"<<endl;
	if(head != 0){
		cout<<"head isnt 0"<<endl;
		Node *de = head;
		cout<<" head dereferenced"<<endl;
		cout<<*element<<endl;
		cout<<"we printed"<<endl;
		cout<<de->data<<endl;
		cout<<"printeeeeed"<<endl;
		*element = de->data;
		cout<<"element dereferenced"<<endl;
		head = de->next;
		cout<<" head = head->next"<<endl;
		delete(de);
		l--;
		return true;
	}
	return false;
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
