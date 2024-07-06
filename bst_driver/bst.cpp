#include <iostream>
#include <string>
#include "bst.h"

//Note:	BST- every node (excluding leaves) have at least 2 children. A leaf has none. 
//		lchild < parent, rchild > parent, root = first node
//		in-order successor: right child's most left descendent

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: defualt constructor
Pre-Conditon: definitions defined, correct file in folder
Post-Condition: bst created & initialized to data recieved from file
Description: a binary search tree is created using data from file
**********************************************************************************************************************************************************/
bst::bst()
{
	cout << "The default constructor has been called:\n";

	//open file
	ifstream in;
	in.open("county_data.txt");
	if (in.fail())
		cout << "Input file did not open correctly" << endl;
	else
	{//else read into string file
		//variable - these help read data 
		string str = "", str_name = " ", str_pop = "",item_name="";
		int x = 0, y = 0, z = 0;
		double item_num;
		while (!in.eof())
		{//^while NOT at end of file:
			str = "", str_pop = "", item_name = "";		//empty the strings
			y = 0, z = 0;								//empty the integers
			//read file line into sample string		
			getline(in, str);			//use getline to capture whitespaces
			//use loop to read the name & population from str 
			for (x = 0; x < str.length(); ++x) {
				//if character is a letter OR ('.'||a whitespace) followed by a letter||whitespace, 
				// add it to name
				if (str[x] >= 'A' && str[x] <= 'z' || (str[x] == '.' || str[x] == ' ') && 
					( (str[x + 1] >= 'A' && str[x + 1] <= 'z') || str[x+1]==' ') ) {
					item_name.resize(++y, str[x]);	//read str[x] into name[y] then resize name to ++y
				}
				else 
				{//once name is read, we read numbers 
					str_pop.resize(++z, str[x]);	//read str[x] into pop[z] then resize num to ++z
				}
			}
			//convert str_pop to type double
			item_num = stod(str_pop);
			//echo the sample output in file to screen per professors' instruction
			//Formatting
			cout.precision(0);			//no values after decimal
			cout.setf(ios::fixed);		//all numbers will be displayed the same
			cout << left << setw(30) << item_name << item_num << endl;
			//insert name & number into bst
			insert(item_name, item_num);
		}
	}
	in.close();
	cout << endl;
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: empty
Pre-Conditon: bst declared 
Post-Condition: boolean value returned representing whether bst is empty or not
Description: returns true if tree is empty
**********************************************************************************************************************************************************/
bool bst::empty()
{
	return (root == 0);
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: auxillary::insert
Pre-Conditon: bst declared, functions defined
Post-Condition: insert() is called starting from root
Description: calls insert() to insert into bst
**********************************************************************************************************************************************************/
void bst::insert(const string& item, const double& population)
{
	insert(root, item, population);	//notice root is being passed, as well
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: insert
Pre-Conditon: auxillary function called, indicating we start from root
Post-Condition: bst contains an additional node
Description: inserts item & corresponding population into bst as a leaf
**********************************************************************************************************************************************************/
void bst::insert(treenode*& loc_ptr, const string& item, const double& population)
{
	if (loc_ptr == 0)
	{//if leaf does not exist
		loc_ptr = new treenode;					//allocate memory for new node
		loc_ptr->lchild = loc_ptr->rchild = 0;	//lchild & rchild don't exist as this is a leaf
		loc_ptr->county_name = item;			//attach data to node
		loc_ptr->population_size = population;	//^
	}
	else if (loc_ptr->county_name > item)		//lchild < parent implies new leaf belongs on the left
		insert(loc_ptr->lchild, item, population);	//so insert at the left
	else if (loc_ptr->county_name < item)		//rchild > parent implies new leaf belongs on the right
		insert(loc_ptr->rchild, item, population);	//so insert at the right
	else//otherwise, item==loc->ptr; meaning it is already exist in the bst
		cout << "the item is already in the tree\n";
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: auxillary::search_tree
Pre-Conditon: str passed, functions defined, bst declared
Post-Condition: function is called, root is passed, ptr is returned
Description: calls search_tree to search for item in bst
**********************************************************************************************************************************************************/
treenode* bst::search_tree(string item)
{
	return search_tree(root, item);
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: search_tree
Pre-Conditon: auxillary function called, indicating to start from root
Post-Condition: ptr to item is returned if it exist in bst, otherwise 0 is returned 
Description: returns location of item in bst via ptr
**********************************************************************************************************************************************************/
treenode* bst::search_tree(treenode* loc_ptr, string item)
{//note, because of auxillary, this function starts from the root
	if (loc_ptr != 0)
	{//if loc_ptr != 0, then there's still locations to search
		if (loc_ptr->county_name == item)	//if item found in bst
			return loc_ptr;					//return location (ptr)
		else if (loc_ptr->county_name > item)	//lchild < parent imples we search on the left
			return search_tree(loc_ptr->lchild, item);	//search starting on the left of node
		else if (loc_ptr->county_name < item)	//rchild > parent implies we search on the right
			return search_tree(loc_ptr->rchild, item);	//search starting on the right of node
	}
	else//location ptr== 0
		return loc_ptr;	//implies item not in tree
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: auxillary::county_ranges
Pre-Conditon: bst declared, function defined
Post-Condition: function called starting from root
Description: county_ranges is called starting from root
**********************************************************************************************************************************************************/
void bst::county_ranges(const string& min_name, const string& max_name)
{
	county_ranges(root, min_name, max_name);
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: county_ranges
Pre-Conditon: auxillary function called to indicate we start from root
Post-Condition: data between min_name & max_name (inclusive) are displayed to the screen
Description: displays names in bst between min_name & max_name (inclusively) in alphabetical order
**********************************************************************************************************************************************************/
void bst::county_ranges(treenode*& loc_ptr, const string& min_name, const string& max_name)
{
	if (loc_ptr != 0)
	{//while node(s) exist in bst
		county_ranges(loc_ptr->lchild, min_name, max_name);	//print starting from the smallest (lchild < parent)
		if (loc_ptr->county_name >= min_name && loc_ptr->county_name <= max_name)//at the least child
			cout << loc_ptr->county_name << endl;//print name if it is in range
		county_ranges(loc_ptr->rchild, min_name, max_name);	//after printing lchild & parent, print rchild
		//then print starting from parent's parent, excluding lchild, which was alrdy printed...draw the bst...
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: auxillary::del_name
Pre-Conditon: bst declared, function defined
Post-Condition: function called to de-allocate memory using root as the reference starting point
Description: calls function to de-allocate memory
**********************************************************************************************************************************************************/
void bst::del_name(string item)
{
	del_name(root, item);
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: del_name
Pre-Conditon: auxillary function called 
Post-Condition: de-allocates memory corresponding to item if it exist in bst
Description: de-allocates memory corresponding to item in bst if it exist
**********************************************************************************************************************************************************/
void bst::del_name(treenode*& loc_ptr, string item)
{
	if (loc_ptr == 0)//implies item on in bst
		cout << "item not in tree\n";

	else if (loc_ptr->county_name > item)//lchild < parent implies search/delete on the left
		del_name(loc_ptr->lchild, item);	//item should be on the left
	else if (loc_ptr->county_name < item)//rchild > parent implies search/delete on the right
		del_name(loc_ptr->rchild, item);	///item should be on the right
	else
	{//otherwise, item found
		treenode* ptr;				//pointer to help manage bst
		if (loc_ptr->lchild == 0)	
		{//if there's no left child
			ptr = loc_ptr->rchild;	//prepare to move the right child into parent's place
			delete loc_ptr;			//delete the parent
			loc_ptr = ptr;			//the new parent is the right child, even if right child does not exist
		}
		else if (loc_ptr->rchild == 0)
		{//if there's no right child
			ptr = loc_ptr->lchild;	//prepare to move the left child into parent's place
			delete loc_ptr;			//remove the parent
			loc_ptr = ptr;			//the new parent is the left child
		}
		else
		{//otherwise, both children exist, & we must use the successer
			ptr = inorder_succ(loc_ptr);					//point to successor
			loc_ptr->county_name = ptr->county_name;		//replace parent with successor
			loc_ptr->population_size = ptr->population_size;//^	
			del_name(loc_ptr->rchild, ptr->county_name);
			//^ delete extra copy, starting from current_node->rchild (because successor was & is always on the right)
		}
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: inorder_succ
Pre-Conditon: function declared, tree node passed
Post-Condition: ptr to successor of treenode is returned
Description: returns to pointer to successor of node
**********************************************************************************************************************************************************/
treenode* bst::inorder_succ(treenode* loc_ptr)
{
	treenode* ptr = loc_ptr->rchild;	//successor is always from the right child
	while (ptr->lchild != 0)
	{//successor = rchild's left most child
		ptr = ptr->lchild;	//point to next left child
	}
	return ptr;	//return pointer to left most child
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: auxillary::print_tree
Pre-Conditon: bst declared
Post-Condition: function called
Description: calls print_tree starting from root
**********************************************************************************************************************************************************/
void bst::print_tree()
{
	print_tree(root);
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: print_tree
Pre-Conditon: auxillary function called to indicate we start from root
Post-Condition: entire tree is displayed
Description: prints every name in bst in alphabetical order
**********************************************************************************************************************************************************/
void bst::print_tree(treenode*& loc_ptr)
{//recursion
	if (loc_ptr != 0)
	{//if there's nodes to print
		print_tree(loc_ptr->lchild);			//lchildren are least, so print from left first
		cout << loc_ptr->county_name << endl;	//once at most left node, print name
		print_tree(loc_ptr->rchild);			//then print right child of that node
	}
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: destructor
Pre-Conditon: bst declared, function defined
Post-Condition: all memory allocated to bst is de-allocated
Description: de-allocates memory for bst
**********************************************************************************************************************************************************/
bst::~bst()
{
	cout << "The Destructor called" << endl;
	while (root != 0)
	{//while their are still nodes to delete
		del_name(root->county_name);	//delete them
	}
}


/***********************FUNCTION HEADER ******************************************************************************************************************
Name: auxillary::sorted_info
Pre-Conditon: bst declared
Post-Condition: sorted_info is called to print to file
Description: calls sorted_info using ofstream starting from root
**********************************************************************************************************************************************************/
void bst::sorted_info()
{
	ofstream out;
	//Format for output in FILE
	out.precision(0);			//no values after decimal
	out.setf(ios::fixed);		//all numbers will be displayed the same
	//variable of type output file stream
	out.open("county_info.txt", fstream::app);	//assign file to out & open it
	sorted_info(out, root);						//the function call
}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: sorted_info
Pre-Conditon:	auxillary function called
Post-Condition: entire bst is printed to file
Description: prints bst names & corresponding numbers to file in alphaebtical order
**********************************************************************************************************************************************************/
void bst::sorted_info(ostream& out, treenode*& loc_ptr)
{//recurssion
	if (loc_ptr != 0)
	{//if there's nodes to print
		sorted_info(out, loc_ptr->lchild);			//print lchilds first, as they are less than parent & sibling
		out << left << setw(30) << loc_ptr->county_name << loc_ptr->population_size << endl;
		sorted_info(out, loc_ptr->rchild);			//only after left children are printed may we print right 
	}

}

/***********************FUNCTION HEADER ******************************************************************************************************************
Name: empty_tree
Pre-Conditon: functions defined, tree declared
Post-Condition: de-allocates all memory for bst
Description: de-allocates memory that was allocated towards bst
**********************************************************************************************************************************************************/
void bst::empty_tree()
{
	while (root != 0)
	{//while there's nodes to delete
		del_name(root->county_name);
	}
}

