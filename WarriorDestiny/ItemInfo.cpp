#include "stdafx.h"
#include "Game.h"
#include "Item.h"
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>	// binary search template function is created which takes in a vector,the starting int index of the vector, the last int index of the vector and the vector content to be searched
int binary_search(const vector<T>& vec, int start, int end, const T& key)
{
	// Termination condition: start index greater than end index
	if (start > end)
	{
		return -1;	// was not found
	}

	// Find the middle element of the vector and use that for splitting
	// the array into two pieces.
	const int middle = start + ((end - start) / 2);

	if (vec[middle] == key)
	{
		return middle;	// was found
	}
	else if (vec[middle] > key)
	{
		return binary_search(vec, start, middle - 1, key);	// was found
	}

	return binary_search(vec, middle + 1, end, key);	
}

void Game::ItemInfo()
{
	cout << "Would you like to view items in original order or in alphabetical order?" << endl;
	bool decisionMade = false;
	int decision;

	// Loops through until a valid response is given by the user (valid input: 1 and 2)
	while (decisionMade == false)
	{
		cout << "1. Orignal. " << endl;
		cout << "2. Alphabetical. " << endl;
		cin >> decision; cout << endl;	// user input to decide on how they want the item information to be displayed
		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}
		if (decision == 1)	// if user wants orignal order
		{
			cout << "Your Inventory:" << endl; cout << endl;	// for each Item user owns
			for (int i = 0; i < 12; i++)
			{
				cout << (i + 1) << ". Quantity: (" << character.playerStore.itemList[i].quantity << ") " << character.playerStore.itemList[i].name << endl;	// display quantity and name
			}
			cout << endl;
			bool decisionMade1 = false;
			int decision;

			// Loops through until a valid response is given by the user (valid input: 0 - 12)
			while (decisionMade1 == false)
			{
				cout << "Choose a number from 1 - 12 to match listed item to display info. " << endl;
				cout << "Enter 0 to go back. " << endl;
				cin >> decision; cout << endl;	// user input to decide on what Item information to display
				if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
				{
					cin.clear();	// Clear the user input 
					cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
				}
				else if (decision == 0)	// if user wants to go back
				{
					ManageInventory();		// call ManageInventory() function to go back
					decisionMade1 = true;	// The user has given valid input, exits loop
				}
				else if (decision >= 1 && decision <= 12)	// if the user chooses a valid item
				{
					decisionMade1 = true;	// The user has given valid input, exits loop
				}
				else	// The user has given invalid input
				{
					cout << "You did not enter a valid response. " << endl; cout << endl;	// inform the user that the input was invalid (loop again)
				}
			}
			Item& playerItem = character.playerStore.itemList[decision - 1];	// playerItem will be easier to use in code (is the user choice of item in the player inventory)

			cout << "Depending on if the item is a piece of armor or a weapon," << endl;
			cout << "the bonus value will go towards the either the total amount of hitpoints you can take (armor item)" << endl;
			cout << "or the total amount of hitpoints you can deliver (weapon item)." << endl; cout << endl;
			cout << "Item: " << playerItem.name << endl;	// display playerItem name
			cout << "Bonus: " << playerItem.bonus << " hitpoints" << endl; cout << endl;	// display playerItem bonus

			decisionMade = true;	// The user has given valid input, exits loop
		}
		else if (decision == 2)	// if the user wants alphabetical order
		{
			Inventory temp = character.playerStore;	// a temporary playerStore is created
			sort(temp.itemList.begin(), temp.itemList.end());	// sorts the temporary playerStore to alphabetical order
			cout << "Your Inventory:" << endl; cout << endl;	// for each Item user owns
			for (int i = 0; i < 12; i++)
			{
				cout << (i + 1) << ". Quantity: (" << temp.itemList[i].quantity << ") " << temp.itemList[i].name << endl;	// display quantity and name
			}
			cout << endl;

			string searchItem;

			bool decisionMade2 = false;

			// Loops through until a valid response is given by the user (valid input: 0 - 12)
			while (decisionMade2 == false)
			{
				cout << "Which item's information would you like to view?" << endl;
				cout << "Please remember to include capitals or symbols in name of item." << endl;
				cout << "Enter 0 to go back. " << endl;
				cin >> searchItem;			// user inputs string which will be name of an item
				cout << "Finding " << searchItem << " information..." << endl; cout << endl;
				Item it;					// creates a temporary item 
				it.name = searchItem;		// gives the temporary item the name of the user input string 
				int result = binary_search(temp.itemList, 0, (temp.itemList.size()-1), it);	// search for any item with the same name as the string input
		
				if (cin.fail())		// If the user input is invalid (e.g. user does not enter a valid string)
				{
					cin.clear();	// Clear the user input 
					cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
				}
				else if (searchItem == "0")	// if user wants to go back
				{
					ManageInventory();		// call ManageInventory() function to go back
					decisionMade2 = true;	// The user has given valid input, exits loop
				}
				else if (it.name == temp.itemList[result].name)	// if the user chooses a valid item
				{
					Item& playerItem = temp.itemList[result];	// playerItem will be easier to use in code (is the user choice of item in the player inventory)

					cout << "Depending on if the item is a piece of armor or a weapon," << endl;
					cout << "the bonus value will go towards the either the total amount of hitpoints you can take (armor item)" << endl;
					cout << "or the total amount of hitpoints you can deliver (weapon item)." << endl; cout << endl;
					cout << "Item: " << playerItem.name << endl;	// display playerItem name
					cout << "Bonus: " << playerItem.bonus << " hitpoints" << endl; cout << endl;	// display playerItem bonus

					decisionMade2 = true;	// The user has given valid input, exits loop
				}
				else	// The user has given invalid input
				{
					cout << "You did not enter a valid response. There is no item called " << it.name << "." << endl; cout << endl;	// inform the user that the input was invalid (loop again)
				}
			}
			decisionMade = true;	// The user has given valid input, exits loop
		}
		else	// The user has given invalid input
		{
			cout << "You did not enter a valid response. " << endl; cout << endl;	// inform the user that the input was invalid (loop again)
		}
	}

	bool decisionMade1 = false;

	// Loops through until a valid response is given by the user (valid input: 1 and 2)
	while (decisionMade1 == false)
	{
		cout << "Did you want to view any other item's bonus information. " << endl;
		cout << "1. Yes. " << endl;
		cout << "2. No, go back. " << endl;
		cin >> decision; cout << endl;	// user decision to view more Item information or not
		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}
		else if (decision == 1)	// if user wants to view more Item information
		{
			ItemInfo();				// call ItemInfo() function 
			decisionMade1 = true;	// The user has given valid input, exits loop
		}
		else if (decision == 2)	// if user does not want to view more Item information
		{
			ManageInventory();		// call ManageInventory() function to go back
			decisionMade1 = true;	// The user has given valid input, exits loop
		}
		else	// The user has given invalid input
		{
			cout << "You did not enter a valid response. " << endl; cout << endl;	// inform the user that the input was invalid (loop again)
		}
	}
}


