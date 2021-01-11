#include "stdafx.h"
#include "Game.h"
#include <iostream>

using namespace std;

void Game::TicTacToeRules()
{
	cout << "Boy 1: Okay, so Tic Tac Toe has a square with 9 boxes inside." << endl;
	cout << "Boy 1: We take in turns drawing either an 'X' or an 'O' in the boxes." << endl;
	cout << "Boy 1: Your aim is to line up three of your 'O's in the boxes." << endl;
	cout << "Boy 1: They can line up diagonally, vertically or horizontally." << endl;
	cout << "Boy 1: If you get three 'O's in a row, I will give you 5 gold." << endl;
	cout << "Boy 1: If I get three 'X's in a row, you have to give me 5 gold." << endl;
	cout << "Boy 1: If neither of us win, then it is a draw and we keep our gold." << endl;
	cout << "Boy 1: Would you like to give it a go?" << endl; cout << endl;
	cout << "1. Yes, let's play." << endl;
	cout << "2. No, return to the choice between both games." << endl; cout << endl;

	int decision;

	bool validInput = false;
	// Loops through until a valid response is given by the user (valid input: 1, and 2)
	while (validInput == false)
	{
		cout << "Enter a number: ";
		cin >> decision; cout << endl;	// User input to decide if they want to play
		cout << endl;

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}

		switch (decision)
		{
		case 1:	// If player enters 1
			TicTacToe();	// Calls TicTacToe function
			validInput = true;	// User input is valid, exit loop
			break;
		case 2:	// If player enters 2
			BoyStall();	// Calls BoyStall function
			validInput = true;	// User input is valid, exit loop
			break;
		default:	// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}