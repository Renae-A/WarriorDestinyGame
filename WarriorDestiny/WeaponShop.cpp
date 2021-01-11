#include "stdafx.h"
#include "Game.h"
#include <iostream>

using namespace std;

void Game::WeaponShopMenu()
{
	cout << "~~~~ Weapon Shop ~~~~" << endl;
	cout << "The shop currently has " << weaponStore.gold << " gold." << endl;			// displays weapon store's gold
	cout << "You currently have " << character.playerStore.gold << " gold." << endl;	// displays user gold
	cout << endl;

	cout << "What would you like to do?" << endl;
	cout << "1. Buy items." << endl;
	cout << "2. Sell items." << endl;
	cout << "3. Talk to weapon smith." << endl;
	cout << "4. Return to town." << endl;

	bool validInput = false;
	int choice;

	// Loops through until a valid response is given by the user (valid input: 1, 2, 3 and 4)
	while (validInput == false)
	{
		cout << "Enter a number to decide: ";
		cin >> choice;		// user input of what they would like to do in the weapon shop
		cout << endl;

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of a int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}

		switch (choice)
		{
		case 1:				// if the user wants to buy weapons
			BuyWeapon();	// call the BuyWeapon function
			break;			// The user has given valid input, exits loop
		case 2:				// if the user wants to sell weapons
			SellWeapon();	// call the SellWeapons function
			break;			// The user has given valid input, exits loop
		case 3:				// if the user wants to talk to the weapon smith
			TalkWeapon();	// call the TalkWeapon function
			break;			// The user has given valid input, exits loop
		case 4:				// if the user wants to go back to the town
			menu();			// call the menu function
			break;			// The user has given valid input, exits loop   
		default:			// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}

