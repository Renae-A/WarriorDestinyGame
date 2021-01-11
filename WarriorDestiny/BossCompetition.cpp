#include "stdafx.h"
#include "Game.h"
#include <iostream>

using namespace std;

void Game::BossCompetition()
{
	cout << "~~~~ Boss Competition ~~~~" << endl; cout << endl;

	cout << "Battle a boss beast of your choice in the arena." << endl;
	cout << "If you win against one of the lower class bosses, you win 1000 gold and you will gain 20 health." << endl;
	cout << "If you win against the Dragon, you win 10000 gold and you will gain 100 health." << endl;
	cout << "If you lose against the boss, you will lose 50% of your current gold." << endl; 
	cout << "Once you accept battle, you cannot return until the battle is over." << endl; cout << endl;

	cout << "Are you sure you want to enter the boss competition?" << endl; cout << endl;
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
		case 1:					// If player wants to enter boss competition
			StartCompetition();	// Call StartCompetition function
			validInput = true;	// User input is valid, exit loop
			break;
		case 2:					// If player does not want to enter boss competition, and wants to go back
			BattleArena();		// Call BattleArena function
			validInput = true;	// User input is valid, exit loop
			break;
		default:				// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}

void Game::StartCompetition()
{
	Giant giant;			// create a Giant for if the user chooses the Giant to verse
	Minotaur minotaur;		// create a Minotaur for if the user chooses the Minotaur to verse
	Dragon dragon;			// create a Dragon for if the user chooses the Dragon to verse

	cout << "Which boss beast would you like to battle against?" << endl; cout << endl;

	for (int i = 5; i < 8; i++)	// for each Enemy boss
	{
		cout << (i - 4) << ". " << theEnemies.enemyList[i].name << endl;	// display their name
	}

	int decision;
	bool validInput = false;

	// Loops through until a valid response is given by the user (valid input: 1, 2 and 3)
	while (validInput == false)
	{
		cout << "Enter a number: ";
		cin >> decision; cout << endl;	// User input to decide what boss they want to verse
		cout << endl;

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}
		switch (decision)
		{
		case 1:								// if the user chooses a Giant to verse
			CompetitionResults(giant);		// call CompetitionResults function that takes a Giant as a parameter
			validInput = true;				// User input is valid, exit loop
			break;						
		case 2:								// if the user chooses a Minotaur to verse
			CompetitionResults(minotaur);	// call CompetitionResults function that takes a Minotaur as a parameter
			validInput = true;				// User input is valid, exit loop
			break;						
		case 3:								// if the user chooses a Dragon to verse
			CompetitionResults(dragon);		// call CompetitionResults function that takes a Dragon as a parameter
			validInput = true;				// User input is valid, exit loop
			break;						
		default:							// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}

void Game::CompetitionResults(Enemy& beast)
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
	cout << "The battle is over." << endl;
	if (character.isAlive())	// if the user is alive
	{
		if (beastName == "Dragon")	// if the beast was a Dragon
		{
			cout << "Congratulations! You have defeated the Dragon!" << endl;
			cout << "You have gained 10000 gold and 100 health." << endl;
			character.playerStore.gold += 10000;	// add 10000 to the user's gold
			character.levelUp(100);					// add 100 to the user's health
		}
		else	// if the beast was not a Dragon
		{
			cout << "You have gained 1000 gold and 20 health." << endl;
			character.playerStore.gold += 1000;		// add 1000 to the user's gold
			character.levelUp(20);					// add 20 to the user's health
		}
	}
	else	// if the beast is alive
	{
		int loss = (int)(character.playerStore.gold * 0.5);
		cout << "You have lost " << loss << " gold." << endl;
		character.playerStore.gold -= loss;	// subtract 50% of the user's gold
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


