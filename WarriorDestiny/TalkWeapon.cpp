#include "stdafx.h"
#include "Game.h"
#include <iostream>

using namespace std;

void Game::TalkWeapon()
{
	bool validInput = false;
	int choice;

	// Loops through until a valid response is given by the user (valid input: 1, 2, 3 and 4)
	while (validInput == false)
	{
		cout << "Weapon smith: So you want to know the ins and outs?" << endl;
		cout << "1. Ask about shopkeeper" << endl;
		cout << "2. Ask about boss competition" << endl;
		cout << "3. Ask about Golem City" << endl;
		cout << "4. Return to shop menu" << endl; cout << endl;
		cout << "Enter a number to decide: ";
		cin >> choice;	// user input to decide what they want to ask about
		cout << endl;

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of a int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}
		
		switch (choice)
		{
		case 1:	// if user wants to talk about the shopkeeper
			cout << "Weapon smith: I'm pretty well known around the city, I'm suprised you don't know." << endl;
			cout << "Weapon smith: I used to teach science specialising in rocks and minerals." << endl;
			cout << "Weapon smith: But I soon realised that that was not what I enjoyed." << endl;
			cout << "Weapon smith: I then was inspired by the city's Battle Arena to forge weapons and that hopefully sell them to the warriors who fought the beasts." << endl;
			cout << "Weapon smith: Now, that's where I am at. I am doing what I love." << endl; cout << endl;
			break;
		case 2:	// if user wants to talk about the boss competition
			cout << "Weapon smith: The competition has three bosses." << endl;
			cout << "Weapon smith: The Giant, the Minotaur and the Dragon." << endl;
			cout << "Weapon smith: You can make some serious gold by entering the competition but you really have to be skilled." << endl;
			cout << "Weapon smith: We have many people travel to fight the bosses but most of which leave defeated." << endl;
			cout << "Weapon smith: If you buy your weapons from here though, you will definitely have a better chance than any other weapon bought in the city." << endl; cout << endl;
			break;
		case 3:	// if user wants to talk about the Golem City
			cout << "Weapon smith: Golem City attracts many villagers from small towns." << endl;
			cout << "Weapon smith: The guarantee of protection within the city gates is one reason." << endl;
			cout << "Weapon smith: We have good trade with the surrounding cities and towns as well." << endl;
			cout << "Weapon smith: This is really the place to be." << endl; cout << endl;
			break;
		case 4:	// if user wants to go back
			WeaponShopMenu();	// call WeaponShopMenu function
			break;
		default:	// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}