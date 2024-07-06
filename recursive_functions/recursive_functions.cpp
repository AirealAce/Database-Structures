/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Aaron P. Mills                            TOTAL POINTS:  25
COURSE:  COP 3530								DUE DATE:  11/21/2021
Assignment Name:  Assignment#8					Professor:  Dr. Petrie
Description:  The program involves the usage of strings and recurssive functions
******************************************************************************************************/
#include <iostream>
#include <string>
using namespace std;

//*************************************************************************************
//Name: palindrome
//Precondition: string argument is passed
//Postcondition: returns true if string is a palindrome, otherwise false
//Description: uses recurssion to return true/false if string is read the same forwards as it is backwards
//*************************************************************************************
bool palindrome(const string& s) 
{ 
	if (s.length() != 0)
	{//"while" there are still characters to compare
		if (tolower(s[0]) == tolower(s[s.size() - 1]))	//use lowercase versions during comparison
		{//if first character in s == last character in s, then it's symmetric / a palindrome
			return palindrome(s.substr(1, s.size() - 2));	//remove the first & last index, then compare again
		}
		else if (s[0] == ' ')
		{//if first index is a space
			return palindrome(s.substr(1, s.size() - 1));	//remove the first index, compare again
		}
		else if (s[s.size() - 1] == ' ')
		{//if last index is a space
			return palindrome(s.substr(0, s.size() - 1));		//remove the last index, compare again
		}
		else
		{//othwerwise, string is NOT palindrome at all
			return false;
		}
	}
	return true;	//base case
}

//*************************************************************************************
//Name: printReversel
//Precondition: string is passed
//Postcondition: string reversed is returned
//Description: uses recursion to reverse a string
//*************************************************************************************
string  printReversel(const string& s) 
{ 
	string s_reversed = "";		//reversed string
	if (s.length() != 0)
	{//"while" there are still characters to add
		s_reversed = s[s.size() - 1];										//reversed string = last character in s
		return s_reversed += printReversel(s.substr(0, s.length() - 1));	//add last character multiple times, while decreasing the string size
	}
	return s_reversed;	//else return empty string 
}

//*************************************************************************************
//Name: printIterReverse
//Precondition: string is passed
//Postcondition: reversed string is returned
//Description: does NOT use recursion and reverses a string
//*************************************************************************************
string printIterReverse(const string& s) 
{ 
	string copy = s, reversed;	//NOTE: it was not specified whether lowercase should be considered the same word
	int x, y = 0;				//loop counters
	//reverse the string
	for (x = copy.length() - 1; x >= 0; --x) {
		reversed.resize(++y, copy[x]);	//replace reversed[y] with copy[x], then increase to new size {++y}
	}
	return reversed;
}


//test driver
int main()
{
	string s = "";
	string response = "y";

	while (response == "y" || response == "Y")
	{
		cout << " please enter string: ";
		getline(cin, s);
		if (palindrome(s) == true)
		{
			cout << s << " IS a palindrome \n";
		}
		else
		{
			cout << s << " is a NOT palindrome \n";
		}

		cout << "The Rec-reverse of \"" << s << "\" is \"" << printReversel(s) << "\"" << endl;
		cout << "The Iter-reverse of \"" << s << "\" is \"" << printIterReverse(s) << "\"" << endl;
		cout << endl << "Do you wish to continue (y or Y for yes; n or N for no ? ";
		cin >> response;
		cin.ignore();
	}
	return 0;
}
