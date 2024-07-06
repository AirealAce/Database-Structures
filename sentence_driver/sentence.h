#pragma once			//include the source file only once in a single compilation
#include <iostream>
#include <string>
using namespace std;

#ifndef SENTENCE_H			//if not defined
#define SENTENCE_H			//define file

//word = node in list
class word
{
public:
	string term;	//term = data of node in list
	word* next;		//*next = pointer to next node in list
};

//list class
class sentence
{
public:
	sentence();                     //defualt constructor: initializes front/back of node to null
	sentence(const string& s);		//explicit-value constructor: initializes list to s 
	sentence(const sentence& org);  //copy constructor: used for call by value, return, or 
	//								//initialization/declaration word object
	~sentence();					//destructor: de-allocate all memory allocated for the word. 
	bool isEmpty() { return front == 0; }	//checks if list empty
	int length();					//determines the length of the sentence 
	void add_back(string& s);		//adds word (node) to back of list
	friend ostream& operator<<(ostream& out, const sentence&); //friend: chaining to print sentence
	void operator=(const string& s);		//overload=: assign s value to the current object (list)
	sentence& operator=(const sentence& w);	//^ but sentence parameter instead 
	void operator+(sentence& B);			//overload+: without chaining; adds list B to current list 
	bool isEqual(sentence& B);				//returns true if two lists are equal; otherwise false;
	void remove(const string& s);			//deletes the first occurrence of the string s from list
	word* search(const string&);			//searches for node equal to string in list, returns  location

private:
	word* front, * back;	//front/back of list pointers 
};

#endif
