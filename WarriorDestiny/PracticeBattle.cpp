#include "stdafx.h"
#include "Game.h"
#include "AllEnemyHeaders.h"
#include <iostream>

using namespace std;

void Game::PracticeBattle()
{
	cout << "~~~~ Practice Battle ~~~~" << endl; cout << endl;

	cout << "Battle a lower class beast of your choice in the arena." << endl;
	cout << "If you win against the beast, you win 20 gold and you will gain 2 health." << endl;
	cout << "If you lose against the beast, you will lose 20% of your current gold." << endl; 
	cout << "Once you accept battle, you cannot return until the battle is over." << endl; cout << endl;

	cout << "Would you like enter a practice battle?" << endl; cout << endl;
	cout << "1. Yes." << endl;
	cout << "2. No, return to other options." << endl;
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
		case 1:	// If player enters 1
			StartPractice();	// Calls StartPractice function
			validInput = true;	// User input is valid, exit loop
			break;
		case 2:	// If player enters 2
			BattleArena();	// Calls BattleArena function
			validInput = true;	// User input is valid, exit loop
			break;
		default:	// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}

void Game::StartPractice()
{
	Ghoul ghoul;		// create a Ghoul for if the user chooses the Ghoul to verse
	Cyclops cyclops;	// create a Cyclops for if the user chooses the Cyclops to verse
	Centaur centaur;	// create a Centaur for if the user chooses the Centaur to verse
	Ogre ogre;			// create a Ogre for if the user chooses the Ogre to verse
	Demon demon;		// create a Demon for if the user chooses the Demon to verse

	cout << "Which beast would you like to battle against in practice?" << endl; cout << endl;

	for (int i = 0; i < 5; i++)	// for each lower class Enemy 
	{
		cout << (i + 1) << ". " << theEnemies.enemyList[i].name << endl;	// display their name
	}

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
		case 1:							// if the user chooses a Ghoul to verse
			PracticeResults(ghoul);		// call PracticeResults function that takes a Ghoul as a parameter
			validInput = true;			// User input is valid, exit loop
			break;						
		case 2:							// if the user chooses a Cyclops to verse
			PracticeResults(cyclops);	// call PracticeResults function that takes a Cyclops as a parameter
			validInput = true;			// User input is valid, exit loop
			break;						
		case 3:							// if the user chooses a Centaur to verse
			PracticeResults(centaur);	// call PracticeResults function that takes a Centaur as a parameter
			validInput = true;			// User input is valid, exit loop
			break;						
		case 4:							// if the user chooses a Ogre to verse
			PracticeResults(ogre);		// call PracticeResults function that takes a Ogre as a parameter
			validInput = true;			// User input is valid, exit loop
			break;						
		case 5:							// if the user chooses a Demon to verse
			PracticeResults(demon);		// call PracticeResults function that takes a Demon as a parameter
			validInput = true;			// User input is valid, exit loop
			break;						
		default:						// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}

void Game::PracticeResults(Enemy& beast)
{
	string beastName = beast.GetName();	// beastName will be easier to use in code (is the name of the beast the user chose)

	while (character.isAlive() && beast.isAlive()) // If both the player and the beast is still alive continue this loop
	{
		// the player will attack the beast first
		int damage = character.attack();	// damage is the value of the user's attack value
		cout << "You hit for " << damage << " damage. " << endl;
		beast.takeDamage(damage);	// take the damage away from the beast's health
		if (!beast.isAlive()) // if the beast dies, user has won
		{
			cout << "You have defeated the " << beastName << "!" << endl; // inform the user
		}
		else {}	// continue otherwise
		if (character.isAlive() && beast.isAlive()) // If both the player and the beast is still alive
		{
			int damage = beast.Attack();	// damage is the value of the beast's attack value
			cout << "The " << beastName << " attacks you for " << damage << " damage." << endl;
			character.takeDamage(damage);	// take the damage away from the beast's health
			if (!character.isAlive()) // if the user dies, beast has won
			{
				cout << "You have been defeated by the " << beastName << endl; // inform the user
			}
			else {}	// continue otherwise
		}
	}
	// Once player or beast has been defeated
	cout << "The battle is over. ";
	if (character.isAlive())	// if the user is alive
	{
		cout << "You have gained 20 gold and 2 health." << endl;
		character.playerStore.gold += 20;	// add 20 to the user's gold
		character.levelUp(2);				// add 2 to the user's health
	}
	else
	{
		int loss = (int)(character.playerStore.gold * 0.2);
		cout << "You have lost " << loss << " gold." << endl;
		character.playerStore.gold -= loss;	// subtract 20% of the user's gold
	}

	character.restoreHealth();	// restore health to maxHealth value

	int decision;
	bool decisionMade = false;

	// Loops through until a valid response is given by the user (valid input: 0)
	while (decisionMade == false)
	{
		cout << "Enter 0 to return." << endl;
		cin >> decision; cout << endl;	// user input to return back to battle arena

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}

		switch (decision)
		{
		case 0:						// if the player wants to go back
			BattleArena();			// call BattleArena function
			decisionMade = true;	// User input is valid, exit loop
			break;
		default:					// If input is invalid, inform the user
			cout << "You did not enter a valid response. " << endl; cout << endl;
		}
	}
}


