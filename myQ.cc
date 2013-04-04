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
				
		// operator overloads
		bool operator==(myQ<T> * other);
		T* operator[](int index);
		void operator = (myQ<T> * other);
		myQ<T>& operator+=(T* data);
		myQ<T>& operator-=(T* data);
		myQ<T>& operator-=(myQ<T>& other);
		myQ<T>& operator - (myQ<T>& other);
		myQ<T>& operator - (T* data);
		myQ<T>& operator+=(myQ<T>& other );
		bool operator>( myQ<T> * other);		
		bool operator<( myQ<T> * other);
		myQ<T>& operator + (myQ<T>& other);
		myQ<T>& operator + (T* data);
		void operator!();


		// que methods used by application
		void  print(int i);
		void pushBack(T*); //adds to tail.
    		void popFront(); //removes from head.
		T* front();
		T* back();
		bool isEmpty(); 
		int length();
		void deleteTail();
		void clear();	
		void save();

		// que test methods
		void  testFunc();

};


template<class T>
void myQ<T>:: testFunc(){
	myQ<T> intQ1;
	myQ<T> intQ2;
	myQ<T> intQ3;
	cout<<"adding 1-20 to q1"<<endl;
	for(int i=0; i<20;i++){
		int * intptr = new int(i+1);
		intQ1+=intptr;
	}
	intQ1.print(1);
	cout<<"adding 1-9 to q2 "<<endl;
	for(int i=0; i<9;i+=3){
		int* intptr1 = new int(i+1);
		int* intptr2 = new int(i+2);
		int* intptr3 = new int(i+3);
		intQ2+intptr1+intptr2+intptr3;
	}
	intQ2.print(2);
	cout<<"adding q2 to q1"<<endl;
	intQ1+= intQ2;
	intQ1.print(1);
	cout<<"adding q2 to q3"<<endl;
	intQ3+= intQ2;
	intQ3.print(3);
	cout<<"readding q2 to q1 and then adding q3"<<endl;
	intQ1+intQ2+intQ3;
	intQ1.print(1);
	cout<<"checking subscript operator on q1"<<endl;
	for(int i =0; i< intQ1.length();i++)
		cout<<*intQ1[i]<<",";
		cout<<endl;
	
	cout<<"removing 9 from q1"<<endl;
	intQ1-= intQ1[intQ1.length()-1];
	intQ1.print(1);
	cout<<"removing q2 from q1"<<endl;
	intQ1 -= intQ2;
	intQ1.print(1);
	cout<<"clearing q1 "<<endl;
	!intQ1;
	intQ1.print(1);
	cout<<"printing q2"<<endl;
	intQ2.print(2);
	cout<<"subtracting q2 from itself and then attempting to substract q3 from q2"<<endl;
	intQ2- intQ2 - intQ3;
	cout<<"printing q2"<<endl;
	intQ2.print(2);
	cout<<"printing q3"<<endl;
	intQ3.print(3);
	cout<<"substracting every element in q3 from q3"<<endl;
	while(!intQ3.isEmpty())
		intQ3 - intQ3.front();
	cout<<"priting q3"<<endl;
	intQ3.print(3);
	
	!intQ1;
	!intQ2;
	!intQ3;
	intQ1 - intQ2;
	int one = 1;
	int two = 2;
	intQ1+= &one;
	intQ2+&one+&two;
	intQ2.print(2);
	intQ1-= intQ2;
	intQ1.print(1);
	intQ2.deleteTail();
	intQ2.print(2);
	!intQ1;
	!intQ2;
	intQ2+&one+&two;
	intQ2.print(2);
	intQ2.deleteTail();
	intQ2.print(2);

}

template <class T>
bool myQ<T>::isEmpty()	{
	return (head == 0);
}

template <class T>
void myQ<T>::print(int i){
	cout<<"printing queue "<< i << ":";
	Node* dummy = head;
	while(dummy != 0){
		cout<<*(dummy->data)<<",";
		dummy= dummy->next;
	}
	cout<<endl<<endl;
}

template<class T>
int myQ<T>::length()	
{
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
void myQ<T>::pushBack(T* ele)	
{
	if(ele == 0) return;
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
void myQ<T>::popFront()
{
	if (isEmpty()){
		
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
	if(length() == 1)	{
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
	delete curr;
	tail = prev;
	tail->next = 0;	
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

//overloading the [] operator
template<class T>
T* myQ<T>::operator[](int i)
{
	Node *dummyNode;
	if(i < 0 ||i > length()){//Checking if the index i is within the bounds of the Queue
		cout<<"Index out of bounds Exception"<<endl;
		return 0;
	
	}
	else{
		int temp = 0;
		
		dummyNode = head;
		while(i != temp){
			dummyNode= dummyNode->next;	//Cycling through the nodes untill the desired index is reached.
			temp++;	
		}
		
	}
	return dummyNode->data;
}

template<class T>
myQ<T>& myQ<T>::operator+=(T *data)
{	if(data == 0) return *this;

	pushBack(data);
	return *this;
} 

template<class T>
myQ<T>& myQ<T>::operator+=(myQ<T>&  newQ){
	
	if(newQ.isEmpty()) return *this;	
	Node *temp;
	temp = newQ.head;	

	while(temp != 0){
		pushBack(temp->data);
		temp= temp->next;	
	}
	return *this;
}

template<class T>
myQ<T>& myQ<T>::operator-(T* data){
	Node currNode = 0;
	myQ<T>& newQ = new myQ<T>();

	currNode = head;
	while(currNode != 0)	{
		newQ += new Node(currNode->data);
		currNode = currNode->next;
	}

	if(data != 0)	newQ -= data;

	return newQ;
}

template<class T>
myQ<T>& myQ<T>::operator-(myQ<T>& other){
	Node currNode = 0;
	myQ<T>& newQ = new myQ<T>();

	currNode = head;
	while(currNode != 0)	{
		newQ += new Node(currNode->data);
		currNode = currNode->next;
	}

	newQ -= other;

	return newQ;
}

template<class T>
void myQ<T>::operator!(){
	while (! this->isEmpty())
			this->popFront();
}

template<class T>
myQ<T>& myQ<T>::operator-=(T* data)	{
	if(data == 0) return *this;
	if(head == 0) return *this;

	if(data == head->data){
		popFront();		
		return *this;
	}
	

	Node *curr,*prev;
	curr= head->next;
	prev = head;

	while(curr != 0){
		if((curr->data) == data){
			prev->next = curr->next; 
			if(curr == tail)	tail = prev;
			delete curr;
			return *this;
		}
		prev = curr;
		curr = curr->next;			
	}
	return *this;
}

template<class T>
myQ<T>& myQ<T>::operator-=(myQ<T>& other)	{
	if(other.head == 0) return *this;

	Node* cNode = other.head;
	while(cNode != 0){
		*this -= cNode->data;
		cNode = cNode->next;
	}
	return *this;
}

template<class T>
myQ<T>& myQ<T>::operator+(T* data)	{
	Node currNode = 0;
	myQ<T>& newQ = new myQ<T>();

	currNode = head;
	while(currNode != 0)	{
		newQ += new Node(currNode->data);
		currNode = currNode->next;
	}
	
	if(data != 0)	newQ += new Node(data);

	return newQ;
}

template<class T>
myQ<T>& myQ<T>::operator+(myQ<T>& newQ)	{
	Node currNode = 0;	
	myQ<T>& newestQ = new myQ<T>();

	currNode = head;
	while(currNode != 0)	{
		newestQ += new Node(currNode->data);
		currNode = currNode->next;
	}
	
	newestQ += newQ;

	return newestQ;
}

#endif
