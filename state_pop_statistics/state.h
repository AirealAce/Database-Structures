#pragma once			//include the source file only once in a single compilation
#include <iostream>		//standard c++ library for cout/cin 
#include <fstream>		//file manipulation library
#include <string>		//string manipulation library

using namespace std;	//standard namespace convention

#ifndef state_h			//if header file is not defined
#define state_h			//define it 

class population_record				//variable type for population records
{	
public:								//access specifier: all items under public may be accessed outside the class
	string state_name = "";			//string that holds states' names
	double population = 0;			//double that holds population quantity 
};


class state_class					//variable type for state classes
{
public:								//access specifier 
	state_class();					//default constructor: initializes the state (private data) of the class.
	state_class(const state_class&);//copy constructor: copies one array into the next
	~state_class();					//destructor which de-allocates all memory allocated to the dynamic pop_DB
	void double_size();				//doubles the capacity (size) of the memory allocate to dynamic array pop_DB
	void operator+(const population_record &);	//overload operator+ "without chaining.": inserts a popultation record into  population dynamic array (pop_DB).
	bool Is_Full() { return count == capacity; };//inline implementation: returns true if pop_DB is full; otherwise returns false
	bool Is_Empty() { return count == 0; };		//inline implementation: returns ture if pop_DB is empty; otherwise returns false
	int Search(const string&); //search pop_DB for a state in pop_DB & return location or -1 if not found
	void Remove(const string&); // deletes a population record from pop_DB given state name 
	void Print_ALL_To_File(const string& datafile);  //prints all the fields of all the population records stored in pop_DB to the filename stored in datafile.
	void Print_ALL();//prints all the fields of all the population records stored in pop_DB to the screen.
	void Print_Range(const int min, const int max);//prints all the fields of all the population records stored in pop_DB with a population between min and max to the screen;
	int State_Count(const int min, const int max);  //returns the total number of states with a population between min and max, inclusive.
	void Sort(); //sorts the array pop_DB in alphabetical order based on state_name field using insertion sort algorithm
private:			//access specifier: these members are accessed only from within member functions
	int count;		//total number of population records stored in pop_DB
	int capacity;	//total memory allocated to the dynamic array pop_DB
	population_record* pop_DB;      //dynamic array of state_classes are named "pop_D8"
};

#endif