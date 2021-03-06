/*-------------------------------------------------------------------------------------------------

	Authors:		Bushey, Luke
					King, Garret

	Created:		2/21/2017
	Modified:		3/1/2017

	This class represents a customer object. Each object stores the customer's first and last
	names, a unique customer ID, a history of the customer's transactions, and a queue of
	which media items the customer is holding (still has checked out). This class has the
	functionality to take in a data stream with the method setData() in order to populate its
	data members. The method displayCustomer() will neatly print a customer object's
	information to the console.

	Assumption:  The customer ID will not have preceding zeroes.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef customer_h
#define customer_h

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "dvd.h"

using namespace std;

class Customer {

	public:
	
	Customer(void);					//default no-args constructor
	~Customer(void);				//destructor

	/*------------------------------------------------------------------------------------------------

		Method takes in a file stream and populates the customer's data members by calling the
		setter methods. Setters are used as hepler methods for error checking. If any setter
		method returns false, then setData will return false and the object should be deleted.

		PRECONDITIONS:
			- data must be formatted for customer objects

	------------------------------------------------------------------------------------------------*/

	bool setData(ifstream& infile);

	/*------------------------------------------------------------------------------------------------

		Method prints the Transaction history associated with a customer.

		NOTES:	Method cannot change any data members.

	------------------------------------------------------------------------------------------------*/

	void displayHistory(void) const;

	/*------------------------------------------------------------------------------------------------

		Method prints information associated with a Customer object to the console.

		NOTES:	Method cannot change any data members.

	------------------------------------------------------------------------------------------------*/

	void displayCustomer(void) const;

	/*------------------------------------------------------------------------------------------------

		Method takes in a Transaction object and calls addTransaction() to add the Transaction
		to the Customer's history. The Transaction is also stored in the Customer's holding
		vector indicating that they have checked the item out of the store's inventory.

	------------------------------------------------------------------------------------------------*/

	void borrowMedia(DVD* movie, string transaction);
	
	/*------------------------------------------------------------------------------------------------

		Method takes in a Transaction object and calls addTransaction() to add the Transaction
		to the Customer's history. The Transaction concerning the same Media item is then found
		in the Customer's holding vector and deleted, indicating that the item has been returned.

	------------------------------------------------------------------------------------------------*/

	void returnMedia(DVD* movie, string transaction);

	//getters
	int getID(void) const;
	string getFirstName(void) const;
	string getLastName(void) const;

	/*------------------------------------------------------------------------------------------------

		Setter method for ID. Returns a bool indicating success.

		PRECONDITIONS:
			- input must be less than 10000
			- input must be greater than 999

		POSTCONDITIONS:
			- sets ID to input

	------------------------------------------------------------------------------------------------*/

	bool setID(int input);

	/*------------------------------------------------------------------------------------------------

		Setter method for firstName. Returns a bool indicating success.

		PRECONDITIONS:
			- input cannot be an empty string

		POSTCONDITIONS:
			- sets firstName to input

	------------------------------------------------------------------------------------------------*/

	bool setFirstName(string input);

	/*------------------------------------------------------------------------------------------------

		Setter method for lastName. Returns a bool indicating success.

		PRECONDITIONS:
			- input cannot be an empty string

		POSTCONDITIONS:
			- sets lastName to input

	------------------------------------------------------------------------------------------------*/

	bool setLastName(string input);

	Customer& operator=(const Customer& toCopy);
	
	private:

	/*------------------------------------------------------------------------------------------------

	Method takes in a Transaction object and adds it to the history queue.

	------------------------------------------------------------------------------------------------*/

	void addTransaction(string toAdd);
	
	int ID;
	string firstName;
	string lastName;
	vector<string> history;			//history of all of a customer's transactions
	vector<DVD*> holding;			//vector of media customer currently has checked out
};
#endif // !customer_h

