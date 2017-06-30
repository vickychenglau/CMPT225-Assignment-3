/*
 * Customer.h - Header of Customer class
 * 
 * Class Description: Contains information about the type of customer event (is it Arrival or Depature),
 *					  If Arrival Event, then has the time of the arrival and length of transaction
 *					  If Departure Event, then has the time of the departure and length set to 0
 * Class Invariant: Type is always A, D, or None. Time and Length is always >= 0.
 *
 * Last modified on: June 30, 2017
 * Author: Jacky Tse, Vicky Lau
 */
 
#pragma once

#include <string>

using namespace std;


class Customer{

private:
	string type;
	unsigned int time;
	unsigned int length;

public:
	// Default Constructor
	// Description: Created a customer with no type and time and length of 0
	// Postcondition: Type is set to "None", the rest is set to 0.
	Customer();

	// Parameterized Constructor
	// Description: Created a customer with the indicated parameters
	// Postcondition: If type is not A or D, set to "None"
	//				  Time is set to theTime
	//				  Length is set to theLength unless type is D, in which length = 0.
	Customer(string theType, 
			 unsigned int theTime, 
			 unsigned int theLength);

	// Description: Returns the type
	string getType() const;

	// Description: Returns the time
	unsigned int getTime() const;

	// Description: Returns the Length
	unsigned int getLength() const;

	// Description: Sets type to theType
	void setType(string theType);

	// Description: Sets time to theTime
	void setTime(unsigned int theTime);

	// Description: Sets length to theLength
	void setLength(unsigned int theLength);

	// Description: Comparison operator. Compares "this" Customer object with "rhs" Customer object.
	//				Returns true if time of "this" Customer object is the same as the time of "rhs" Customer object.
	bool operator==(const Customer & rhs);

	// Description: Comparison operator. Compares "this" Customer object with "rhs" Customer object.
	//				Returns true if time of "this" Customer object is > than the time of "rhs" Customer object.
	bool operator>(const Customer & rhs);

	// Description: Comparison operator. Compares "this" Customer object with "rhs" Customer object.
	//				Returns true if time of "this" Customer object is < than the time of "rhs" Customer object.
	bool operator<(const Customer & rhs);

	// Description: Comparison operator. Compares "this" Customer object with "rhs" Customer object.
	//				Returns true if time of "this" Customer object is >= than the time of "rhs" Customer object.
	bool operator>=(const Customer & rhs);

	// Description: Comparison operator. Compares "this" Customer object with "rhs" Customer object.
	//				Returns true if time of "this" Customer object is <= than the time of "rhs" Customer object.
	bool operator<=(const Customer & rhs);

	// Description: Prints the content of "this".
	friend ostream & operator<<(ostream & os, const Customer & p);
}; 

// end Customer.h