//date.h
#pragma once			//include the source file only once in a single compilation
#include <iostream>		//standard c++ library for cout/cin 
#include <fstream>		//file manipulation library
#include <string>		//string manipulation library

using namespace std;	//standard namespace convention

#ifndef date_h			//if header file is not defined
#define date_h			//define it 

class Date
{
public:
	Date(); //default constructor; sets m=01, d=01, y =0001
	Date(unsigned m, unsigned d, unsigned y); //explicit-value constructor to set date equal to 
	//specified date. Print a message if a leap year.
	void display();	//output Date object to the screen
	int getMonth();	//accessor to output the month
	int getDay();	//accessor to output the day
	int getYear();	//accessor to output the year
	void setMonth(unsigned m);	//mutator to change the month
	void setDay(unsigned d);	//mutator to change the day
	void setYear(unsigned y);	//mutation to change the year
	friend ostream& operator<<(ostream& out, Date& dateObj);
	//^overloaded operator<< as a friend function with chaining
private:
	int myMonth=0, myDay=0, myYear=0; //month, day, and year of a Date obj respectively
};

#endif