#include "stdafx.h"
#include "Game.h"
#include <iostream>

using namespace std;

void Game::Markets()
{
	cout << "The markets are thriving with all sorts of people." << endl;
	cout << "You notice a man in a cloak holding a stack of numbered cards at a stall." << endl;
	cout << "Another stall you see, has two small boys running it with a bunch of paper and pencils." << endl;
	cout << "What would you like to do?" << endl; cout << endl;
	cout << "1. Visit mysterious man's stall." << endl;
	cout << "2. Visit the young boys'stall." << endl;
	cout << "3. Return to town." << endl; cout << endl;
	int decision;

	bool validInput = false;

	// Loops through until a valid response is given by the user (valid input: 1, 2 and 3)
	while (validInput == false)
	{
		cout << "Enter a number: ";
		cin >> decision; cout << endl;	// User input to decide which stall they want to visit
		cout << endl;

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}

		switch (decision)
		{
		case 1:					// If user wants to visit man's stall
			ManStall();			// Calls ManStall function
			validInput = true;	// User input is valid, exit loop
			break;
		case 2:					// If user wants to visit boys' stall
			BoyStall();			// Calls BoyStall function
			validInput = true;	// User input is valid, exit loop
			break;
		case 3:					// If user wants to return to town
			menu();				// Calls menu function
			validInput = true;	// User input is valid, exit loop
			break;
		default:				// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}