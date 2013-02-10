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
			if(head != 0){
			 	currentNode= head->next;
				delete(head);
				while(currentNode != 0){
					head = currentNode;
					currentNode = head->next;
					delete(head);
			}
                    }
		};

		// queue methods
		bool pushBack(T element);
		bool popFront(T* element);
		bool front(T* element);
		bool isEmpty();
		int length();	

};

template <class T>
 bool myQ<T>::isEmpty(){

	if( l== 0) return false;


	return true;
}

template<class T>
int myQ<T>:: length(){
	return l;

}

template <class T>
bool myQ<T>::front(T* element){
	if(l == 0)return false;

	else *element = head->data;
	return true;
	

}
template<class T>
bool myQ<T>::pushBack(T ele){
	if(true){
		
		if(head == 0){ // empty list
			head = new Node;
			head->data = ele;
			l++;
			return true;
		}else if(tail == 0){ // tail not initialised
			tail = new Node;
			tail->data = ele;
			head->next = tail;
			l++;
			return true;
			
		}else{ // add to back
			Node* newTail = new Node;
			newTail->data = ele;
			tail->next = newTail;
			tail= newTail;
			l++;
			return true;

		}
	}
	 return false;	
}

//
template <class T>
bool myQ<T>::popFront(T* element){
	if(head != 0){
		Node *de = head;
		*element = de->data;
		head = de->next;
		delete(de);
		l--;
		return true;
	}
	return false;
}



