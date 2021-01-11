#include "stdafx.h"
#include "Game.h"
#include <iostream>

using namespace std;

void Game::ManStall()
{
	cout << "Strange man: Hello there.." << endl;
	cout << "Strange man: You look like someone who would like a little extra gold." << endl;
	cout << "Strange man: Can I interest you in a number guess game..?" << endl;
	cout << "Strange man: I will make it worth your while if you pay 5 gold." << endl;
	cout << "Strange man: All you have to do is choose a number card between 1 and 100." << endl;
	cout << "Strange man: If I cannot guess your number within 7 guesses," << endl;
	cout << "Strange man: I will return double your pay." << endl;
	cout << "Strange man: If I guess within 7 guesses, I keep your pay." << endl;
	cout << "Strange man: What do you say?" << endl; cout << endl;
	cout << "1. Yes, play game." << endl;
	cout << "2. No, return to markets." << endl; cout << endl;
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
		case 1:					// If user wants to play game
			NumberGame();		// Calls NumberGame function
			validInput = true;	// User input is valid, exit loop
			break;
		case 2:					// If user wants to go back to markets
			Markets();			// Calls Markets function
			validInput = true;	// User input is valid, exit loop
			break;
		default:				// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}
