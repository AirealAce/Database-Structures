/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Aaron P. Mills                            TOTAL POINTS:  25               
COURSE:  COP 3530								DUE DATE:  09/26/2021
Assignment Name:  Assignment#3                 Professor:  Dr. Petrie

Description:  The program involves the manipulation of strings
******************************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "string_class.h"
using namespace std;

int main()
{
	string_class s;
	
	cout << "****************************************" << endl
		<< "Test#1: tesing default constructor and overloaded operator<< with chaining\n"
		<< s << "1st blank line" << endl << s << "2nd blank line" << endl
		<< "Test#1 Ended" << endl 
		<< "****************************************" << endl;

	string_class r("hello");
	cout << "****************************************" << endl
		<< "Test#2: tesing explicit-value constructor and overloaded operator<< with chaining\n"
		<< r << endl << "1st blank line" << endl << r <<endl<< "2nd blank line " << endl
		<< "Test#2 Ended" << endl
		<< "****************************************" << endl;

	
	cout << "****************************************" << endl
		<< "Test#3: tesing palindrome\n"
		<< "****************************************" << endl;
	string response = "Y";
	string ss;
	while (response == "Y" || response == "y")
	{
		cout << "Enter String: ";
		getline(cin, ss);
		string_class main_string(ss);

		if (main_string.palindrome())
		{
			cout << ss << " is a palindrome\n";
		}
		else
		{
			cout << ss << " is not a palindrome\n";
		}
		cout << "Would you like to try another string? (Y or N):   ";
		getline( cin,response);
	}
	cout << "Test#3 Ended" << endl
		<< "****************************************" << endl;
	cout << "****************************************" << endl;
	
	
	cout << "Test#4: tesing replace_all\n"
		<< "****************************************" << endl;
	response = "y";
	string current, old_substring, new_substring;
	while (response == "Y" || response == "y")
	{
		cout << "Enter value for current_string: ";
		getline(cin, current);
		string_class current_string(current);
		cout << "Enter old_substring: ";
		getline(cin, old_substring);
		cout << "Enter new_substring: ";
		getline(cin, new_substring);
		cout << "Current Value in Current string = " << current << endl;
		current_string.replace_all(old_substring, new_substring);
		cout << "New value in Current String = " << current_string << endl;
		cout<< endl;
		cout << "Would you like to try another string? (Y or N):   ";
		getline(cin, response);
		cout << endl;
	}
	cout << "****************************************" << endl
		<< "End Test#4: tesing replace\n"
		<< "****************************************" << endl;
	return 0;
}