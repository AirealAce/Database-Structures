#include "date.h"
#include <iomanip>  //need to use formatting manipulators

/*************************************************************************************
//Name: Default Constructor
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized
//Description: This is the default constructor which will be called automatically when
//an object is declared. It will initialize the state of the class
//*************************************************************************************/
Date::Date()
{
	cout << "Default constructor has been called" << endl;
	myMonth = 1;
	myDay = 1;
	myYear = 1;

	cout << setfill('0') << setw(2) << myMonth << "\\";
	cout << setfill('0') << setw(2) << myDay << "\\";
	cout << setfill('0') << setw(4) << myYear << endl << endl;
}

//*************************************************************************************
//Name: Explicit-value constructor
//Precondition: Parameters have been accepted (ints)
//Postcondition: If entered correctly, the Date object is initialized
//Description: This function initializes a Date object to explicit values unless the values are
//illegal for dates. If so, the user will be told which values are unnacceptable.
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
	//note that there exist certain combinations of mm/dd/yyyy that can't exist
	cout << "Explicit-value constructor has been called" << endl;
	//check general conditions before displaying
	if (m > 0 && m < 13 && d>0 && d < 32 && y>0)
	{//then check specific conditions before displaying
		if (((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d < 32) ||
			((m == 4 || m == 6 || m == 9 || m == 11) && d < 31) || (m == 2 && d < 29) || 
			(m == 2 && d <= 29 && (y % 4 == 0)))
		{//if dates are legal, display them
			cout << setfill('0') << setw(2) << m << "\\";
			cout << setfill('0') << setw(2) << d << "\\";
			cout << setfill('0') << setw(4) << y << endl;
		//as well as store the data by initializing the class object's attributes
			myMonth = m;
			myDay = d;
			myYear = y;
		}
		else //since month & year are correct, the day must be incorrect if nothing else
		{	cout << "day = " << setfill('0') << setw(2) << d << " is incorrect" << endl; }

		//display if leap year
		if (y % 4 == 0)
		{	cout << "This is a leap year" << endl << endl;}
		else
		{	cout << endl;}
	}
	else {
		//otherwise, check for errors & display them
		if (!(m > 0 && m < 13))			//is month legal?
		{	cout << "Month = " << setfill('0') << setw(2) << m << " is incorrect" << endl;}		
		
		if (!(d > 0 && d < 32))			//is day legal?
		{cout << "day = " << setfill('0') << setw(2) << d << " is incorrect" << endl;}

		if (!(y>0))
		{	cout << "Year = " << setfill('0') << setw(4) << y << " is incorrect" << endl << endl;}
	}
}

//*************************************************************************************
//Name: Display
//Precondition: The Date object has been initialized
//Postcondition: The Date object's attributes are displayed to consoloe. 
//Description: This function displays the contents of the Date object to the screen. 
//*************************************************************************************
void Date::display()
{
	cout << setfill('0') << setw(2) << myMonth << "\\";
	cout << setfill('0') << setw(2) << myDay << "\\";
	cout << setfill('0') << setw(4) << myYear << endl << endl;
}

//*************************************************************************************
//Name: getMonth
//Precondition: The Date object has been defined with attributes initialized.
//Postcondition: The month attribute is returned.
//Description: This function returns the month attribute of a Date object.
//*************************************************************************************
int Date::getMonth()
{
	return (*this).myMonth;
}

//*************************************************************************************
//Name: getDay
//Precondition: The Date object has been defined with attributes initialized.
//Postcondition: The day attribute is returned.
//Description: This function returns the day attribute of a Date object.
//*************************************************************************************
int Date::getDay()
{
	return (*this).myDay;
}

//*************************************************************************************
//Name: getYear
//Precondition: The Date object has been defined with attributes initialized.
//Postcondition: The year attribute is returned.
//Description: This function returns the year attribute of a Date object.
//*************************************************************************************
int Date::getYear()
{
	return (*this).myYear;
}

//*************************************************************************************
//Name: setMonth
//Precondition: The Date object has been initialized / declared. 
//Postcondition: The specified attribute is initialized to the parameter value.
//Description: This function initializes an attribute to a specificed value. 
//*************************************************************************************
void Date::setMonth(unsigned m)
{
	myMonth = m;
}

//*************************************************************************************
//Name: setDay
//Precondition: The Date object has been initialized / declared. 
//Postcondition: The specified attribute is initialized to the parameter value.
//Description: This function initializes an attribute to a specificed value. 
//*************************************************************************************
void Date::setDay(unsigned d)
{
	myDay = d;
}

//*************************************************************************************
//Name: getYear
//Precondition: The Date object has been initialized / declared. 
//Postcondition: The specified attribute is initialized to the parameter value.
//Description: This function initializes an attribute to a specificed value. 
//*************************************************************************************
void Date::setYear(unsigned y)
{
	myYear = y;
}

//*************************************************************************************
//Name: operator<<
//Precondition: The Date object has been initialized / declared. 
//Postcondition: The attributes of the Date object are displayed.
//Description: This function displays the contents of a Date object, & allows for chaining.
// EX of chaining: cout << dateObj1 << dateObj2 << dateObj3.
//*************************************************************************************
ostream& operator<<(ostream& out, Date& dateObj)
{
	out << setfill('0') << setw(2) << dateObj.myMonth << "\\";
	out << setfill('0') << setw(2) << dateObj.myDay << "\\";
	out << setfill('0') << setw(4) << dateObj.myYear;

	return out;//returning object that invoked the function
}
