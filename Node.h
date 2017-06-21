/******
Node class for out linked List queue


******/
#include "Customers.h"
#pragma once

class Node{
private:
	int data;
	Node* next;

public:
	Node();
	Node(int thedata);
	Node(int thedata, Node* theNextNode);

	setNodeData(int thedata);
	setNodeNext(Node* theNextNode);

	getNodeData(int thedata);
	getNodeNext(Node* theNextNode);

}; //end Node