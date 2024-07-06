#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "vlist.h" 
using namespace std;

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: vlist
Pre-Conditon: constructor has not been invoked.
Post-Condition: count = 0; vector size is 9 
Description: constructs an instance of a vlist object.
**********************************************************************************************************************************************************/
vlist::vlist()
{
	cout << "Default Constructor Invoked" << endl;
	count = 0;		//there are no elements in a defualt vlist
	DB.resize(9);	//allocate 9 memory spaces for defualt vlists (<-according to professor's comment)
}


/***********************FUNCTION HEADER ******************************************************************************************************************
Function Name: vlist
Precondition: a vlist object is being passed by reference.
Postcondition: a hard copy of a vlist object has been created.
Description: creates a hard copy of a vlist object.
**********************************************************************************************************************************************************/
vlist::vlist(const vlist& Org) 
{
	cout << "Copy Constructor Invoked" << endl;
	(*this).count = Org.count;		//copy the counter
	(*this).DB = Org.DB;			//copy the vector
	(*this).print();				//print each vlist object
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Function Name: ~vlist
Precondition: destructor has not been invoked.
Postcondition: array DB deleted.
Description: deallocates memory of a vlist object.
**********************************************************************************************************************************************************/
vlist::~vlist() 
{
	cout << "Destructor Invoked" << endl;
	count = 0;			//reset counter
	DB.clear();			//remove all values from vector memory
	DB.shrink_to_fit();	//de-allocate all the memory in the vector
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Function Name: isEmpty()
Precondition: vlist declared
Postcondition: boolean value returned
Description: returns true if vlist is empty, otherwise false
**********************************************************************************************************************************************************/
bool vlist::isEmpty() { return count == 0 ; }

/***********************FUNCTION HEADER ******************************************************************************************************************
Function Name: search
Precondition: function called
Postcondition: returns the location (via iterator) for the key in the vector, otherwise returns the front of vector
Description: this function informs the user on the location of key in the vlist
**********************************************************************************************************************************************************/
vector<string>::iterator vlist::search(const string& key) 
{
	int x;	//loop counter
	vector<string>::iterator i = DB.begin();	//iterator representing location of key in vector
	cout << "Search Key: " << key << "\t";
	for (x = 0; x < count; x++) {
		if (DB[x] == key)						//if key exist in vector
		{
			cout << "Item Found" << endl;
			i = DB.begin() + x;					//this is the location of the key 
			return i;							//return location
		}
	}
	cout << "Item Not Found" << endl;			//otherwise key not found
	return i;									//return front of vector
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Function Name: insert
Precondition: vlist declared
Postcondition: vlist contains "key" if memory is available
Description: inserts "key" into vlist if possible
**********************************************************************************************************************************************************/
void vlist::insert(const string& key) 
{
	if (isEmpty()) {
		DB.insert(DB.begin(), key);	//if empty, insert at front of vector
		count++;					//we have 1 new element
	}
	else if(DB.size() == DB.max_size())
	{//if max potential size is reached, we cannot insert to vector
		cout << "Not enough memory available" << endl;
	}
	else {
		int x;
		for (x = 0; x < count; x++) {
			if (DB[x] >= key) {		//for alphabetical ordering
				if (count == DB.size()) DB.resize(DB.size() + 1);	//if full, then resize
				DB.insert(DB.begin() + x, key);						//insert key, vector shift is implied 
				x = 0;												//reset counter
				break;												//exit loop
			}
		}
		if (x == count) 
		{//if loop counter x was not reset, that means key would be last in alphabetical order
			DB.insert(DB.begin()+count, key);	//insert to the end of the list
		}
		count++;		//we have 1 additional element
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Function Name: remove
Precondition: vlist declared
Postcondition: vlist lost an element named "key" if it exist
Description: removes 1 instance of "key" in vlist if it exist
**********************************************************************************************************************************************************/
void vlist::remove(const string& key) 
{
	vector<string>::iterator i = search(key);	//i = location of key if it exist
	if (*i == key)	
	{//if the value at location of i == key
		DB.erase(i);	//then key exist in vector
		--count;		//remove it
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Function Name: print
Precondition: vlist declared
Postcondition: vlist displayed to screen
Description: display contents of vlist to screen
**********************************************************************************************************************************************************/
void vlist::print() 
{
	for (int x = 0; x < count; ++x) {
		cout << DB[x] << endl;
	}
}

