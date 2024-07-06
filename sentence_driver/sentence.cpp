#include <iostream>
#include <string>
#include "sentence.h"

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: defualt constructor
Pre-Conditon: function is called, definitions defined
Post-Condition: front & back pointers of list are initialized
Description: front & back pointers will be initialized to null, indicating an empty list.
**********************************************************************************************************************************************************/
sentence::sentence()
{	front = back = 0; }

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: explicit-value constructor
Pre-Conditon: object declared
Post-Condition: object initialized to explicit value
Description: initializes object to specific value
**********************************************************************************************************************************************************/
sentence::sentence(const string& s)
{
	string str = s;			//add_back only works with type "string&", NOT "const string&"
	if (front == 0)			//if list is empty
	{	add_back(str); }	//add "str" to the back of current list
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: copy constructor
Pre-Conditon: current & parameter list declard
Post-Condition:  a new list has been defined, which is a copy of the original
Description:  The function performs a copy of the formal parameter org.
**********************************************************************************************************************************************************/
sentence::sentence(const sentence& org)
{
	word* q = org.front;		//front of original (parameter) list
	front = 0;					//empty list so we can copy properly
	while (q != 0)				//traverse (iterate through list)
	{
		(*this).add_back(q->term);		//add org's list item to current object's list
		q = q->next;					//move to next node in the original list
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: destructor
Pre-Conditon: list declared
Post-Condition: memory allocated towards list is no longer allocated
Description: this de-allocates memory for lists
**********************************************************************************************************************************************************/
sentence::~sentence()
{
	cout << "Destructor has been called\n";
	while (front != 0)		//while memory is allocated
	{						//deletes from front to back
		word* p = front;	//point to front of list
		front = front->next;//prepare for next deletion
		delete p;			//delete allocated memory representing front of list
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: length
Pre-Conditon: list declared
Post-Condition: string length of list is returned
Description: this function returns the string length of entire list
**********************************************************************************************************************************************************/
int sentence::length()
{
	word* p = front;//initialize p to front to help in the traversal of the list
	int len = 0;	//length of sentence
	while (p != 0)  //traverse (iterate through list)
	{				//^stop when there are no more nodes
		len += p->term.length();	//add length of each word (node) to get sentence length 
		p = p->next;				//move to next node in the list
	}
	return len;		//return length of sentence

}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: add_back
Pre-Conditon: list & string parameter declared
Post-Condition: string is added to the back of list
Description: adds string to back of list in node format 
**********************************************************************************************************************************************************/
void sentence::add_back(string& s)
{
	if (front == 0)			//if list is empty
	{						
		front = new word;	//front points to a new node memory 
		front->term = s;	//add s to data field of that node (aka put data in node)
		front->next = 0;	//the next node does not exist, so front->next = null
		back = front;		//because there's only one node, front = back of list 
	}
	else
	{						//if list is NOT empty
		word* p = new word;	//create new node, have temporary pointer point to that
		p->next = 0;		//p is last element: the node after p does not exist, so it's null
		p->term = s;		//initialize the last node in list	(aka add data to it)
		back->next = p;		//now the next node after back is p 
		back = p;			//now p IS the back of the list 
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: operator<<
Pre-Conditon: list declared
Post-Condition: list is displayed to screen
Description: displays list to screen with chaining
**********************************************************************************************************************************************************/
ostream& operator<<(ostream& out, const sentence& s)
{
	word* p = s.front;		//pointer to help traverse through the list
	while (p != 0)			//loop for iterations
	{
		out << p->term;		//display current term
		p = p->next;		//prepare to display next term
	}
	return out;				//return for chaining
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: operator=
Pre-Conditon: string is passed, list declared
Post-Condition: list is assigned the contents of string
Description: assigns list the value of string
**********************************************************************************************************************************************************/
void sentence::operator=(const string& s)
{
	front = 0;			//empty the list
	back = 0;			//empty the list
	word* p = front;	//pointer for traversal
	string add_me = "";	//variable to help isnert each word into list
	for (int x = 0; x < s.length(); ++x)
	{	
		add_me += s[x];	//add each character to string word
		//if at end of string, add word to list
		if (x + 1 == s.length())
		{//add word to list
			add_back(add_me);
		}
		//if this index IS a letter||number & the next is NOT
		else if ( ( (s[x] >= 'A' && s[x] <= 'z') || (s[x] >= '0' && s[x] <= '9') )
			&& !( ( s[x + 1] >= 'A' && s[x + 1] <= 'z') || (s[x + 1] >= '0' && s[x + 1] <= '9') ))
		{//then we have a word to add to list
			add_back(add_me);
			add_me = "";
		}//else if this character is NOT a letter||number, but the next one IS
		else if ( !( (s[x] >= 'A' && s[x] <= 'z')||(s[x] >= '0'&&s[x] <='9') ) 
			&& ( (s[x + 1] >= 'A' && s[x + 1] <= 'z') || (s[x+1] >= '0' && s[x+1] <= '9') ))
		{//add non-dictionary word to list
			add_back(add_me);
				add_me = "";
		}
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: operator=
Pre-Conditon: sentence is passed, list declared
Post-Condition: list is assigned the contents parameter sentence list
Description: assigns list the value of parameter sentence list
**********************************************************************************************************************************************************/
sentence& sentence::operator=(const sentence& w) 
{ 
	front = 0;			//empty the list
	back = 0;			//empty the list
	word* q = w.front;	//pointer to help traverse through list
	while (q != 0)		//while node exist
	{
		add_back(q->term);	//add term of each node in w
		q = q->next;		//prepare next node to be added
	}
	return (*this);			//return this for chaining 
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: operator+
Pre-Conditon: current list & argument list declared
Post-Condition: the contents of argument list are added to the back of current list
Description: adds the nodes of argument list to back of current list
**********************************************************************************************************************************************************/
void sentence::operator+(sentence& B)
{
	word* q = B.front;			//pointer to help traverse through argument list
	while (q != 0)				//while node exist
	{
		add_back(q->term);		//add it to the back of current list
		q = q->next;			//prepare next node to be added
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: isEqual
Pre-Conditon: list object & argument are declared
Post-Condition: bool value is returned
Description: returns whether or not current list is the same as argument list
**********************************************************************************************************************************************************/
bool sentence::isEqual(sentence& B)
{
	word* p = front;			//pointer to help store current list in string
	word* q = B.front;			//pointer to help store argument list in string
	string this_str = "";		//string to store current list
	string that_str = "";		//string to store argument list
	while (p != 0)				//loop for storing current list in string 
	{							//while node exist 
		this_str += p->term;	//add contents to string
		p = p->next;			//prepare next node to be added
	}
	while (q != 0)			//loop for storing argument in string
	{						//while node exist
		that_str += q->term;//add contents to string
		q = q->next;		//prepare next node to be added
	}
	return this_str == that_str;	//return true or false if they are equal
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: remove
Pre-Conditon: string & object declared
Post-Condition: if string exist in list, it is removed	
Description: removes string from list if it's there
**********************************************************************************************************************************************************/
void sentence::remove(const string& s)
{
	//p=0 if string not in list; otherwise p holds the address of the node key is in.
	word* p = search(s); //check to see if string in list

	//string was not found
	if (p == 0)  //string was not found in the list
	{/*Don't do anything*/ }
	else  //if string  WAS found in the list
	{
		//if string is first node & If there is only one node in list
		if (p == front && front == back)
		{//remove it (p)
			delete p;			//remove node
			front = back = 0;	//empty the list
		}
		//string is first node & if there are multiple nodes in list
		else if (p == front)
		{//remove it (p)
			front = front->next;//the NEW front is the NEXT node
			delete p;			//remove node we no longer want
		}
		//front does not contain key & there are at least 2 nodes
		else
		{//remove it (p)
			word* back_ptr = front;
			//find node before the node that contains string
			while (back_ptr != 0 && back_ptr->next != p)
			{
				back_ptr = back_ptr->next;//go through each node until node before p is found
			}
			//if key is in the last node
			if (p == back)
			{//set back to node before last node
				back = back_ptr;			//the NEW back is node before p
			}
			back_ptr->next = p->next;		//next node after back_ptr is NOT p anymore. it's p->next
			delete p;						//remove p from list
		}
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: search
Pre-Conditon: string is passed & list declared
Post-Condition: pointer to string argument in list is returned, if it exist in list
Description: this function is meant to help with remove function. it returns the location of 
key in list if it exist, otherwise 0 is returned. 
**********************************************************************************************************************************************************/
word* sentence::search(const string& key)
{
	word* p = front;//pointer to help iterate through list
	while (p != 0)  //traverse (iterate through list)
	{
		if (p->term == key) //check if key equal to data in current node
		{
			return p;       //key located, return its location in list
		}
		p = p->next; //move to next node in the list
	}
	return p; //return location if found, otherwise 0 (null)
}
