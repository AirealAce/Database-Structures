/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Aaron P. Mills                            TOTAL POINTS:  25
COURSE:  COP 3530								DUE DATE:  11/10/2021
Assignment Name:  Assignment#6                 Professor:  Dr. Petrie
Description:  This program includes double-linked queues & essential functions. 
******************************************************************************************************/
#include<iostream>
#include "bqueue.h"
using namespace std;

int main()
{
	bqueue k;
	k.enqueue(60);
	k.print();
	k.enqueue(20);
	k.enqueue(30);
	k.print();
	k.enqueue(10);
	k.print();
	k.enqueue(50);
	k.enqueue(40);
	k.print();
	bqueue j = k;
	j.dequeue();
	j.print();
	j.dequeue();
	j.dequeue();
	j.dequeue();
	j.print();
	j.dequeue();
	j.dequeue();
	j.print();
	j.dequeue();
	j.dequeue();
	return 0;
}
