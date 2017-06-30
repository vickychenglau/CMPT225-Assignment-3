/*
 * SimulationApp.cpp
 * 
 * Class Description: Simulates a line up with one teller.
 *					  Calculates the average wait time for each customer.
 *					  Also outputs the number of customers and the time of each
 *					  customer's arrival/departure in order.
 *
 * Last modified on: June 30, 2017
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

	Customer newEvent;

	Queue<Customer> *bankLine = new Queue<Customer>();
	PriorityQueue<Customer> *eventPriorityQueue = new PriorityQueue<Customer>();

	unsigned int time 	  		= 0;
	unsigned int length   		= 0;
	unsigned int departureTime  = 0;
	unsigned int currentTime    = 0;
	unsigned int numOfCustomers = 0;

	float totalWaitTime   = 0.0;
	float averageWaitTime = 0.0;

	bool tellerAvailable = true;


	cout << "Simulation Begins" << endl;

/******************************************************
	try{
		cout << "Peeking before enqueuing:" << endl;
		newEvent = eventPriorityQueue->peek();
		((cout << "Now, let's have a look at the peeked Customer:")<< newEvent )<< endl;  
	}
	catch(EmptyDataCollectionException&anException){
		cout << "peeking() unsuccessful because " << anException.what() << endl;
		// Place recovery code here!
		}

******************************************************/

	// Create and add arrival events to event queue
	while(getline(cin >> ws, aLine)){   // while (there is data)
      	stringstream ss(aLine);
      	ss >> time >> length;

      	// Arrival Customer created
      	newEvent = Customer("A", time, length);

      	if (!eventPriorityQueue->enqueue(newEvent)){
        	return(1);
      	}

      	numOfCustomers++;
    }

/**************************************************
    try{
		cout << "Peeking before Processing events:" << endl;
		newEvent = eventPriorityQueue->peek();
		((cout << "Now, let's have a look at the peeked Customer:")<< newEvent )<< endl;  
	}
	catch(EmptyDataCollectionException&anException){
		cout << "peeking() unsuccessful because " << anException.what() << endl;
		// Place recovery code here!
	}
**************************************************/

    // Event loop
    while(!eventPriorityQueue->isEmpty()){
    	try{
      		newEvent = eventPriorityQueue->peek();
      	}
      	catch(EmptyDataCollectionException&anException){
			cout << "peeking() unsuccessful because " << anException.what() << endl;
		}

      	// Calculates current time
      	currentTime = newEvent.getTime();

      	// Process an Arrival Event
      	if(newEvent.getType() == "A"){
      		cout << "Processing an arrival event at time:   " << setw(2) << right 
      			 << currentTime << endl;

      		if(!eventPriorityQueue->dequeue()){
      			return(1);
      		}

      		// Customer dooesn't line up and goes directly to teller
			if(bankLine->isEmpty() && tellerAvailable){

				departureTime = currentTime + newEvent.getLength();

				// Departing Customer created since at the teller
				newEvent = Customer("D", departureTime, 0);

				// Adds a Departure Event to the Priority Queue
				if(!eventPriorityQueue->enqueue(newEvent)){
					return(1);
				}

				tellerAvailable = false;
			}
			// Customer lines up
			else{
				if(!bankLine->enqueue(newEvent)){
					return(1);
				}
			}
		}
		// Process a Departure Event
      	else{
      		cout << "Processing a departure event at time:  " << setw(2) << right 
      			 << currentTime << endl;

      		// Dequeuing a departure event since customer is leaving
      		if(!eventPriorityQueue->dequeue()){
      			return(1);
      		}

      		// Enqueues the leaving customer into a delete queue
      		// since deleting here causes a segmentation fault

      		if(!bankLine->isEmpty()){
      			// Customer at front of line begins transaction
      			try{
      				newEvent = bankLine->peek();
      			}
      			catch(EmptyDataCollectionException&anException){
					cout << "peeking() unsuccessful because " << anException.what() << endl;
				}

      			totalWaitTime += (currentTime - newEvent.getTime());

      			if(!bankLine->dequeue()){
      				return(1);
      			}

      			departureTime = currentTime + newEvent.getLength();

				// Next customer's departing event
      			newEvent = Customer("D", departureTime, 0);

      			if(!eventPriorityQueue->enqueue(newEvent)){
      				return(1);
      			}
      		}
      		else{
      			tellerAvailable = true;
      		}
      	}
    }

	cout << "Simulation Ends" << endl << endl;


	averageWaitTime = totalWaitTime / numOfCustomers;

	cout << "Final Statistics:" << endl;
	cout << "	Total number of people processed:  " << numOfCustomers << endl;
	cout << "	Average amount of time spent waiting: " 
		 << averageWaitTime << endl;

	delete bankLine;
	delete eventPriorityQueue;

	return(0);
}