#pragma once		//include header only once
#include <iostream>
using namespace std;

#ifndef BQUEUE_H			//if not defined
#define BQUEUE_H			//define file

class bqnode				//node for queue
{
public:
	int priority;			//data field
	bqnode* prev, * next;	//previous & next poitners for nodes
};

class bqueue
{
public:
	bqueue();				//defualt constructor: initializes front to 0 
	~bqueue();				//destructor: deletes allocated memory
	bqueue(const bqueue&);	//copy constructor: used for initialization with "="
	void enqueue(int);		//adds to back of queue
	void dequeue();			//removes from back of queue
	void print();			//prints the entire queue
	bool empty() { return front == 0; }	//returns whether queue is empty or not

private:
	bqnode* front;			//front of queue
};

#endif