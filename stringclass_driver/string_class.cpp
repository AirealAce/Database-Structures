#include "string_class.h"	//include user defined header
#include <iomanip>			//use formatting manipulators

/*************************************************************************************
//Name: Default Constructor
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized
//Description: This is the default constructor which will be called automatically when
//an object is declared. It will initialize the state of the class
//*************************************************************************************/
string_class::string_class()
{
	current_string = "";
}

//*************************************************************************************
//Name: Explicit-value constructor
//Precondition: a parameter has been passed
//Postcondition: If entered correctly, the class object is initialized
//Description: This function initializes an object to an explicit value
//*************************************************************************************
string_class::string_class(const string& s)
{
	current_string = s;
}

//*************************************************************************************
//Name: palindrome
//Precondition: current_string object has been defined
//Postcondition: bool value is returned 
//Description: this function returns bool value based on if current_string is a palindrome
//*************************************************************************************
bool string_class::palindrome()
{
	string copy = lowercase(), reversed;	//we will use lowercase virsion of current_string
	int x,y = 0;
	//reverse the string
	for (x = copy.length() - 1; x >= 0; --x) {
		reversed.resize(++y, copy[x]);
		//^replace reversed[y] with copy[x], then increase to new size {++y}
	}
	
	//if palindrome, return true, else false
	if (copy == reversed) 
		{ return true; }
	else 
		{ return false; }
}

//*************************************************************************************
//Name: replace_all
//Precondition: current_string defined, old_substring & new substring have been passed
//Postcondition: current_string is altered
//Description: this function replaces all instances old_substring with new_substring in current_string
//*************************************************************************************
void string_class::replace_all(string old_substring, string new_substring)
{
	int x, y, z = 0; //x,y = loop variables; z = index after end of new_substring
	if (current_string == "" || old_substring.size() > current_string.size() || locate(old_substring,z) == -1)
		cout << "INVALID ARGUMENT!" << endl;
	else {
		//while old_substring exist in current_string (starting from z)
		while (locate(old_substring, z) != -1)
		{
			x = locate(old_substring, z);								//x holds starting location of old substring
			shift(x, old_substring.size(), new_substring.size());		//shift string characters to accomodate for new_substring
			//loop through string to replace instance of old_substring
			for (y = 0; y < new_substring.size(); ++y)
			{
				current_string[x] = new_substring[y];
				++x;
			}
			
			z = x; //prepare to search for old_substring in current_string, starting from index z
			//old_string might be larger than current_string now
			if (old_substring.size() > current_string.size())
			{	break;	}
		}
	}
}

//*************************************************************************************
//Name: operator<<
//Precondition: the current_string object has been initialized / declared. 
//Postcondition: the attributes of the string_class are displayed
//Description: This function displays the contents of a string_class object, & allows for chaining.
// EX of chaining: cout << str_classObj1 << str_classObj2 << str_classObj3.
//*************************************************************************************
ostream& operator<<(ostream& out, string_class& org)
{
	out << org.current_string << endl;
	return out;//returning object that invoked the function (for chaining)
}

//*************************************************************************************
//Name: lowercase
//Precondition: current_string defined
//Postcondition: the lowercase of current_string is returned
//Description: this function returns the lowercase of current_string
//*************************************************************************************
string string_class::lowercase()
{
	string copy = current_string;
	int x = 0;
	//iterate through each character in the string
	for (x = 0; x < copy.length(); ++x) {
		//if character is capitalized, make it lowercase
		if (copy[x] >= 'A' && copy[x] <= 'Z')
		{
			copy[x] = tolower(copy[x]);
		}
	}
	return copy;
}

/******************************************************************************************************************************************************
Name: locate
Pre-Condition: current_string defined, string & integer passed
Post-Condition: the index of sub_str in current_string is returned 
Description: this function searches for sub_str in current_string, starting from index start_here,
then returns the starting index of sub_str in current_string.
******************************************************************************************************************************************************/
int string_class::locate( string sub_str, int start_here)
{
	//start_here = start searching from this position
	//x->used to store sample, y=starting location of sample, z=sample's size
	int x, y, z; 			//loop variables
	string sample;			//sample of current_string
	for (y = start_here; y <= current_string.size() - sub_str.size(); ++y)
	{//^ go through string up until last possible sample 
		sample = ""; x = y;	z = 0;			//reset variables
		for (x = y; z < sub_str.size(); ++x)
		{
			sample.resize(++z, current_string[x]);
			//^replace sample[z] with current_string[x], then increase to new size {++z}
		}
		//if sample == sub_str, return the location
		if (sample == sub_str) 
			{ return y; }
	}
	//otherwise, return -1 to represent current_string does NOT contain sub_str
	return -1;
}

/******************************************************************************************************************************************************
Name: shift
Pre-Condition: location index, old_substring's & new_substring's sizes have been passed
Post-Condition: current_string is altered to accomodate for the replacement
Description: this function prepares current_string to have old_substring replaced with new_substring.
This member function should be used in combination with replace_all & locate. 
******************************************************************************************************************************************************/
void string_class::shift(int location, int old_strsz, int new_strsz)
{
	int x,y;								//x = index immediately after end location of old/new sub_string
	int current_sz = current_string.size();	//current_sz = current string size
	int diff = new_strsz - old_strsz;		//difference between new & old substring sizes

	//if new_substring > old_substring
	if (diff > 0) 
	{//make space
		current_string.resize(current_sz += diff, ' ');
		//must shift diff*-1 amount of times
		for (y = 0; y < diff; ++y)
		{//because old_substring size is greater, we stop shifting at the end of that string
			for (x = current_sz-1; x >= location + old_strsz; --x)
			{//shift characters right
				current_string[x] = current_string[x - 1];
			}
		}
	}
	//else if new_substring < old_substring
	else if (diff < 0) 
	{//must shift diff*-1 amount of times (recall diff is negative)
		for (y = 0; y < diff * -1; ++y)
		{//because new_substring size is greater, we stop shifting at the end of that string
			for (x = location + new_strsz; x < current_sz; ++x)
			{//shift characters left
				current_string[x] = current_string[x + 1];
			}
		}
		current_string.resize(current_sz += diff, ' ');
		//remove extra characters
	}
}