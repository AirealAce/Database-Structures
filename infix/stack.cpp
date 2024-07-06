#include <iostream>
#include <string>
#include "stack.h"

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: defualt constructor
Pre-Conditon: stack is declared
Post-Condition: stack is initialized
Description: member function that initializes stack to 0
**********************************************************************************************************************************************************/
stack::stack()
{	s_top = 0;	}

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
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: pushh
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
Name: infix
Pre-Conditon: stack is declared, member functions are defined
Post-Condition: an infix version of the exp parameter is returned
Description: function that takes a postfix expression & returns the infix version
**********************************************************************************************************************************************************/
string infix(string exp)
{//note: I think infix expressions are the same as telescoping form from discrete math
	char token;						//character in exp
	string tokenSTR,				//string version of token: used for certain functions
		topToken, otherToken;		//token on top of opStack & the next node, respectively 
	stack opStack;					//stack of operands
	int operands = 0, operators = 0;//number of operands & operators, respectively
	string sample = "";				//sample string: used for combining characters & nodes
	int y = 0;						//loop variables
	if (exp.empty()) return "";		//if expression is empty, return empty string
	for (y = 0; y < exp.length(); y++)
	{//otherwise we count operands & operators to check if expression is legal
		if (exp[y] >= 'A' && exp[y] <= 'Z' || exp[y] >= 'a' && exp[y] <= 'z')
		{//if character in exp is a letter
			operands++;
		}
		else if (exp[y] == '+' || exp[y] == '-' || exp[y] == '*' || exp[y] == '/')
		{//if character in exp is an operator
			operators++;
		}
	}
	if (operators >= operands)
	{//error check for too many operators
		cout << "ERR0R: \t|"<<"too many operators and not enough operands" << endl;
		return "";
	}
	else if (operands > operators + 1)
	{//error check for too many operands
		cout << "ERR0R: \t|"<< "too many operands and not enough operators" << endl;
		return "";
	}
	else
	{//if expression is valid, we may generate the infix
		operands = 0; operators = 0;		//reset these variables for usage in algorithm
		for (int i = 0; i < exp.length(); i++)
		{//run algorithm until we reach end of expression
			token = exp[i];		//record the first character in the expression
			switch (token)
			{
			case ' ': break;       //if character is blank, do nothing
			case '+': case '-': case '*': case '/':
					if (operands >= 2)
					{//if we have 2 operands, it is time to make a sub-expression
						topToken = opStack.top();	//store the top node
						opStack.pop();				//remove it from stack
						otherToken = opStack.top();	//store the preceding node
						opStack.pop();				//remove it from stack
						//create the sub expression
						sample = "(" + otherToken + " " + token + " " + topToken + ")";
						opStack.push(sample);	//add sub expression to stack in place of original nodes
						operands -= 1;			//we now have 1 less operand because of the combination
						sample = "";			//empty sub expression in preparation for next combination
					}				
				break;
			default:
				if (exp.length() == 1 && (exp[0] >= 'A' && exp[0] <= 'Z' || exp[0] >= 'a' && exp[0] <= 'z'))
				{//if expression is one letter, we make the expression right now
					tokenSTR = "(";				//preparation to create expression
					tokenSTR.append(1, token);	//adding character to expression
					tokenSTR += ")";			//expression created
				}
				else {//otherwise
					tokenSTR = "";				//empty the string
					tokenSTR.append(1, token);	//tokenSTR = token
				}
				opStack.push(tokenSTR);		//add character to stack
				operands++;					//additional opperand in stack
				break;
			}
		}
		return opStack.top();	//the stack now only contains an infix expression
	}
}