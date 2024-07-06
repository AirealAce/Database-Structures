#pragma once
#include <vector> 
#include <string>
using namespace std;

#ifndef vlist_H
#define vlist_H

class vlist
{
public:
	vlist();				//defualt constructior 
	vlist(const vlist&);	//copy constructor
	~vlist();				//destructor
	bool isEmpty();			//check if vlist empty
	vector<string>::iterator search(const string&);	//searches for string in vector
	void insert(const string&);	//inserts into vector
	void remove(const string&);	//removes from vector
	void print();				//prints vector
private:
	vector<string> DB;		//constructs an empty vector of type string; capacity can increase
	int count;				//represents number of elements in vector (as opposed to memory allocated for vector)
};

#endif


