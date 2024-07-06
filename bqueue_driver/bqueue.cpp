#include <iostream>
#include <string>
#include "bqueue.h"

using namespace std;

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: bqueue
Pre-Conditon: definitions are defined & set, queue is declared
Post-Condition: queue is initialized to 0
Description: sets front of queue to point to no memory
**********************************************************************************************************************************************************/
bqueue::bqueue() {
	front = 0;		//empty queue
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: destructor
Pre-Conditon: queue declared
Post-Condition: memory allocated for queue is de-allocated
Description: de-allocates memory for circular queue
**********************************************************************************************************************************************************/
bqueue::~bqueue()
{
	cout << "~bqueue has been called\n";
	while (!empty())
	{
		dequeue();		//de-allocate memory in queue until empty
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: copy constructor
Pre-Conditon: both queues are declared
Post-Condition: current queue holds the data of argument queue
Description: copies one circular queue into current queue
**********************************************************************************************************************************************************/
bqueue::bqueue (const bqueue& Org)
{
	(*this).front = 0;		//empty current queue
	bqnode* p = Org.front;	//pointer for transversing 
	//if queue is not empty
	while (p != 0)
	{
		(*this).enqueue(p->priority);			//add data of each node from argument queue to current
		if (p->next == Org.front) { break; }	//if we reached end of all data, stop copying
		p = p->next;							//transverse through queue
	}

}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: enqueue
Pre-Conditon: queue declared
Post-Condition: queue contains an aditional node with priority equal to item
Description: adds node to end of queue with priority field equal to item
**********************************************************************************************************************************************************/
void bqueue::enqueue(int item)
{
	if (empty())
	{//if queue is empty
		front = new bqnode;					//create new node
		front->priority = item;				//set the priority field 
		front->next = front->prev = front;	//make the queue circular for future use
	}
	else
	{
		bqnode* p = front->prev;	//this is the "back" (last node before front)
		p->next = new bqnode;		//create a new "back"
		p->next->prev = p;			//the old back is the previous of the new back
		p = p->next;				//point to new back
		p->priority = item;			//set the priority field
		front->prev = p;			//new back is previous of front
		p->next = front;			//circle back to the front
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: dequeue
Pre-Conditon: removes node from front of circular queue
Post-Condition: circular queue is declared
Description: removes node from front of circular queue if not empty; otherwise, messege displays
**********************************************************************************************************************************************************/
void bqueue::dequeue()
{
	if (!empty())
	{
		bqnode* p = front;		//prepare to remove front
		front = front->next;	//new front 

		if (front != 0)
		{
			front->prev = p->prev;	//new front has the previous of the old front
			p->prev->next = front;	//back circulates to new front now
		}
		if (front == p) front = 0;	//if there is only one node, queue is empty
		delete p;					//de-allocate memory of node
	}
	else
	{//if queue is empty
		cout << "Cannot deQueue because queue is empty" << endl;
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: print
Pre-Conditon: circular queue declared
Post-Condition: contents of circular queue is displayed to screen
Description: prints the priority field of each node in circular queue
**********************************************************************************************************************************************************/
void bqueue::print()
{
	bqnode* p= front;		//pointer for transversing 
	while (p != 0)
	{
		cout << p->priority << endl;		//print priority field of node
		if (p->next == front) { break; }	//if end of queue is reached, stop printing
		p = p->next;						//traverse to next node
	}
}