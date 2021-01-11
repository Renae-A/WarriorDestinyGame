#include "stdafx.h"
#include "Game.h"
#include <iostream>

using namespace std;

void Game::SellArmor()
{
	int decision = 0;

	cout << "~~~~ Sell Items ~~~~" << endl;
	cout << "You have " << character.playerStore.gold << " gold." << endl; cout << endl;	// displays user gold

	cout << "Your Inventory: " << endl; cout << endl;
	for (int i = 6; i < 12; i++)	// for every item in the user inventory (that relates to the items in the armor store)
	{
		cout << ((i - 6) + 1) << ". Quantity: (" << character.playerStore.itemList[i].quantity << ") " << character.playerStore.itemList[i].name << endl;	// display the quantity, and the name
	}
	cout << endl;

	cout << "Which item would you like to sell? " << endl;

	bool decisionMade = false;

	// Loops through until a valid response is given by the user (valid input: 0, 1, 2, 3, 4, 5 and 6)
	while (decisionMade == false)
	{
		cout << "Choose a number from 1 - 6 to match listed item. " << endl;
		cout << "Enter 0 to go back. " << endl;
		cin >> decision; cout << endl;	// user input of item they want to sell item
		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}
		else if (decision == 0)	// if the user wants to go back
		{
			ArmorShopMenu();		// call ArmorShopMenu() function to go back
			decisionMade = true;	// The user has given valid input, exits loop
		}
		else if (decision >= 1 && decision <= 6)	// if the user chooses a valid item
		{
			decisionMade = true;	// The user has given valid input, exits loop
		}
		else	// The user has given invalid input
		{
			cout << "You did not enter a valid response. " << endl;	// inform the user that the input was invalid (loop again)
		}
	}

	Item& playerItem = character.playerStore.itemList[(6 + decision) - 1];	// playerItem will be easier to use in code (is the user choice of item in the player inventory)
	Item& storeItem = armorStore.itemList[decision - 1];					// storeItem will be easier to use in code (is the user choice of item in the armor store's inventory)

	cout << "Current selling price of " << playerItem.name << " is " << playerItem.price << " gold." << endl;	// displays price of the item
	cout << "You have " << playerItem.quantity << " " << playerItem.name << "/s." << endl;						// displays user's quantity of the item
	cout << "The shop has " << storeItem.quantity << " " << storeItem.name << "/s." << endl;					// displays the armor store's quantity of the item
	int amount = 0;
	bool decisionMade1 = false;

	// Loops through until a valid response is given by the user (valid input: any integer)
	while (decisionMade1 == false)
	{
		cout << "How many " << storeItem.name << "/s would you like to sell?" << endl;
		cout << "Enter 0 to exit." << endl;
		cin >> amount;		// user input to decide how many of the item they wish to purchase
		cout << endl;
		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}
		if (amount == 0)	// if the user wants to go back
		{
			ArmorShopMenu();		// call ArmorShopMenu() function to go back
			decisionMade1 = true;	// The user has given valid input, exits loop
		}
		else if (playerItem.quantity < amount)	// if the user does not have the amount of items that the user wants to sell
		{
			cout << "You does not have " << amount << " " << storeItem.name << "/s to sell." << endl;	// inform the user
		}
		else if (playerItem.price > armorStore.gold)	// if the armor store's gold is less than the price of the item (cannot afford)
		{
			cout << "The shop cannot afford " << amount << " " << storeItem.name << "/s." << endl;	// inform the user
		}
		else	// if the sale is valid
		{
			cout << "You have sold " << amount << " " << storeItem.name << "/s." << endl;	// displays the amount and item name that the user bought
			playerItem.quantity -= amount;	// remove the amount that the user sold from the quantity the user has
			character.playerStore.gold += (storeItem.price * amount);	// add (the price of the item x the amount) to the user's gold 
			storeItem.quantity += amount;	// add the amount the user bought to the quantity of the item the armor store has
			armorStore.gold -= (storeItem.price * amount);	// subtract (the price of the item x the amount) from the armor store's gold
			decisionMade1 = true;	// The user has given valid input, exits loop
		}

	}
	int YesNoAnswer;
	cout << "Would you like to sell anything? " << endl;
	cout << "1. Yes." << endl;
	cout << "2. No." << endl; 
	cin >> YesNoAnswer;	// user input to decide if they want to sell another item
	cout << endl;

	if (YesNoAnswer == 1)	// if the user wants to sell another item
	{
		SellArmor();	// call the SellArmor function
	}
	else if (YesNoAnswer == 2)	// if the user does not want to sell another item
	{
		ArmorShopMenu();	// call the ArmorShopMenu function
	}
	else	// if the input is invalid
	{
		cout << "You did not enter a valid response. Returning to shop menu." << endl;	// inform the user
		ArmorShopMenu();	// call the ArmorShopMenu function
	}
}