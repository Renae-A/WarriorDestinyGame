#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <random>

using namespace std;

void Game::FireGrassWater()
{
	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution<> distr(1, 3); // define the range
	int boyElement = distr(eng);	// Sets boyElement value to a random number between 1 and 3 of the range

	cout << "~~~ Fire Grass Water Game ~~~" << endl; cout << endl;

	cout << "Boy 2: Here is your paper and pencil. " << endl;
	cout << "Boy 2: Write your element without showing me." << endl;
	cout << "Boy 2: And on the count of three, we will reveal our element." << endl; cout << endl;
	
	bool invalidInput = true;
	char choice;

	// Loops through until a valid response is given by the user (valid input: 'f', 'F', 'g', 'G', 'w' and 'W')
	while (invalidInput == true)
	{
		cout << "Choose your element." << endl;
		cout << "Enter 'F' for Fire." << endl;
		cout << "Enter 'G' for Grass." << endl;
		cout << "Enter 'W' for Water." << endl; cout << endl;
		cout << "Your element: "; cin >> choice; cout << endl;	// user input choice of element

		if (cin.fail())		// If the user input is invalid (e.g. a int instead of a char)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}

		switch (choice)
		{
		case 'F':	// if user chooses Fire
		case 'f':
			cout << "3" << endl; 
			cout << "2" << endl;
			cout << "1" << endl; cout << endl;
			if (boyElement == 1)	// if boy chooses Fire (draw)
			{
				cout << "You have chosen Fire" << endl;
				cout << "The boy has chosen Fire" << endl; cout << endl;
				cout << "Boy 2: It's a draw!" << endl; cout << endl;
				FireGrassWaterAgain();	// call FireGrassWaterAgain function 
			}
			else if (boyElement == 2)	// if boy chooses Grass (user win)
			{
				cout << "You have chosen Fire" << endl;
				cout << "The boy has chosen Grass" << endl; cout << endl;
				cout << "Boy 2: Aww.. You won." << endl; cout << endl;
				cout << "The boy hands over 5 gold." << endl; cout << endl;
				character.playerStore.gold += 5;	// add 5 to user gold
				FireGrassWaterAgain();	// call FireGrassWaterAgain function 
			}
			else if (boyElement == 3)	// if boy chooses Water (user lose)
			{
				cout << "You have chosen Fire" << endl;
				cout << "The boy has chosen Water" << endl; cout << endl;
				cout << "Boy 2: Yay! I win!" << endl; cout << endl;
				cout << "You give the boy 5 gold." << endl; cout << endl;
				character.playerStore.gold -= 5;	// subtract 5 from user gold
				FireGrassWaterAgain();	// call FireGrassWaterAgain function 
			}
			break;
		case 'G':	// if user chooses Grass
		case 'g':
			cout << "3" << endl;
			cout << "2" << endl;
			cout << "1" << endl; cout << endl;
			if (boyElement == 1)	// if boy chooses Fire (user lose)
			{
				cout << "You have chosen Grass" << endl;
				cout << "The boy has chosen Fire" << endl; cout << endl;
				cout << "Boy 2: Yay! I win!" << endl; cout << endl;
				cout << "You give the boy 5 gold." << endl; cout << endl;
				character.playerStore.gold -= 5;	// subtract 5 from user gold
				FireGrassWaterAgain();	// call FireGrassWaterAgain function 
			}
			else if (boyElement == 2)	// if boy chooses Grass (draw)
			{
				cout << "You have chosen Grass" << endl;
				cout << "The boy has chosen Grass" << endl; cout << endl;
				cout << "Boy 2: It's a draw!" << endl; cout << endl;
				FireGrassWaterAgain();	// call FireGrassWaterAgain function 
			}
			else if (boyElement == 3)	// if boy chooses Water (user win)
			{
				cout << "You have chosen Grass" << endl;
				cout << "The boy has chosen Water" << endl; cout << endl;
				cout << "Boy 2: Aww.. You won." << endl; cout << endl;
				cout << "The boy hands over 5 gold." << endl; cout << endl;
				character.playerStore.gold += 5;	// add 5 to user gold
				FireGrassWaterAgain();	// call FireGrassWaterAgain function 
			}
			break;
		case 'W':	// if user chooses Water
		case 'w':
			cout << "3" << endl;
			cout << "2" << endl;
			cout << "1" << endl; cout << endl;
			if (boyElement == 1)	// if boy chooses Fire (user win)
			{
				cout << "You have chosen Water" << endl;
				cout << "The boy has chosen Fire" << endl; cout << endl;
				cout << "Boy 2: Aww.. You won." << endl; cout << endl;
				cout << "The boy hands over 5 gold." << endl; cout << endl;
				character.playerStore.gold += 5;	// add 5 to user gold
				FireGrassWaterAgain();	// call FireGrassWaterAgain function 
			}
			else if (boyElement == 2)	// if boy chooses Grass (user lose)
			{
				cout << "You have chosen Water" << endl;
				cout << "The boy has chosen Grass" << endl; cout << endl;
				cout << "Boy 2: Yay! I win!" << endl; cout << endl;
				cout << "You give the boy 5 gold." << endl; cout << endl;
				character.playerStore.gold -= 5;	// subtract 5 from user gold
				FireGrassWaterAgain();	// call FireGrassWaterAgain function 
			}
			else if (boyElement == 3)	// if boy chooses Water (draw)
			{
				cout << "You have chosen Water" << endl;
				cout << "The boy has chosen Water" << endl; cout << endl;
				cout << "Boy 2: It's a draw!" << endl; cout << endl;
				FireGrassWaterAgain();	// call FireGrassWaterAgain function 
			}
		}
	}
}

void Game::FireGrassWaterAgain()
{
	cout << "Boy 2: Would you like to play again?" << endl; cout << endl;
	cout << "1. Yes, play again." << endl;
	cout << "2. No, return to the choice between both games." << endl;
	cout << "3. No, return to Markets." << endl; cout << endl;
	int decision;

	bool validInput = false;

	// Loops through until a valid response is given by the user (valid input: 1, 2 and 3)
	while (validInput == false)
	{
		cout << "Enter a number: ";
		cin >> decision; cout << endl;	// User input to decide if they want to play again
		cout << endl;

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}

		switch (decision)
		{
		case 1:					// If user wants to play again
			FireGrassWater();	// Calls FireGrassWater function
			validInput = true;	// User input is valid, exit loop
			break;
		case 2:					// If user wants to go back to the boys' stall
			BoyStall();			// Calls BoyStall function
			validInput = true;	// User input is valid, exit loop
			break;
		case 3:					// If user wants to go back to the markets
			Markets();			// Calls Markets function
			validInput = true;	// User input is valid, exit loop
			break;
		default:				// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}

