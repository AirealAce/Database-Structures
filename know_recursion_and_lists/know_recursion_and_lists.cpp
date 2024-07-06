/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Aaron P. Mills                            TOTAL POINTS:  25
COURSE:  COP 3530								DUE DATE:  11/28/2021
Assignment Name:  Assignment#9                 Professor:  Dr. Petrie
Description: This assignment is to add to a list, and print it recursively.
******************************************************************************************************/
#include <iostream>

using namespace std;

//node = node in list
class node
{
public:
	int data;		//data = data of node in list
	node* next;		//*next = pointer to next node in list
};

//*************************************************************************************
//Name: fun
//Precondition: node is passed
//Postcondition: list is printed started from that node
//Description: utilizes recurssion to print list starting from node
//*************************************************************************************
void fun( node* start)
{	/*Note: I commented out the code that seemed to have no significance*/
	//if list is empty at node, don't print anything
	if (start == 0)
		return;
	cout << start->data;			//otherwise, print the node data
	if (start->next != 0)			//if there is more nodes to print
		cout << "->";				//add arrows to make it look like a list
		fun(start->next/*->next*/);	//then print the next node recursively 
	//cout << start->data;
}

//*************************************************************************************
//Name: add_back
//Precondition: front & back node are passed, along with the data to be added
//Postcondition: data is added to a new node in list
//Description: addes data to list
//*************************************************************************************
void add_back(node*& front, node*& back, const int x)
{
	if (front == 0)			//if list is empty
	{
		front = new node;	//front points to a new node memory 
		front->data = x;	//add x to data field of that node (aka put data in node)
		front->next = 0;	//the next node does not exist, so front->next = null
		back = front;		//because there's only one node, front = back of list 
	}
	else
	{						//if list is NOT empty
		node* p = new node;	//create new node, have temporary pointer point to that
		p->next = 0;		//p is last element: the node after p does not exist, so it's null
		p->data = x;		//initialize the last node in list	(aka add data to it)
		back->next = p;		//now the next node after back is p 
		back = p;			//now p IS the new back of the list 
	}
}

int main()
{
	node* front = 0;
	node* back = 0;
	for (int i = 1; i <= 6; i++)
	{
		add_back(front, back, i);
	}
	fun(front);
	return 0;
}