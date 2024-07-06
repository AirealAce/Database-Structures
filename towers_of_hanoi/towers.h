#pragma once			//include the source file only once in a single compilation
#include <iostream>
#include <string>
using namespace std;

#ifndef TOWERS_H			//if not defined
#define TOWERS_H			//define file

typedef string stack_element;	//Variables of type "stack_element" are string varaibles

class stack_node
{
public:
	stack_element data;		//the data attached to the node
	stack_node* next=0;		//the pointer to the node & its address
	int size;				//size of node
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
	void rename(string str) { (*this).name = str; }		//allows the renaming of stacks; may update later
	void clear();										//empties all the stacks

//private:	private variables make this annoyingly complicated.
	stack_node* s_top;									//pointer to top of stack
	string name;										//name of stack
	int count;											//number of nodes
};

void print_stacks(stack& A, stack& B, stack& C);		//displays all stacks
void move(stack& src, stack& dst, int& moves);			//execute player action (if acceptable)
void newGame(stack& A, stack& B, stack& C, int& moves);	//prepares a new game

#endif







