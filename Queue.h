/*
 * Queue.h - Header and Implementation of Queue class
 * 
 * Class Description: A Linked List implimentation of a FIFO/LILO queue
 * Class Invariant: FIFO/LILO
 *
 * Last modified on: June 30, 2017
 * Author: Jacky Tse, Vicky Lau
 */

#pragma once

#include <cstdio>  // Needed for NULL
#include <string>
#include <iostream>
#include "Node.h"
#include "Customer.h"
#include "EmptyDataCollectionException.h"

using namespace std; // Needed for cout, cin to be recognized


template <class ElementType>
class Queue {

private:
   int elementCount;
   Node<ElementType>* head;
   Node<ElementType>* tail;

// We must complete this section.

public:

// Let's put our constructor(s) and destructor (if any) ***here***.

   Queue();

   ~Queue();

/******* Public Interface - START - *******/
        
   // Description: Returns the number of elements in the Queue.
   // (This method eases testing.)
   // Time Efficiency: O(1)
   int getElementCount() const;

   // Description: Returns "true" is this Queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;
   
   // Description: Adds newElement to the "back" of this Queue 
   //              (not necessarily the "back" of its data structure) and 
   //              returns "true" if successful, otherwise "false".
   // Time Efficiency: O(1)

 ////????!!!!!!!!!!!!!!!!!!!!!!!!!!???????????? REMEMBER TO CHANGE BACK TO ORIGINAL IMPLIMENTATION
   //bool enqueue(const ElementType& newElement);
   bool enqueue(const ElementType& newElement);
   
   // Description: Removes the element at the "front" of this Queue 
   //              (not necessarily the "front" of its data structure) and  
   //              returns "true" if successful, otherwise "false".
   // Precondition: This Queue is not empty.
   // Time Efficiency: O(1)
   bool dequeue();
   
   // Description: Returns (a copy of) the element located at the "front" of this Queue.
   // Precondition: This Queue is not empty.
   // Postcondition: This Queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
   // Time Efficiency: O(1)
   ElementType peek() const throw(EmptyDataCollectionException);

   // Prints all the data in queue.
   void printQueue();
 
/******* Public Interface - END - *******/

// Let's feel free to add other private helper methods to our Queue class.
      
}; // end Queue Header


// Start of implementation of methods


//Default Constructor
template <class ElementType>
Queue<ElementType>::Queue(){
   elementCount = 0;
   head = NULL;
   tail = NULL;
}

//Deconstructor
template <class ElementType>
Queue<ElementType>::~Queue(){
   Node<ElementType> *previous = head;
   Node<ElementType> *current = head;

   while(current != NULL){
      previous = current;
      current = current->next;
      delete previous;
   }
}

// Description: Returns the number of elements in the Queue.
// (This method eases testing.)
// Time Efficiency: O(1)
template <class ElementType>
int Queue<ElementType>::getElementCount() const{
   return(elementCount);
}

// Description: Returns "true" is this Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const{
   if(getElementCount() == 0){
      return(true);
   }

   return(false);
}

// Description: Adds newElement to the "back" of this Queue 
//              (not necessarily the "back" of its data structure) and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::enqueue(const ElementType& newElement){
   Node<ElementType> *newNode = new Node<ElementType>(newElement);
   
   if(head == NULL){    //For the case it is empty
      head = newNode;
      tail = newNode;
   }
   else{
      tail->next = newNode;   //Inserting at the end of LL
      tail = newNode;         //updating tail
   }

   elementCount++;

   return(true);
}

// Description: Removes the element at the "front" of this Queue 
//              (not necessarily the "front" of its data structure) and  
//              returns "true" if successful, otherwise "false".
// Precondition: This Queue is not empty.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::dequeue(){
   if(isEmpty()){
      return(false);
   }

   Node<ElementType>* current = head;

   if(head == tail){
      head = NULL;
      tail = NULL;
   }
   else{
      head = head->next;
   }

   delete current;

   elementCount--;

   return(true);
}

// Description: Returns (a copy of) the element located at the "front" of this Queue.
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType Queue<ElementType>::peek() const throw(EmptyDataCollectionException){
   if(isEmpty()){
      throw EmptyDataCollectionException("peek() called with empty queue.");
   }

   return(head->data);
}

// Prints all the data in queue.
template <class ElementType>
void Queue<ElementType>::printQueue(){
   Node<ElementType> *current = head;

   while(current != NULL){
      cout << current->data;
      current = current->next;
   }
}

// End of Queue Implementation

// End of Queue.h
