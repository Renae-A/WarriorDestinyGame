#include "stdafx.h"
#include "Game.h"

void Game::EnemyStatistics()
{
	cout << "~~~~ Enemy Statistics ~~~~" << endl; cout << endl;

	cout << "You walk around the arena entrance to find a large board with some information." << endl; cout << endl;

	cout << "Beasts:" << endl; cout << endl;
	for (int i = 0; i < 8; i++)	// for each Enemy
	{
		cout << (i + 1) << ". " << theEnemies.enemyList[i].name << endl;				// display Enemy name
		cout << "Health: " << theEnemies.enemyList[i].maxHealth;						// display Enemy maximum health
		cout << "	Attack: " << theEnemies.enemyList[i].attack << endl; cout << endl;	// display Enemy attack value
	}
	cout << endl;

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

