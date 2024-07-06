/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Aaron P. Mills                            TOTAL POINTS:  25
COURSE:  COP 3530								DUE DATE:  10/24/2021
Assignment Name:  Assignment#5                 Professor:  Dr. Petrie
Description:  This prgram includes the following: singly-linked list, stack, classes, pointers, & more.
******************************************************************************************************/
#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

//test driver
int main()
{
	string post_fix = "", in_fix = "", exp = "";

	cout << "*****Test 1********************************************************" << endl;
	exp = "a b + c d - *";
	cout << "exp: \t|" << exp << endl;
	in_fix = infix(exp);
	cout << "infix: \t|" << in_fix << endl;
	cout << "*****End of Test 1********************************************************" << endl << endl;
	
	cout << "*****Test 2********************************************************" << endl; 
	exp = "a b +";
	cout << "exp: \t|" << exp << endl;
	in_fix = infix(exp);
	cout << "infix: \t|" << in_fix << endl;
	cout << "*****End of Test 2********************************************************" << endl << endl;

	cout << "*****Test 3********************************************************" << endl;
	exp = "a b / c d / /";
	cout << "exp: \t|" << exp << endl;
	in_fix = infix(exp);
	cout << "infix: \t|" << in_fix << endl;
	cout << "*****End of Test 3********************************************************" << endl << endl;

	cout << "*****Test 4********************************************************" << endl;
	exp = "a b / c * +";
	cout << "exp: \t|" << exp << endl;
	in_fix = infix(exp);
	cout << "infix: \t|" << in_fix << endl;
	cout << "*****End of Test 4********************************************************" << endl << endl;

	cout << "*****Test 5********************************************************" << endl;
	exp = "a b c d / + e * f";
	cout << "exp: \t|" << exp << endl;
	in_fix = infix(exp);
	cout << "infix: \t|" << in_fix << endl;
	cout << "*****End of Test 5********************************************************" << endl << endl;

	cout << "*****Test 6********************************************************" << endl;
	exp = "a";
	cout << "exp: \t|" << exp << endl;
	in_fix = infix(exp);
	cout << "infix: \t|" << in_fix << endl;
	cout << "*****End of Test 6********************************************************" << endl << endl;

	cout << "*****Test 7********************************************************" << endl;
	exp = "";
	cout << "exp: \t|" << exp << endl;
	in_fix = infix(exp);
	cout << "infix: \t|" << in_fix << endl;
	cout << "*****End of Test 7********************************************************" << endl << endl;

	cout << "*****Test 8********************************************************" << endl;
	exp = "+";
	cout << "exp: \t|" << exp << endl;
	in_fix = infix(exp);
	cout << "infix: \t|" << in_fix << endl;
	cout << "*****End of Test 8********************************************************" << endl << endl;

	//Error checking...
	cout << "*****My Test 1********************************************************" << endl;
	exp = "a b + c d - e f * g h / i j * + - / /";
	cout << "exp: \t|" << exp << endl;
	in_fix = infix(exp);
	cout << "infix: \t|" << in_fix << endl;
	cout << "*****End of My Test 1********************************************************" << endl << endl;
	
	cout << "*****My Test 2********************************************************" << endl;
	exp = "a b + c * d -";
	cout << "exp: \t|" << exp << endl;
	in_fix = infix(exp);
	cout << "infix: \t|" << in_fix << endl;
	cout << "*****End of My Test 2********************************************************" << endl << endl;

	string button = "y"; int tst_count = 0;
	while (button == "y" || button == "Y")
	{
		tst_count++;
		cout << "*****Your Test " << tst_count << "********************************************************" << endl;
		cout << "Enter a postfix expression: ";
		getline(cin, exp);
		cout << "exp: \t|" << exp << endl;
		in_fix = infix(exp);
		cout << "infix: \t|" << in_fix << endl;
		cout << "*****End of Your Test " << tst_count << "********************************************************" << endl << endl;

		cout << "Would you like to test another expression? (Y/y) ";
		getline(cin,button);
		cout << endl;
	}
	return 0;
}

