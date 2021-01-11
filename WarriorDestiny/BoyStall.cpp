#include "stdafx.h"
#include "Game.h"
#include <iostream>

using namespace std;

void Game::BoyStall()
{
	cout << "The two boys see you approach them and they smile brightly at each other." << endl;
	cout << "Boy 1: Do you like to play games?" << endl;
	cout << "Boy 2: We love games. Would like to play a game with one of us?" << endl;
	cout << "Boy 1: I think Tic Tac Toe is the best game ever!" << endl;
	cout << "Boy 2: No way! Fire, Grass, Water is way better." << endl;
	cout << "Boy 1: We should let our customer decide." << endl;
	cout << "You: Ummmm..." << endl;
	cout << "Boy 1: Would you like us to tell you the rules?" << endl;
	cout << "Boy 2: Then you can decide." << endl; cout << endl;
	cout << "1. Yes, let's hear rules for Tic Tac Toe." << endl;
	cout << "2. Yes, let's hear rules for Fire, Grass, Water." << endl;
	cout << "3. No, return to markets." << endl; cout << endl;
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
		case 1:						// If the user wants to view the rules for Tic Tac Toe
			TicTacToeRules();		// Call TicTacToeRules function
			validInput = true;		// User input is valid, exit loop
			break;
		case 2:						// If the user wants to view the rules for Fire, Grass, Water
			FireGrassWaterRules();	// Call FireGrassWaterRules function
			validInput = true;		// User input is valid, exit loop
			break;
		case 3:						// If the user wants top return to the markets
			Markets();				// Call Markets function
			validInput = true;		// User input is valid, exit loop
			break;
		default:					// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}

