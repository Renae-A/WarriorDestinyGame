#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

using namespace std;

void Game::EquippedItems()
{
	for (int i = 0; i < 7; i++)	// for every BodyPart
	{
		cout << character.playerBody.BodyList[i].name << ": " << character.playerBody.BodyList[i].item.name << endl;	// display BodyPart name and name of Item equipped
	}
	cout << endl;

	int decision;
	bool decisionMade = false;

	// Loops through until a valid response is given by the user (valid input: 0)
	while (decisionMade == false)
	{
		cout << "Enter 0 to return." << endl;
		cin >> decision; cout << endl;	// user input to return back to inventory management

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}

		switch (decision)
		{
		case 0:						// if the player wants to go back
			ManageInventory();		// call ManageInventory function
			decisionMade = true;	// User input is valid, exit loop
			break;
		default:					// If input is invalid, inform the user
			cout << "You did not enter a valid response. " << endl; cout << endl;
		}
	}
}