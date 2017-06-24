/*
 * Customer.cpp - Implementation of Customer class
 * 
 * Class Description: Contains information about the arrival/departure time
 *					  of the customers, as well as their length of stay
 * Class Invariant:
 *
 * Last modified on: June 23, 2017
 * Author: Jacky Tse, Vicky Lau
 */

#include <string>
#include "Customer.h"

using namespace std;


// Default Constructor
// Description: Created a customer with no type and time and length of 0
// Postcondition: Type is set to "None", the rest is set to 0.
Customer::Customer(){
	type   = "None";
	time   = 0;
	length = 0;
}

// Parameterized Constructor
// Description: Created a customer with the indicated parameters
// Postcondition: If type is not A or D, set to "None"
//				  Time is set to theTime and length is set to theLength
Customer::Customer(string theType, 
				   unsigned int theTime,
				   unsigned int theLength){
	if(theType == "A" || theType == "D"){
		type = theType;
	}
	else{
		type = "None";
	}

	time   = theTime;
	length = theLength;
}

// Description: Returns the type
string Customer::getType() const{
	return(type);
}

// Description: Returns the time
unsigned int Customer::getTime() const{
	return(time);
}

// Description: Returns the Length
unsigned int Customer::getLength() const{
	return(length);
}

// Description: Comparison operator. Compares "this" Customer object with
//				"rhs" Customer object.
//				Returns true if time of "this" Customer object is > than
//				the time of "rhs" Customer object.
bool Customer::operator==(const Customer & rhs){
	string rhsType = rhs.getType();
	unsigned int rhsTime = rhs.getTime();

	if(this->type == rhsType && this->time == rhsTime){
		return(true);
	}

	return(false);
}

// Description: Comparison operator. Compares "this" Customer object with
//				"rhs" Customer object.
//				Returns true if "this" has type A and "rhs" has type D
//				If type is "None", then it is less than the other
bool Customer::operator>(const Customer & rhs){
	string rhsType = rhs.getType();
	unsigned int rhsTime = rhs.getTime();

	if(this->type == "A" && rhsType == "D"){
		return(true);
	}
	else if(this->type == rhsType && this->time < rhsTime){
		return(true);
	}
	else if(rhs.getType() == "None"){
		return(true);
	}

	return(false);
}
	

	


// End of Customer.cpp