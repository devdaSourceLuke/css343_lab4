/*-------------------------------------------------------------------------------------------------

	Authors:		Bushey, Luke
					King, Garret

	Created:		2/21/2017
	Modified:		3/1/2017

	This class represents a DVD object. Each object stores information about the title, director,
	release year, and number of copies in inventory. Getter and setter methods are available
	for all data members. This class has the functionality to take in a data stream with the
	method setData() in order to populate its data members. Overloaded comparison operators
	allow for comparing DVD objects, and the method adjustInventory() can be called to increase
	or decrease the inventory amount. The method display() will neatly print a DVD object's
	information to the console.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef dvd_h
#define dvd_h

#include <string>
#include <iostream>

using namespace std;

const int CURRENTYEAR = 2017;

class DVD {

public:

	DVD(void);						//default no-args constructor
	virtual ~DVD(void);				//default destructor
	
	/*------------------------------------------------------------------------------------------------

		Method takes in a file stream and populates the DVD's data members by calling the
		setter methods. Setters are used as hepler methods for error checking. If any setter
		method returns false, then setData will return false and the object should be deleted.

		PRECONDITIONS:
			- data must be formatted for DVD objects

	------------------------------------------------------------------------------------------------*/

	virtual bool setData(ifstream& inFile);

	/*------------------------------------------------------------------------------------------------

		Method prints all information of a DVD object to the console in an easy-to-read format.

		NOTES:	Method cannot change any data members.

	------------------------------------------------------------------------------------------------*/

	virtual void display(void) const;

	//getters
	string getTitle(void) const;
	string getDirector(void) const;
	virtual string getActor(void) const;
	int getInventory(void) const;
	int getYear(void) const;
	virtual int getMonth(void) const;
	virtual char getGenre(void) const;
	
	/*------------------------------------------------------------------------------------------------

		Setter method for title. Returns a bool indicating success.

		PRECONDITIONS:
			- input cannot be an empty string

		POSTCONDITIONS:
			- sets title equal to input

	------------------------------------------------------------------------------------------------*/

	bool setTitle(string input);

	/*------------------------------------------------------------------------------------------------

		Setter method for director. Returns a bool indicating success.

		PRECONDITIONS:
			- input cannot be an empty string

		POSTCONDITIONS:
			- sets director equal to input

	------------------------------------------------------------------------------------------------*/

	bool setDirector(string input);

	/*------------------------------------------------------------------------------------------------

	Setter method for date. Returns a bool indicating success.

	PRECONDITIONS:
	- input cannot be less than next year and greater than 1927

	POSTCONDITIONS:
	- sets date equal to input

	------------------------------------------------------------------------------------------------*/

	bool setYear(int input);

	virtual bool setMonth(int input);
	
	/*------------------------------------------------------------------------------------------------

		Method decreases or increases the inventory of a DVD object. Returns a bool indicating
		success.

		PRECONDITIONS:
			- inventory + input > 0

		POSTCONDITIONS:
			- sets inventory equal to inventory + input

	------------------------------------------------------------------------------------------------*/
	
	bool adjustInventory(int input);

	bool setGenre(char input);

	virtual bool setActor(string input);

	//overloaded comparison operators
	virtual bool operator==(const DVD& toCompare) const;
	virtual bool operator!=(const DVD& toCompare) const;
	virtual bool operator<(const DVD& toCompare) const;
	virtual bool operator>(const DVD& toCompare) const;

private:
	char genre;
	string title ;
	string director;
	int inventory;
	int year;	
};

#endif // !dvd_h