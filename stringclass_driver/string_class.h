//string_class.h
#pragma once			//include the source file only once in a single compilation
#include <iostream>		//standard c++ library for cout/cin 
#include <fstream>		//file manipulation library
#include <string>		//string manipulation library
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
using namespace std;	//standard namespace convention

#ifndef string_class_h			//if header file is not defined
#define string_class_h			//define it 

class string_class {
public:
	string_class();						//defualt constructor: current_string = ""
	string_class(const string& s);		//explicit-value constructor: current_string = {explicit value}
	bool palindrome();					//bool function: returns true if current_string reads the same as it does backwards
	void replace_all(string old_substring, string new_substring);	
	//^function to replace old_substring with new_substring in current_string
	string lowercase();					//returns the lowercase of current_string
	int locate(string sub_str, int start_here);	//returns location of sub_str within current_string
	void shift( int location, int old_strsz, int new_strsz);//function: supports replace_all.
	//^uses old_substring's & new_substring's sizes & substring location to modify current_string

private:
	string current_string = "";
	friend ostream& operator<<(ostream& out, string_class& org);	//overloading << 
};

#endif