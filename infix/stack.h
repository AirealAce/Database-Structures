#pragma once			//include the source file only once in a single compilation
#include <iostream>
#include <string>
using namespace std;

#ifndef STACK_H			//if not defined
#define STACK_H			//define file

typedef string stack_element;	//Variables of type "stack_element" are string varaibles

class stack_node
{
public:
	stack_element data;		//the data attached to the node
	stack_node* next;		//the pointer to the node & its address
};

class stack
{
public:
	stack();											//defualt constructor
	stack(const stack&);								//copy constructor
	~stack();											//destructor
	stack_element top();								//returns data of the top node of stack
	void pop();											//removes top element node from stack
	void push(const stack_element&);					//adds node element to top of the stack
	void print();										//prints the elements of the stack 
	bool empty() { return s_top == 0; };				//returns true if stack is empty

private:
	stack_node* s_top;									//pointer to top of stack
};

string postfix(string exp);
string infix(string exp);


#endif







