/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Aaron P. Mills                            TOTAL POINTS:  25                COURSE:  COP 3530
Assignment Name:  Assignment#2                 Professor:  Dr. Petrie
DUE DATE:  09/19/2021

Description:  This program is to record valid dates & display them. It involves the following: 
1. C++ classes
2. Implementing a class in C++;
3. Operator overloading with chaining;
4. Preprocessor directives #ifndef, #define, and #endif;
5. this – the pointer to the current object.

*********************************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include "date.h"

using namespace std;

//*********************************************************************************************
int main()		//test driver
{
	Date myDate;
	Date herDate(11, 14, 1953);
	Date test1Date(25, 1, 1982);	//should generate error message that bad month
	Date test22Date(2, 29, 2020);	//ok, should say leep year
	Date test3Date(2, 30, 2021);	//should generate error message that bad day
	Date test4Date(1, 25, 0000);	//should generate error message that bad year
	Date test5Date(80, 40, 0000);	//should generate error message that bad month, day and year
	herDate.display();				//self explanatory 
	cout << herDate.getMonth() << endl;		//using methods to view private data
	cout << herDate.getDay() << endl;		//^
	cout << herDate.getYear() << endl;		//^
	myDate.setMonth(11);					//altering class data
	myDate.setDay(12);						//^
	myDate.setYear(2015);					//^
	cout << "myDate: " << myDate << " test22Date: " << test22Date << " herDate: " << herDate << endl;
	return 0;
}