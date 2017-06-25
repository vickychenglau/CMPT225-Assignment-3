/*
 * Customer.cpp - Implementation of Customer class
 * 
 * Class Description: Contains information about the arrival/departure time
 *					  of the customers, as well as their length of stay
 * Class Invariant:
 *
 * Last modified on: June 24, 2017
 * Author: Jacky Tse, Vicky Lau
 */

#include <iostream>
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
//				Returns true time and type are the same
bool Customer::operator==(const Customer & rhs){
	string rhsType = rhs.getType();
	unsigned int rhsTime = rhs.getTime();

	if(type == rhsType && time == rhsTime){
		return(true);
	}

	return(false);
}

// Description: Comparison operator. Compares "this" Customer object with
//				"rhs" Customer object.
//				Lower time has more priority. Type "A" has more priority.
//				If type is "None", then it is less than the other
bool Customer::operator>=(const Customer & rhs){
	string rhsType = rhs.getType();
	unsigned int rhsTime = rhs.getTime();

	if(time < rhsTime){
		return(true);
	}
	else if(time == rhsTime && type == "A" && rhsType == "D"){
		return(true);
	}

	return(false);
}

bool Customer::operator<=(const Customer & rhs){
	string rhsType = rhs.getType();
	unsigned int rhsTime = rhs.getTime();

	if(time > rhsTime){
		return(true);
	}
	else if(time == rhsTime && type == "D" && rhsType == "A"){
		return(true);
	}

	return(false);
}
	
// Description: Prints the content of "this".
ostream & operator<<(ostream &os, const Customer &p) {
	os << "Type: " << p.getType() << ",	Time: " << p.getTime() <<
		  ",	Length: " << p.getLength() << endl;

	return os;
}	

// End of Customer.cpp