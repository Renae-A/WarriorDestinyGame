// WarriorDestiny.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include "Player.h"
#include "Enemy.h"

using namespace std;

void Game::menu()
{
	cout << "The streets of the city are full of life and indistinct chatter amongst the town folk." << endl;
	cout << "What would you like to do next?" << endl; cout << endl;

	cout << "1. Battle Arena" << endl;
	cout << "2. Armor Shop" << endl;
	cout << "3. Weapons Shop" << endl;
	cout << "4. Markets" << endl;
	cout << "5. Inventory" << endl;
	cout << "6. Return Home" << endl;
	cout << "7. Save/Exit" << endl;
	cout << "8. Save Current Date and Time" << endl;
	cout << endl;

	bool validInput = false;
	int choice;

	// Loops through until a valid response is given by the user (valid input: 1, 2, 3, 4, 5, 6 and 7)
	while (validInput == false)
	{
		cout << "Enter a number: ";
		cin >> choice; cout << endl;	// User input to decide which game they would like to play
		cout << endl;

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}

		switch (choice)
		{
		case 1:					// If user wants to go to the battle arena
			BattleArena();		// Calls BattleArena function
			validInput = true;	// User input is valid, exit loop
			break;
		case 2:					// If user wants to go to the armor shop
			ArmorShopMenu();	// Calls ArmorShopMenu function
			validInput = true;	// User input is valid, exit loop
			break;
		case 3:					// If user wants to go to the weapon shop
			WeaponShopMenu();	// Calls WeaponShopMenu function
			validInput = true;	// User input is valid, exit loop
			break;
		case 4:					// If user wants to go to the markets
			Markets();			// Calls Markets function
			validInput = true;	// User input is valid, exit loop
			break;
		case 5:					// If user wants to manage their inventory
			ManageInventory();	// Calls ManageInventory function
			validInput = true;	// User input is valid, exit loop
			break;
		case 6:					// If user wants to go home
			if (character.playerStore.gold >= 20000)	// if user has enough gold to afford cure (20000 or more)
			{
				ReturnHome();		// Calls ManageInventory function
				validInput = true;	// User input is valid, exit loop
				break;
			}
			else	// if user does not have enough gold to afford cure (less than 20000)
			{
				cout << "You sigh because you know you cannot leave yet." << endl;
				cout << "The amount of gold you have is not sufficient enough to get the cure for your father." << endl;
				cout << "After looking at the gates of Golem City for a while you decide to keep trying to earn the 20000 gold you require." << endl;
				menu();				// call menu function
				validInput = true;	// User input is valid, exit loop
				break;
			}
		case 7:					// If user wants to save or exit the game
			SaveAndExit();		// Calls SaveAndExit function
			validInput = true;	// User input is valid, exit loop
			break;
		case 8:					// If user wants to save or exit the game
			SaveDateAndTime();	// Calls SaveDateAndTime function
			validInput = true;	// User input is valid, exit loop
			break;
		default:				// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}

 void Game::NewGame()
{
	cout << "A whistful feeling falls upon you as you turn your back on your home. " << endl;
	cout << "Slung on your shoulder, you hold the bare minimum in a small drawstring bag." << endl;
	cout << "Although the bag is light, the responsibility is heavy on you." << endl;
	cout << "Your father has fallen ill and the druid's medicine which can cure him costs a small fortune." << endl;
	cout << "But unfortunately, between you and your father, you cannot afford it." << endl;
	cout << "You let out a heavy sigh and open your bag." << endl;
	cout << "Unfolding the map father gave you, you search for the circled town and stop your finger on it. " << endl;
	cout << "Golem City, a town that is known to train warriors." << endl;
	cout << "Father believes this is the only way to earn decent gold." << endl;
	cout << "If this is the only way, than you shall become a warrior." << endl;
	cout << "You look ahead." << endl;
	cout << "Determination fills your veins." << endl; cout << endl;
	cout << "'This is my destiny.'" << endl; cout << endl;

	character.setName(character);	// character.setName(character) takes the reference of character so that their name can be altered in the function

	cout << "You look back at your map." << endl;
	cout << "'" << character.getName() << ", follow the Silver Forest to find Golem City.'" << endl;
	cout << "Your father's handwriting is elegant despite his body shakes." << endl;
	cout << "Silver Forest. No problem. You wade through the sparkling leaves as the fall from the sky around you." << endl;
	cout << "Golem City is near." << endl; cout << endl;

	menu();	// call menu function
}

int main()
{
	Game game;	// create a new game

	cout << "--- Welcome to A Warrior's Destiny ---" << endl; cout << endl;

	cout << "Menu:" << endl;
	cout << "1. New Game" << endl;
	cout << "2. Load Game" << endl; cout << endl;
	int choice;
	
	bool validInput = false;

	// Loops through until a valid response is given by the user (valid input: 1 and 2)
	while (validInput == false)
	{
		cout << "Enter a number: ";
		cin >> choice; cout << endl;	// User input to decide which game they would like to play
		cout << endl;

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of a int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}

		switch (choice)
		{
		case 1:					// If user wants to create a new game
			game.NewGame();		// Call NewGame function
			validInput = true;	// User input is valid, exit loop
			break;
		case 2:					// If user wants to load a previous game
			cout << "Loading previous game file..." << endl; cout << endl;
			game.LoadGame();	// Call LoadGame function
			validInput = true;	// User input is valid, exit loop
			break;
		}
	}
    return 0;
}

