#include "stdafx.h"
#include "Game.h"
#include <iostream>

using namespace std;

void Game::FireGrassWaterRules()
{
	cout << "Boy 2: Well, there are three elements; Fire, Grass and Water." << endl;
	cout << "Boy 2: What you have to do is write down which element you want to choose." << endl;
	cout << "Boy 2: I will do the same thing but we can't let each other see our element." << endl;
	cout << "Boy 2: Fire will burn the Grass. (Fire wins)" << endl;
	cout << "Boy 2: Grass will absorb the Water. (Grass wins)" << endl;
	cout << "Boy 2: And Water will put out the Fire. (Water wins)" << endl;
	cout << "Boy 2: You have to try and pick the element that will win against mine." << endl;
	cout << "Boy 2: If you win, I will give you 5 gold." << endl;
	cout << "Boy 2: If I win, you have to give me 5 gold." << endl;
	cout << "Boy 2: If neither of us win, then it is a draw and we keep our gold." << endl;
	cout << "Boy 2: Would you like to play this game with me?" << endl; cout << endl;
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
		case 1:	// if user wants to play
			FireGrassWater();	// Call FireGrassWater function
			validInput = true;	// User input is valid, exit loop
			break;
		case 2:	// if user does not want to play
			BoyStall();	// Call BoyStall function
			validInput = true;	// User input is valid, exit loop
			break;
		default:	// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}