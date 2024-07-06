
#include "state.h"
#include <iomanip>  //need to use formatting manipulators

/***********************FUNCTION HEADER ******************************************************************************************************************
Name:  Default Constructor
Pre-Conditon: The count, capacity, and the dynamic array (pop_DB) have not been initialized.
Post-Condition: The count, capacity, and the dynaic array (pop_DB) have been initialized.
Description:  The function initiailizes the state (private data) of the class state_class. It reads 
the data stored in the datafile "census2020_data.txt" into the dynamic array, pop_DB.  
Initially, count is set to 0, capacity to 5, and pop_DB is allocated 5 cells.  If pop_DB become full,
double_size is called, which doubles the capacity of pop_DB.
**********************************************************************************************************************************************************/
state_class::state_class()
{
	//intially count, capacity, and pop_DB are initialized with the following values:
	count = 0;
	capacity = 5;
	pop_DB = new population_record[capacity];		//creating a dynamic of array

	cout << "The default constructor has been called:\n";

	//open file
	ifstream in;
	in.open("census2020_data.txt");
	if (in.fail())
		cout << "Input file did not open correctly" << endl;
	else
	{   //else read into string file

		//variable - these help read data into array 
		string str = "", str_state =" ", str_pop = "";
		int x=0, y=0, z=0;
		//allocate memory for array
		pop_DB = new population_record [capacity];
		while (!in.eof())
		{//^while NOT at end of file:
			str = "", str_pop = "";		//empty strings
			y = 0,z=0;					//empty integers
			//read file text into STRING		
			getline(in, str);			//use getline to capture whitespaces
			//Use loop to read the state's name & population from str 
			for (x = 0; x < str.length(); ++x) {
				pop_DB[count].state_name[y] = str[x];		//add the first letter to the string
				//if next character is a letter OR a whitespace followed by a letter, add it to the 
				//state's name
				if (str[x] >= 'A' && str[x] <= 'z' || str[x] == ' ' && (str[x+1] >= 'A' && str[x+1] <= 'z')) {
					pop_DB[count].state_name.resize(++y, str[x]);
				}
				else {
					//once string is read, we read numbers 
					str_pop.resize(++z, str[x]);
				}
			}
			//convert str_pop to type double & store it in the array
			pop_DB[count].population = stod(str_pop);
			++count;	//number of items in array increases by 1 
			////if the array is full
			if (Is_Full()) {
				//double the size
				double_size();
			}
		}
	}
	in.close();
}

/******************************************************************************************************************************************************
//Name: Copy Constructor
//Precondition: another array has been defined
//Postcondition: a new array has been defined, which is a copy of the original
//Description:  The function performs a deep copy of the formal parameter org.
******************************************************************************************************************************************************/
state_class::state_class(const state_class & org)
{
	(*this).pop_DB = new population_record [org.capacity];	//create new array with org's size
	//^ this array holds data of type population_record 
	(*this).count = org.count;					//give new array the count of org
	for (int i = 0; i < (*this).count; i++) {
		//copy old array into new array
		(*this).pop_DB[i] = org.pop_DB[i];
	}
}

/******************************************************************************************************************************************************
//Name: Destructor
//Precondition: The array is allocated memory.
//Postcondition: The array is no longer allocated memory.
//Decription: de-allocates all memory allocated to STR.  This will be the last function to be called
(automatically by the compiler) before the program is exited.
******************************************************************************************************************************************************/
state_class::~state_class()
{
	count = 0;
	capacity = 0;
	delete[] pop_DB;
}

/******************************************************************************************************************************************************
Name: double_size
Pre-Condition: dynamic array has been defined
Post-Condition: the capicity (size) of the array has been doubled 		
Description: this function doubles the size of a dynamic array
******************************************************************************************************************************************************/
void state_class::double_size()
{
	capacity *= 2;	//double the size
	//allocate memory 
	population_record* temp = new population_record [capacity];	//create a temporary array with the 
	//new size
	//then copy contents from pop_DB array into temp array 
	for (int i = 0; i < count; ++i) {
		temp[i] = pop_DB[i];
	}
	//delete old memory used for array pop_DB
	delete[] pop_DB;
	//point to the new array memory location, where the size has been doubled 
	pop_DB = temp;
}

/******************************************************************************************************************************************************
Name: operator+
Pre-Condition: a dynamic array has been defined
Post-Condition: the dynamic array now holds an additional element
Description: this function adds a population record to the array of records.
******************************************************************************************************************************************************/
void state_class::operator+(const population_record& r)
{
	//add r's state name & population to array
	pop_DB[count].state_name = r.state_name;
	pop_DB[count].population = r.population;
	++count; //count increases because we just added a new element 

	//if the array is full
	if (Is_Full()) {
		//double the size
		double_size();
	}
}

/******************************************************************************************************************************************************
Name: Search
Pre-Condition: an array has been defined & state's name has been passed to function
Post-Condition: the location of a state in the array has been stated (if state exists)
Description: this functions returns -1 OR the location of a state within the array (if state exists)
******************************************************************************************************************************************************/
int state_class::Search(const string& state)
{
	//go through each element of the array
	for (int x = 0; x < count; ++x) {
		//find the state name that matches the key
		if (pop_DB[x].state_name == state) {
			//return that location in the array
			return x;
		}
	}
	//if not in array, return -1
	return -1;
}


/******************************************************************************************************************************************************
Name: Remove
Pre-Condition: array has been defined & state name has been passed to function
Post-Condition: the array has lost all elements with that state's name
Description: this function removes state's from array's records if it is there
******************************************************************************************************************************************************/
void state_class::Remove(const string& state)
{
	//while the key item exist in the array 
	if (Search(state) > -1) {
		while (Search(state) > -1) {
			int rem = Search(state); //this is the location of the item to remove
			//each element must be shifted to account for the loss 
			for (int x = rem; x < count - 1; ++x) {
				pop_DB[x] = pop_DB[x + 1];
			}
			--count;	//we lose one element
		}
	}
	else
		cout << "This data does not contain " << state << endl;
}


/******************************************************************************************************************************************************
Name: Print_ALL_To_File
Pre-Condition: the array has been defined with file name passed to function
Post-Condition: a file is created &/or written to. It will display all elements of array
Description: This function writes every array element to file. 
******************************************************************************************************************************************************/
void state_class::Print_ALL_To_File(const string& filename)
{
	ofstream out;		//variable of type output file stream
	out.open(filename, fstream::app);	//open file

	//Format for FILE
	out.precision(0);			//no values after decimal
	out.setf(ios::fixed);		//all numbers will be displayed the same

	for (int x = 0; x < count; ++x) {
		//Print to FILE
		out << left << setw(30) << pop_DB[x].state_name << pop_DB[x].population << endl;
	}
	out.close();	//close output file 
}
/******************************************************************************************************************************************************
Name: Print_ALL
Pre-Condition:	array has been defined
Post-Condition:	array contents are displayed to screen
Description: this function displays array contents to the screen
******************************************************************************************************************************************************/
void state_class::Print_ALL()
{
	// Format for CONSOLE
	cout.precision(0);			//no decimal places
	cout.setf(ios::fixed);		//all numbers displayed the same

	for (int x = 0; x < count; ++x) {
		//Print to CONSOLE
		cout << left << setw(30) << pop_DB[x].state_name  << pop_DB[x].population << endl;
	}
}


/******************************************************************************************************************************************************
Name: Print_Range
Pre-Condition: array has been defined & integers have been inputted
Post-Condition: state with population of given range will be displayed to screen 
Description: this function takes min & max as range, then displays states with population in between
that range
******************************************************************************************************************************************************/
void state_class::Print_Range(const int min, const int max)
{
	int x = 0;
	//go through entire array
	for (x = 0; x < count; ++x) {
		if ( pop_DB[x].population >= min && pop_DB[x].population <= max)
			//for all state's with population in given range, print them 
			cout << pop_DB[x].state_name << endl;
	}
}


/******************************************************************************************************************************************************
Name: State_Count
Pre-Condition: max/min have been inputed along with array being defined
Post-Condition: the number of states with population in that range is returned
Description: the function takes min & min, & returns the number of states between the values
******************************************************************************************************************************************************/
int state_class::State_Count(const int min, const int max)
{
	int x = 0, state_counter = 0;
	//go through entire array
	for (x = 0; x < count; ++x) {
		if (pop_DB[x].population >= min && pop_DB[x].population <= max)
			//count how many states are in range
			++state_counter;
	}
	return state_counter;
}

/******************************************************************************************************************************************************
Name: Sort
Pre-Condition: array has been defined 
Post-Condition: the array is ordered alphabetically (A-z)
Description: this function sorts the array alphabetically
******************************************************************************************************************************************************/
void state_class::Sort()
{
	//key is variable of next element 
	//save is variable to assist with swapping 
	//j represents index of current element
	population_record key,save;	
	int j = 0;			
	for (int i = 1; i < count; ++i) {
		//go through entire array
		key = pop_DB[i];		//key represents next element 
		j = i - 1;				//j = index of current element 
		//while CURRENT element is > NEXT element, swap them
		while (pop_DB[j].state_name > key.state_name && j >= 0) {
			save = pop_DB[j + 1];
			pop_DB[j + 1] = pop_DB[j];
			pop_DB[j] = save;
			--j;	//prepare to do the same thing (check & swap) with previous element
		}			//once done, refer to next elements of index: (i+1) & (j+1) to continue sorting
	}
	//array is sorted
}
