#include "stdafx.h"
#include "Game.h"
#include <iostream>

using namespace std;

void Game::BattleArena()
{
	cout << "~~~~ Battle Arena ~~~~" << endl; cout << endl;		
	cout << "Your gold: " << character.playerStore.gold << endl;						// displays user gold
	cout << "Your attack: " << character.getAttackValue() << endl;						// displays user attack value
	cout << "Your maximum health: " << character.getMaxHealth() << endl; cout << endl;	// displays user maximum health


	cout << "What would you like to do?" << endl;
	cout << "1. Practice battle." << endl;
	cout << "2. Enter tournament." << endl;
	cout << "3. Enter boss competition." << endl;
	cout << "4. View enemy statisitics." << endl;
	cout << "5. Return to town." << endl;

	bool validInput = false;
	int choice;

	// Loops through until a valid response is given by the user (valid input: 1, 2, 3 and 4)
	while (validInput == false)
	{
		cout << "Enter a number to decide: ";
		cin >> choice;		// user input of what they would like to do in the battle arena
		cout << endl;

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of a int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}

		switch (choice)
		{
		case 1:					// if the user wants to practice battle
			PracticeBattle();	// call PracticeBattle function
			break;				// The user has given valid input, exits loop
		case 2:					// if the user wants to go into a tournament
			Tournament();		// call Tournament function
			break;				// The user has given valid input, exits loop
		case 3:					// if the user wants to enter the boss competition
			BossCompetition();	// call BossCompetition function
			break;				// The user has given valid input, exits loop
		case 4:					// if the user want to view the enemy statistics
			EnemyStatistics();	// call EnemyStatistics function
			break;				// The user has given valid input, exits loop
		case 5:					// if the user wants to go back to the town
			menu();				// call the menu function
			break;				// The user has given valid input, exits loop 
		default:	// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
	cout << endl;
}

