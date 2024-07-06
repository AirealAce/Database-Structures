/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Aaron P. Mills                            TOTAL POINTS:  25
COURSE:  COP 3530								DUE DATE:  12/13/2021
Assignment Name:  Extra Credit Assignment       Professor:  Dr. Petrie

Description:  This program is to simulate the game "Tower of Hanoi" with three disks. It involves the 
usage of stacks. 
******************************************************************************************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include "towers.h"
using namespace std;

int main()
{
	stack A, B, C;								//the three stacks
	string str; stack* src = 0; stack* dst = 0;	//pointers for later reference for player action
	bool win = false;							//win condition that is true when tower C is complete
	int moves = 0;								//number of EXECUTED moves
	newGame(A, B, C, moves);					//prepare a new game for playing
	int numDisks = A.count;						//A starts off holding all the disks, record the #
	while (!win)
	{//until the player wins (or chooses to exit): play the game
		print_stacks(A, B, C); cout << "*************************" << endl;
		cout << "NOTE: You may press X or x if you wish to end the game." << endl;
		cout << "What is your move? (give first the source stack (A, B, or C) and the Destination Stack" <<
			"separated by 1 Space): ";
		getline(cin, str);
		if (str == "x" || str == "X") break;
		if (str[0] == 'A' || str[0] == 'a') src = &A;
		else if (str[0] == 'B' || str[0] == 'b') src = &B;
		else if (str[0] == 'C' || str[0] == 'c') src = &C;
		else {//all other characters are NOT src stacks
			cout << "ALERT: Invalid src stack." << endl;
			continue;	//try again
		}
		if (str[2] == 'A' || str[2] == 'a') dst = &A;
		else if (str[2] == 'B' || str[2] == 'b') dst = &B;
		else if (str[2] == 'C' || str[2] == 'c') dst = &C;
		else {//all other characters are NOT dst stacks
			cout << "ALERT: Invalid dst stack." << endl;
			continue;	//try again
		}
		move(*src, *dst, moves);	//if player inserts correct stack names, attempt action execution
		if (C.count == numDisks)
		{//win condition & screen
			win = true;
			print_stacks(A, B, C); cout << "*************************" << endl;
			cout << "# of moves executed: " << moves << endl;
			//victory messege as per instruction
			if (moves == 7) cout << "You've completed the game with the minimal possible " <<
				"moves! \nCan't do better than that! INCREDIBLE!!!";
			else if (moves >= 11) cout << "Could have done better.";
			else cout << "Congratulations!";
			cout << endl;
		}
		cout << endl;
	}


	//tracing of print out
	//NOTE: I cannot access nor download the powerpoint / print out provided in canvas
	cout << "***********************************************************************************************************************" << endl;
	cout << "Here's your 'prize'; an attempted traced duplicate of the print out that I can't see on canvas!" << endl;
	cout << "Tracing***************************************************************************************************************" << endl;
	newGame(A, B, C, moves);
	cout << "New Game: " << endl; print_stacks(A, B, C); cout << "*************************" << endl;
	move(A, C, moves); print_stacks(A, B, C); cout << "*************************" << endl;
	move(A, B, moves); print_stacks(A, B, C); cout << "*************************" << endl;
	move(C, B, moves); print_stacks(A, B, C); cout << "*************************" << endl;
	move(A, C, moves); print_stacks(A, B, C); cout << "*************************" << endl;
	move(B, A, moves); print_stacks(A, B, C); cout << "*************************" << endl;
	move(B, C, moves); print_stacks(A, B, C); cout << "*************************" << endl;
	move(A, C, moves); print_stacks(A, B, C); cout << "*************************" << endl;
	cout << "# of executed moves: " << moves << endl << endl;
	
	//examples of illegal moves
	//NOTE: I cannot access nor download the powerpoint / print out provided in canvas
	cout << "***********************************************************************************************************************" << endl;
	cout << "Here's some examples of illegal moves!" << endl;
	cout << "Examples****************************************************************************************************************" << endl;
	newGame(A, B, C, moves);
 	cout << "Start of Game: " << endl; print_stacks(A, B, C); cout << "***************************************************************************" << endl;
	cout << "Legal| " << endl;
	move(A, C, moves); print_stacks(A, B, C); cout << "***************************************************************************" << endl;
	cout << "ILLEGAL| Move A onto C; notice the disk on A is too large for tower C:" << endl;
	move(A, C, moves); print_stacks(A, B, C); cout << "***************************************************************************" << endl;
	cout << "ILLEGAL| Move B onto C; notice there is nothing to move from B:" << endl;
	move(B, C, moves); print_stacks(A, B, C); cout << "***************************************************************************" << endl;

	cout << endl << endl;
}
