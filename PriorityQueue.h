/*
 * PriorityQueue.h - Header of PriorityQueue class
 * 
 * Class Description: A Linked List implimentation of a FIFO/LILO 
 *                    priority queue
 * Class Invariant:           
 *
 * Last modified on: June 23, 2017
 * Author: Jacky Tse, Vicky Lau
 */

#pragma once

#include <cstdio>  // Needed for NULL
#include <string>
#include <iostream>
#include "Node.h"
#include "EmptyDataCollectionException.h"

using namespace std; // Needed for cout, cin to be recognized


template <class ElementType>
class PriorityQueue {

private:
   int elementCount;
   Node<ElementType>* head;
   Node<ElementType>* tail;

// We must complete this section.  
 
public:

// Let's put our constructor(s) and destructor (if any) ***here***.
   PriorityQueue();

   ~PriorityQueue();

/******* Public Interface - START - *******/
        
   // Description: Returns the number of elements in the Priority Queue.
   // (This method eases testing.)
   // Time Efficiency: O(1) 
   int getElementCount() const;   
   
   // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;
    
   // Description: Inserts newElement in sort order.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is sorted.   
   // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.    
   // Time Efficiency: O(n)        
   bool enqueue(const ElementType& newElement);
      
   // Description: Removes the element with the "highest" priority.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is not empty.
   // Time Efficiency: O(1) 
   bool dequeue();
    
   // Description: Returns (a copy of) the element with the "highest" priority.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1) 
   ElementType peek() const throw(EmptyDataCollectionException);

   // Description: Prints all the data in priority queue.
   void printPriorityQueue();
   
/******* Public Interface - END - *******/

// Let's feel free to add other private helper methods to our Priority Queue class.   

}; // End of PriorityQueue Header


// Start of implementation of methods


// Default Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(){
   elementCount = 0;
   head = NULL;
   tail = NULL;
}
        
// Description: Returns the number of elements in the Priority Queue.
// (This method eases testing.)
// Time Efficiency: O(1) 
template <class ElementType>
int PriorityQueue<ElementType>::getElementCount() const{
   return(elementCount);
} 
   
// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const{
   if(getElementCount() == 0){
      return(true);
   }

   return(false);
}
    
// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.   
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.    
// Time Efficiency: O(n)
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(const ElementType& newElement){
   Node<ElementType> *newNode = new Node<ElementType>(newElement);

   if(head == NULL){
      head = newNode;
      tail = newNode;
   }
   else if(newNode >= head){  // Higher priority goes in front
      newNode->next = head;
      head = newNode;
   }
   else{
      Node<ElementType> *current = head;
      bool inserted = false;

      while(current != tail){
         if(newNode <= current && newNode >= current->next){
            newNode->next = current->next;
            current->next = newNode;
            inserted = true;
         }
         else{
            current = current->next;
         }
      }

      if(inserted == false){
         tail->next = newNode;
         tail = newNode;
      }
   }

   elementCount++;

   return(true);
}
      
// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
// Time Efficiency: O(1) 
template <class ElementType>
bool PriorityQueue<ElementType>::dequeue(){
   Node<ElementType>* current = head;
   head = head->next;
   delete current;

   elementCount--;

   return(true);
}
    
// Description: Returns (a copy of) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1) 
template <class ElementType>
ElementType PriorityQueue<ElementType>::peek() const throw(EmptyDataCollectionException){
   if (isEmpty()){
      throw EmptyDataCollectionException("peek() called with empty priority queue.");
   }

   return(head->data);
}

template <class ElementType>
void PriorityQueue<ElementType>::printPriorityQueue(){
   Node<ElementType>* current = head;

   while(current != NULL){
      cout << current->data << ", ";
      current = current->next;
   }
}
// End of PriorityQueue Implementation

// End of PriorityQueue.h