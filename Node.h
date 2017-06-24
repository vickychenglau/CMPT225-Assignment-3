/*
 * Node.h - Header and Implementation of Node class
 * 
 * Class Description: A singly linked list Node
 * Class Invariant:
 *
 * Last modified on: June 23, 2017
 * Author: Jacky Tse, Vicky Lau
 */
 
#pragma once

#include <cstdio>  // Needed for NULL

using namespace std;


template <class ElementType>
class Node{

public:
	// Public attributes
	ElementType data;	// Public because more convienent than getters/setters 
	Node* next;			// Can't use -> notation with private I think

	// Constructors
	Node();
	Node(ElementType theData);
	Node(ElementType theData, Node* theNextNode);

}; // end Node header


// Start of implementation of methods

// Default Constructor
template <class ElementType>
Node<ElementType>::Node(){
	next = NULL;				// No data because type is not known
}

// Parameterized Constructor with data
template <class ElementType>
Node<ElementType>::Node(ElementType theData){
	data = theData;
	next = NULL;
}

// Parameterized Constructor with data and next
template <class ElementType>
Node<ElementType>::Node(ElementType theData, Node* theNextNode){
	data = theData;
	next = theNextNode;
}
// End of Node implementation

// End of Node.h