#include "stdafx.h"
#include "Game.h"
#include "AllEnemyHeaders.h"
#include <random>
#include <iostream>
#include <vector>

using namespace std;

void Game::Tournament()
{
	cout << "~~~~ Tournament ~~~~" << endl; cout << endl;

	cout << "Battle a group of five beasts of your choice in the arena." << endl;
	cout << "You will attack first, then each of the beast will attack you one by one." << endl;
	cout << "If you win against the whole group of beasts, you win 100 gold and you will gain 5 health." << endl;
	cout << "If you lose against beasts, you will lose 30% of your current gold." << endl;
	cout << "Once you accept battle, you cannot return until the battle is over." << endl; cout << endl;

	cout << "Would you like enter a tournament?" << endl; cout << endl;
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
		case 1:					// If user wants to start tournament
			StartTournament();	// Calls StartTournament function
			validInput = true;	// User input is valid, exit loop
			break;
		case 2:					// If user wants to go back to battale arena
			BattleArena();		// Calls BattleArena function
			validInput = true;	// User input is valid, exit loop
			break;
		default:				// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}

void Game::StartTournament()
{
	cout << "Which group of beasts would you like to battle against in tournament?" << endl; cout << endl;

	for (int i = 0; i < 5; i++)	// for every lower class Enemy
	{
		cout << (i + 1) << ". " << theEnemies.enemyList[i].name << endl;	// display name
	}
	int decision;
	bool validInput = false;

	// Loops through until a valid response is given by the user (valid input: 1, and 2)
	while (validInput == false)
	{
		cout << "Enter a number: ";
		cin >> decision; cout << endl;	// User input to decide which Enemy they want to battle
		cout << endl;

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}
		switch (decision)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			TournamentResults(decision);	// call TournamentResults function
			break;
		default:	// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}



void Game::TournamentResults(int decision)
{
	const int intialGroupSize = 5;

	Cyclops cyclops;
	Centaur centaur;
	Ogre ogre;
	Demon demon;
	Ghoul ghoul;

	vector<Cyclops> cyclopsGroup;
	vector<Centaur> centaurGroup;
	vector<Ogre> ogreGroup;
	vector<Demon> demonGroup;
	vector<Ghoul> ghoulGroup;


	for (int i = 0; i < intialGroupSize; i++)	// create a vector of 5 Ghouls
	{
		ghoulGroup.push_back(Ghoul(ghoul));
	}

	for (int i = 0; i < intialGroupSize; i++)	// create a vector of 5 Cyclops
	{
		cyclopsGroup.push_back(Cyclops(cyclops));
	}

	for (int i = 0; i < intialGroupSize; i++)	// create a vector of 5 Centaurs
	{
		centaurGroup.push_back(Centaur(centaur));
	}

	for (int i = 0; i < intialGroupSize; i++)	// create a vector of 5 Ogres
	{
		ogreGroup.push_back(Ogre(ogre));
	}

	for (int i = 0; i < intialGroupSize; i++)	// create a vector of 5 Demons
	{
		demonGroup.push_back(Demon(demon));
	}

	switch (decision)
	{
	case 1:
		while (character.isAlive() && GhoulAlive(ghoulGroup)) // If both the user and a beast is still alive
		{
			if (GhoulAlive(ghoulGroup))	
			{
				random_device rd; // obtain a random number from hardware
				mt19937 eng(rd()); // seed the generator
				uniform_int_distribution<> distr(0, (ghoulGroup.size()-1)); // define the range
				int woundedBeast = distr(eng);

				int damage = character.attack();	// damage equals the value of user's attack
				cout << "You hit for " << damage << " damage. " << endl;
				ghoulGroup[woundedBeast].takeDamage(damage);	// take damage away from the first beast's health
				if (!ghoulGroup[woundedBeast].isAlive()) // if the beast dies, it is removed from the group
				{
					cout << "A ghoul is defeated." << endl;	// inform user
					ghoulGroup.erase(ghoulGroup.begin());	// remove the first beast in the vector
				}
				else {}
			}
			else
			{
				break;
			}
			if (character.isAlive() && GhoulAlive(ghoulGroup))  // If both the user and a beast is still alive
			{
				for (unsigned int i = ghoulGroup.size() - 1; i < ghoulGroup.size(); --i) // loop through beasts
				{
					if (character.isAlive())
					{
						int damage = ghoulGroup[i].Attack();	// damage equals the value of beast's attack
						cout << "A ghoul attacks you for " << damage << " damage." << endl;
						character.takeDamage(damage);	// take damage away from the user's health
						if (!character.isAlive())	// if the user is defeated
						{
							cout << "You have been defeated by the ghouls." << endl; cout << endl;
							cout << ghoulGroup.size() << " ghouls are still standing." << endl;
							for (unsigned int i = 0; i < ghoulGroup.size(); i++)
							{
								cout << "Ghoul " << (i + 1) << " has " << ghoulGroup[i].getHealth() << " health left." << endl;
							}
							cout << endl;
						}
						else {}
					}
					else
					{
						break;
					}
				}
			}
		}
	case 2:
		while (character.isAlive() && CyclopsAlive(cyclopsGroup)) // If both the user and a beast is still alive
		{
			if (CyclopsAlive(cyclopsGroup))
			{
				random_device rd; // obtain a random number from hardware
				mt19937 eng(rd()); // seed the generator
				uniform_int_distribution<> distr(0, (cyclopsGroup.size()-1)); // define the range
				int woundedBeast = distr(eng);

				int damage = character.attack();	// damage equals the value of user's attack
				cout << "You hit for " << damage << " damage. " << endl;
				cyclopsGroup[woundedBeast].takeDamage(damage);	// take damage away from the first beast's health
				if (!cyclopsGroup[woundedBeast].isAlive()) // if the beast dies, it is removed from the group
				{
					cout << "A cyclops is defeated." << endl;	// inform user
					cyclopsGroup.erase(cyclopsGroup.begin());	// remove the first beast in the vector
				}
				else {}
			}
			else
			{
				break;
			}
			if (character.isAlive() && CyclopsAlive(cyclopsGroup))  // If both the user and a beast is still alive
			{
				for (unsigned int i = cyclopsGroup.size() - 1; i < cyclopsGroup.size(); --i) // loop through beasts
				{
					if (character.isAlive())
					{
						int damage = cyclopsGroup[i].Attack();	// damage equals the value of beast's attack
						cout << "A cyclops attacks you for " << damage << " damage." << endl;
						character.takeDamage(damage);	// take damage away from the user's health
						if (!character.isAlive())	// if the user is defeated
						{
							cout << "You have been defeated by the cyclops." << endl; cout << endl;
							cout << cyclopsGroup.size() << " cyclops are still standing." << endl;
							for (unsigned int i = 0; i < cyclopsGroup.size(); i++)
							{
								cout << "Cyclops " << (i + 1) << " has " << cyclopsGroup[i].getHealth() << " health left." << endl;
							}
							cout << endl;
						}
						else {}
					}
					else
					{
						break;
					}
				}
			}
		}
	case 3:
		while (character.isAlive() && CentaurAlive(centaurGroup)) // If both the user and a beast is still alive
		{
			if (CentaurAlive(centaurGroup))
			{
				random_device rd; // obtain a random number from hardware
				mt19937 eng(rd()); // seed the generator
				uniform_int_distribution<> distr(0, (centaurGroup.size()-1)); // define the range
				int woundedBeast = distr(eng);

				int damage = character.attack();	// damage equals the value of user's attack
				cout << "You hit for " << damage << " damage. " << endl;
				centaurGroup[woundedBeast].takeDamage(damage);	// take damage away from the first beast's health
				if (!centaurGroup[woundedBeast].isAlive()) // if the beast dies, it is removed from the group
				{
					cout << "A centaur is defeated." << endl;	// inform user
					centaurGroup.erase(centaurGroup.begin());	// remove the first beast in the vector
				}
				else {}
			}
			else
			{
				break;
			}
			if (character.isAlive() && CentaurAlive(centaurGroup))  // If both the user and a beast is still alive
			{
				for (unsigned int i = centaurGroup.size() - 1; i < centaurGroup.size(); --i) // loop through beasts
				{
					if (character.isAlive())
					{
						int damage = centaurGroup[i].Attack();	// damage equals the value of beast's attack
						cout << "A centaur attacks you for " << damage << " damage." << endl;
						character.takeDamage(damage);	// take damage away from the user's health
						if (!character.isAlive())	// if the user is defeated
						{
							cout << "You have been defeated by the centaurs." << endl; cout << endl;
							cout << centaurGroup.size() << " centaurs are still standing." << endl;
							for (unsigned int i = 0; i < centaurGroup.size(); i++)
							{
								cout << "Centaur " << (i + 1) << " has " << centaurGroup[i].getHealth() << " health left." << endl;
							}
							cout << endl;
						}
						else {}
					}
					else
					{
						break;
					}
				}
			}
		}
	case 4:
		while (character.isAlive() && OgreAlive(ogreGroup)) // If both the user and a beast is still alive
		{
			if (OgreAlive(ogreGroup))
			{
				random_device rd; // obtain a random number from hardware
				mt19937 eng(rd()); // seed the generator
				uniform_int_distribution<> distr(0, (ogreGroup.size()-1)); // define the range
				int woundedBeast = distr(eng);

				int damage = character.attack();	// damage equals the value of user's attack
				cout << "You hit for " << damage << " damage. " << endl;
				ogreGroup[woundedBeast].takeDamage(damage);	// take damage away from the first beast's health
				if (!ogreGroup[woundedBeast].isAlive()) // if the beast dies, it is removed from the group
				{
					cout << "An ogre is defeated." << endl;	// inform user
					ogreGroup.erase(ogreGroup.begin());	// remove the first beast in the vector
				}
				else {}
			}
			else
			{
				break;
			}
			if (character.isAlive() && OgreAlive(ogreGroup))  // If both the user and a beast is still alive
			{
				for (unsigned int i = ogreGroup.size() - 1; i < ogreGroup.size(); --i) // loop through beasts
				{
					if (character.isAlive())
					{
						int damage = ogreGroup[i].Attack();	// damage equals the value of beast's attack
						cout << "An ogre attacks you for " << damage << " damage." << endl;
						character.takeDamage(damage);	// take damage away from the user's health
						if (!character.isAlive())	// if the user is defeated
						{
							cout << "You have been defeated by the ogres." << endl; cout << endl;
							cout << ogreGroup.size() << " ogres are still standing." << endl;
							for (unsigned int i = 0; i < ogreGroup.size(); i++)
							{
								cout << "Ogre " << (i + 1) << " has " << ogreGroup[i].getHealth() << " health left." << endl;
							}
							cout << endl;
						}
						else {}
					}
					else
					{
						break;
					}
				}
			}
		}
	case 5:
		while (character.isAlive() && DemonAlive(demonGroup)) // If both the user and a beast is still alive
		{
			if (DemonAlive(demonGroup))
			{
				random_device rd; // obtain a random number from hardware
				mt19937 eng(rd()); // seed the generator
				uniform_int_distribution<> distr(0, (demonGroup.size()-1)); // define the range
				int woundedBeast = distr(eng);

				int damage = character.attack();	// damage equals the value of user's attack
				cout << "You hit for " << damage << " damage. " << endl;
				demonGroup[woundedBeast].takeDamage(damage);	// take damage away from the first beast's health
				if (!demonGroup[woundedBeast].isAlive()) // if the beast dies, it is removed from the group
				{
					cout << "A demon is defeated." << endl;	// inform user
					demonGroup.erase(demonGroup.begin());	// remove the first beast in the vector
				}
				else {}
			}
			else
			{
				break;
			}
			if (character.isAlive() && DemonAlive(demonGroup))  // If both the user and a beast is still alive
			{
				for (unsigned int i = demonGroup.size() - 1; i < demonGroup.size(); --i) // loop through beasts
				{
					if (character.isAlive())
					{
						int damage = demonGroup[i].Attack();	// damage equals the value of beast's attack
						cout << "A demon attacks you for " << damage << " damage." << endl;
						character.takeDamage(damage);	// take damage away from the user's health
						if (!character.isAlive())	// if the user is defeated
						{
							cout << "You have been defeated by the demons." << endl; cout << endl;
							cout << demonGroup.size() << " demons are still standing." << endl;
							for (unsigned int i = 0; i < demonGroup.size(); i++)
							{
								cout << "Demon " << (i + 1) << " has " << demonGroup[i].getHealth() << " health left." << endl;
							}
							cout << endl;
						}
						else {}
					}
					else
					{
						break;
					}
				}
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and either the user or the beasts win
	cout << "The tournament is over. ";
	if (character.isAlive())	// if user won
	{
		cout << "You have gained 100 gold and 5 health." << endl;
		character.playerStore.gold += 100;	// add 100 to user gold
		character.levelUp(5);				// add 5 to user maxHealth
	}
	else	// if Enemy won
	{
		int loss = (int)(character.playerStore.gold * 0.3);
		cout << "You have lost " << loss << " gold." << endl; cout << endl;
		character.playerStore.gold -= loss;	// subtract 30% of user gold
	}
	character.restoreHealth();	// restore user health

	
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










