#include <iostream>
#include <iomanip>
#include <string>
#include "towers.h"

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: defualt constructor
Pre-Conditon: stack is declared
Post-Condition: stack is initialized
Description: member function that initializes stack to 0
**********************************************************************************************************************************************************/
stack::stack()
{
	s_top = 0; name = ""; count = 0;
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: copy constructor
Pre-Conditon: stack is initialized
Post-Condition: current stack is copied into another
Description: member function that copies current stack into another stack
**********************************************************************************************************************************************************/
stack::stack(const stack& Org)
{
	(*this).s_top = 0;			//empty the current stack
	stack temp;					//temporary stack for copying
	stack_node* p = Org.s_top;	//pointer to traverse through paramater stack
	while (p != 0)
	{//while not at end of stack
		temp.push(p->data);		//add contents (data) of org's stack elements to temporary's 
		p = p->next;			//prepare for next node
	}//note that temp is now the reversed version of p (Org)

	p = temp.s_top;				//point to  temporary stack
	while (p != 0)
	{//while not at end of stack
		(*this).push(p->data);	//add contents (data) of org's stack elements to CURRENT stack
		p = p->next;			//prepare for next node
	}//note: org is being copied in its original order into this
	//note: count should be updated naturally because of pop & push
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: destructor
Pre-Conditon: stack was initialized
Post-Condition: stack is empty
Description: member function that removes ALL nodes from stack
**********************************************************************************************************************************************************/
stack::~stack()
{
	while (s_top != 0)
	{//while not at end of stack
		pop();	//remove each node, & point to next node
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: pop
Pre-Conditon: stack is initialized
Post-Condition: stack has one less node
Description: member function taht removes the top node from stack
**********************************************************************************************************************************************************/
void stack::pop()
{
	stack_node* p;		//pointer for traversal
	if (s_top != 0)
	{//if stack contains nodes
		p = s_top;				//point to the top
		s_top = s_top->next;	//top is now the next node in the stack
		delete p;				//because we removed the original top element
		--count;				//1 less node
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: push
Pre-Conditon: stack is initialized
Post-Condition: stack contains an aditional node
Description: member function that adds a new node the stack, which becomes the new top
**********************************************************************************************************************************************************/
void stack::push(const stack_element& item)
{
	stack_node* p = new stack_node;		//allocate memory for new stack node
	p->data = item;						//the contents of the node = item
	p->next = s_top;					//the next node in stack is the PREVIOUS top
	s_top = p;							//because the NEW top is the new element we created
	string s = top(); 
	s = s[0];
	s_top->size = stoi(s);
	++count;							//1 more node
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: print
Pre-Conditon: stack is initialized
Post-Condition: stack is displayed to screen
Description: member function that displays contents of stack to screen, starting from top of the stack
**********************************************************************************************************************************************************/
void stack::print()
{
	for (stack_node* p = s_top; p != 0; p = p->next)
	{//start from the top of the stack until there is no more elements
		cout << p->data << endl;	//print data of each node to the screen
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: top
Pre-Conditon: stack is initialized
Post-Condition: the top node's data is returned
Description: member function that returns the data of the top node in the stack
**********************************************************************************************************************************************************/
stack_element stack::top()
{
	if (s_top == 0)
	{//exit if stack is empty
		exit(1);
	}
	else
	{//otherwise, return the data of the stack's top node
		return s_top->data;
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: print_stacks
Pre-Conditon: stacks declared
Post-Condition: displays stacks to screen
Description: displays stacks to screen on the same line, with each stack centered around variable peg
**********************************************************************************************************************************************************/
void print_stacks(stack& A, stack& B, stack& C)
{
	stack_node* a = A.s_top; stack_node* b = B.s_top; stack_node* c = C.s_top;	//traversal variables
	int count = 0;	//loop counter
	//deciding how many lines to print based on stack sizes
	if (A.count >= B.count && A.count >= C.count) count = A.count;
	else if (B.count >= A.count && B.count >= C.count) count = B.count;
	else count = C.count; 
	for (int x = 0; x<count; ++x)
	{//start from the top of the stack until there is no more elements
		if (a == 0 || x < count-A.count) cout << "        ";
		else { cout << a->data; a = a->next; }
		if (b == 0 || x < count - B.count) cout << "        ";
		else { cout << b->data; b = b->next; }
		if (c == 0 || x < count - C.count) cout << "        ";
		else { cout << c->data; c = c->next; }
		cout << endl;
	}
	cout << "    " << A.name << "   " << "    " << B.name << "   " << "    " << C.name << "   " << endl;

}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: move
Pre-Conditon: player enters src & dst stacks that exist
Post-Condition: if game rules are followed, disk from src will be moved to dst
Description: moves disk from src to disk if rules are followed; otherwise, an alert appears
**********************************************************************************************************************************************************/
void move(stack& src, stack& dst, int& moves)
{
	cout << "Action: Move disk from tower " << src.name << " to tower " << dst.name << ": " << endl;
		if (src.empty())
			cout << "ALERT: This move is illegal! The source stack is empty!!!" << endl;
		else if (dst.empty() || src.s_top->size < dst.s_top->size)
		{//we can swap if dst stack empty or the disk is larger than src's disk
			string s_top = src.top();
			src.pop();
			dst.push(s_top);
			++moves;
		}
		else if (src.s_top->size > dst.s_top->size) 
			cout << "ALERT: This disk is too large to go there!!!" << endl;
		else
			cout << "ALERT: This move is illegal..." << endl;
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: clear
Pre-Conditon: stack was initialized
Post-Condition: stack is empty
Description: function that removes ALL nodes from stack
**********************************************************************************************************************************************************/
void stack::clear()
{
	while (s_top != 0)
	{//while not at end of stack
		pop();	//remove each node, & point to next node
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: newGame
Pre-Conditon: stack was initialized & passed
Post-Condition: moves set to 0 and stacks are prepared for a new game
Description: stacks B and C are emptied, with A holding the defualt tower, and number of moves = 0
**********************************************************************************************************************************************************/
void newGame(stack& A, stack& B, stack& C, int& moves)
{
	A.clear(); B.clear(); C.clear(); moves = 0;
	A.push("5 XXXXX "); A.push("3  XXX  "); A.push("1   X   ");
	A.rename("A"); B.rename("B"); C.rename("C");
}
