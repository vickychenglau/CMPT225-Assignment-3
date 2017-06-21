#include "Queue.h"
#include <string>
#include <iostream>

using namespace std; // Needed for cout, cin to be recognized

//Default Queue
Queue::Queue(){
	elementCount = 0;
	head = NULL;
	tail = NULL;
}

int Queue::getElementCount(){

	return(elementCount);

}

bool Queue::isEmpty(){
	if(getElementCount() == 0)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

///!!!!!!!!!!!!!!!!!!!!!!!FOR NOW IT IS INT REMEMBER TO CHANGE BACK TO ORIGINAL!!!!!!!!!!!!!!!!!!!!!!?????/////
//bool Queue::enqueue(const ElementType& newElement)
bool Queue::enqueue(const int newElement){
	Node *newNode = new Node(newElement);
	
	if(head == NULL){		//For the case it is empty
		head = newNode;
		tail = newNode;
	}
	else{
		tail->next = newNode;	//Inserting at the end of LL
		tail = newNode;			//updating tail
	}
}

bool Queue::dequeue()
{
	Node* current = head;
	head = head->next;
	delete current;
}

//Not doing peek cause dont know execptions yet...