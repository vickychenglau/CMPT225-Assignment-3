/*
 * SimulationApp.cpp
 * 
 * Class Description: Simulates a line up with one teller.
 *					  Calculates the average wait time for each customer.
 *
 * Last modified on: June 24, 2017
 * Author: Jacky Tse, Vicky Lau
 */

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Customer.h"
#include "Queue.h"
#include "PriorityQueue.h"

using namespace std;


int main(void){
	// Initializing variables

	string aLine;

	Queue<Customer> *bankLine = new Queue<Customer>();

	PriorityQueue<Customer> *eventPriorityQueue = new PriorityQueue<Customer>();

	Customer *newEvent = NULL;

	unsigned int time 	  		 = 0;
	unsigned int length   		 = 0;
	unsigned int departureTime   = 0;
	unsigned int currentTime     = 0;
	unsigned int numOfCustomers  = 0;

	float totalWaitTime = 0.0;
	float averageWaitTime = 0.0;

	bool tellerAvailable = true;


	cout << "Simulation Begins" << endl;

/******************************************************
	try{
		cout << "Peeking before enqueuing:" << endl;
		*newEvent = eventPriorityQueue->peek();
		((cout << "Now, let's have a look at the peeked Customer:")<< newEvent )<< endl;  
		}catch(EmptyDataCollectionException&anException){
		cout << "peeking() unsuccessful because " << anException.what() << endl;
		// Place recovery code here!
		}

******************************************************/

	// Create and add arrival events to event queue
	while(getline(cin >> ws, aLine)){   // while (there is data)
      	stringstream ss(aLine);
      	ss >> time >> length;

      	// Arrival Customer created
      	newEvent = new Customer("A", time, length);

      	if (!eventPriorityQueue->enqueue(*newEvent)){
        	return(1);
      	}

      	numOfCustomers++;
    }

/**************************************************
    try{
		cout << "Peeking before Processing events:" << endl;
		*newEvent = eventPriorityQueue->peek();
		((cout << "Now, let's have a look at the peeked Customer:")<< newEvent )<< endl;  
		}catch(EmptyDataCollectionException&anException){
		cout << "peeking() unsuccessful because " << anException.what() << endl;
		// Place recovery code here!
		}
**************************************************/

    // Event loop
    while(!eventPriorityQueue->isEmpty()){
    	try{
      		*newEvent = eventPriorityQueue->peek();
      	}catch(EmptyDataCollectionException&anException){
			cout << "peeking() unsuccessful because " << anException.what() << endl;
		}

      	// Calculates current time
      	currentTime = newEvent->getTime();

      	// Process an Arrival Event
      	if(newEvent->getType() == "A"){
      		cout << "Processing an arrival event at time:   " << setw(2) << right << currentTime << endl;

      		eventPriorityQueue->dequeue();

			if(bankLine->isEmpty() && tellerAvailable){
				departureTime = currentTime + newEvent->getLength();

				// Departing Customer created since at the teller
				newEvent = new Customer("D", departureTime, 0);

				// Adds a Departure Event to the Priority Queue
				if(!eventPriorityQueue->enqueue(*newEvent)){
					return(1);
				}

				tellerAvailable = false;
			}
			else{
				if(!bankLine->enqueue(*newEvent)){
					return(1);
				}
			}
		}
		// Process a Departure Event
      	else{
      		cout << "Processing a departure event at time:  " << setw(2) << right << currentTime << endl;

      		eventPriorityQueue->dequeue();

      		if(!bankLine->isEmpty()){
      			// Customer at front of line begins transaction
      			try{
      				*newEvent = bankLine->peek();
      			}catch(EmptyDataCollectionException&anException){
					cout << "peeking() unsuccessful because " << anException.what() << endl;
				}

      			totalWaitTime += (currentTime - newEvent->getTime());

      			bankLine->dequeue();

      			departureTime = currentTime + newEvent->getLength();
      			newEvent      = new Customer("D", departureTime, 0);

      			if(!eventPriorityQueue->enqueue(*newEvent)){
      				return(1);
      			}
      		}
      		else{
      			tellerAvailable = true;
      		}
      	}
    }

    averageWaitTime = totalWaitTime/numOfCustomers;

	cout << "Simulation Ends" << endl << endl;

	cout << "Final Statistics:" << endl;
	cout << "	Total number of people processed: " << numOfCustomers << endl;
	cout << "	Average amount of time spent waiting: " 
		 << averageWaitTime << endl;

	return(0);
}