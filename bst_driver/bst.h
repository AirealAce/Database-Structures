#pragma once			//include the source file only once in a single compilation
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

#ifndef BST_H			//if not defined
#define BST_H			//define file

class treenode
{//node for binary search tree
public:
	string county_name;			//identification field
	double population_size;		//data field
	treenode* lchild, * rchild;	//left/right children for tree implementation - pointer to other treenodes
};

class bst
{
public:
	bst();												//store the data file (“county_data.txt”) into initial bst
	~bst();												//de-allocates dynamic memory allocated for tree
	bool empty();										//return true if bst is null; otherwise false is retured
	void insert(const string& item, const double& population);				//auxiliary function: calls function
	void insert(treenode*&, const string& item, const double& population);	//inserts an item into tree (in order)
	void del_name(string item);												//auxiliary function: calls function
	void del_name(treenode*& loc_ptr, string item);							//function deletes an item from the bst
	treenode* search_tree(string item);										//auxiliary fucntion: calls function
	treenode* search_tree(treenode*, string item);				//returns ptr to node in bst where county_name==item 
	treenode* inorder_succ(treenode*);					//returns a ptr to inorder successor, based on county name
	void county_ranges(const string& min_name, const string& max_name);		//auxiliary function: calls function
	void county_ranges(treenode*&, const string& min_name, const string& max_name); 
	//^ displays county names between min_name and max_name, inclusive.
	void print_tree();														//auxiliary function: calls function
	void print_tree(treenode*&);											//display each county, in order
	void sorted_info();														//auxiliary function: calls function
	void sorted_info(ostream&, treenode*&);							//prints county record to file “county_info.txt” in alphabetical order
	void empty_tree();										//de-allocate all nodes that were allocated to the bst
private:
	treenode* root;		//first node in tree/top/peak
};

#endif