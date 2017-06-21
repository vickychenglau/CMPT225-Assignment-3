#include <node.h>
/*****
	Description: A Linked List implimentation of a queue

*****/

class Queue {

private:
	int elementCount;
	Node* head;
	Node* tail;

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
   bool enqueue(const int newElement);
   
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
 
/******* Public Interface - END - *******/

// Let's feel free to add other private helper methods to our Queue class.
      
}; // end Queue
