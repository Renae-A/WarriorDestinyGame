#include "stdafx.h"
#include "Game.h"
#include "Item.h"
#include <iostream>

using namespace std;

void Game::ManageInventory()
{
	cout << "Your gold: " << character.playerStore.gold << endl; cout << endl;	// displays user gold

	cout << "Your Inventory:" << endl; cout << endl;
	for (int i = 0; i < 12; i++)	// for every Item in user inventory
	{
		cout << (i + 1) << ". Quantity: (" << character.playerStore.itemList[i].quantity << ") " << character.playerStore.itemList[i].name << endl;	// display quantity and name
	}
	cout << endl;

	cout << "Would you like to do?" << endl;
	cout << "1. Equip items. " << endl;
	cout << "2. Unequip items." << endl;
	cout << "3. Display equipped items." << endl;
	cout << "4. Item information." << endl;
	cout << "5. Return to town. " << endl;

	int decision;
	bool decisionMade = false;

	// Loops through until a valid response is given by the user (valid input: 1, 2, 3, 4 and 5)
	while (decisionMade == false)
	{
		cout << "Enter a number: ";
		cin >> decision; cout << endl;	// user input to decide on what user wants to do with their inventory

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}

		switch (decision)
		{
		case 1:						// If user wants to equip Items
			Equip();				// Calls Equip function
			decisionMade = true;	// User input is valid, exit loop
			break;
		case 2:						// If user wants to unequip Items
			Unequip();				// Calls Unequip function
			decisionMade = true;	// User input is valid, exit loop
			break;
		case 3:						// If user wants to view their equipped Items
			EquippedItems();		// Calls EquippedItems function
			decisionMade = true;	// User input is valid, exit loop
			break;
		case 4:						// If user wants to view Item information
			ItemInfo();				// Calls ItemInfo function
			decisionMade = true;	// User input is valid, exit loop
			break;
		case 5:						// If user wants to go to back to town
			menu();					// Calls menu function
			decisionMade = true;	// User input is valid, exit loop
			break;
		default:					// If input is invalid, inform the user
			cout << "You did not enter a valid response. " << endl; cout << endl;
		}
	}
}



