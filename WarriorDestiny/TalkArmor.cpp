#include "stdafx.h"
#include "Game.h"
#include <iostream>

using namespace std;

void Game::TalkArmor()
{
	bool validInput = false;
	int choice;

	// Loops through until a valid response is given by the user (valid input: 1, 2, 3 and 4)
	while (validInput == false)
	{
		cout << "Armor smith: Hmm? What would you like to talk about small fry?" << endl;
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
			cout << "Armor smith: You want to know about me, eh?" << endl;
			cout << "Armor smith: Well, I grew up here when I was a wee little boy. I worked in the family business all my life." << endl;
			cout << "Armor smith: This is the best armor shop within miles and I am mighty proud to now be the owner of this establishment." << endl;
			cout << "Armor smith: As much as I would have loved to have travelled more, I find this job is my true calling." << endl;
			cout << "Armor smith: Anyway, that's enough about me." << endl; cout << endl;
			break;
		case 2:	// if user wants to talk about the boss competition
			cout << "Armor smith: Aghh yes! The competition for true warriors!" << endl;
			cout << "Armor smith: They say whoever can beat the Dragon wins 10000 gold." << endl;
			cout << "Armor smith: If I could get my hands dirty and defeat the Dragon myself, I would.." << endl;
			cout << "Armor smith: However, I must stay here and take care of the business." << endl;
			cout << "You: I plan on taking on the Dragon myself actually." << endl;
			cout << "Armor smith: YOU! Hah! That is a laugh, my friend. Well, if you do, I will be sure to watch that battle at the arena." << endl; cout << endl;
			break;
		case 3:	// if user wants to talk about the Golem City
			cout << "Armor smith: Golem City has been here for many centuries." << endl;
			cout << "Armor smith: It began as a small farming town and has now become the massively populated city you see today." << endl;
			cout << "Armor smith: The Battle Arena is one of the biggest attractions, second to my armor store of course, haha!" << endl;
			cout << "Armor smith: We are in the land of the rich, son. Rich with life and wealth!" << endl; cout << endl;
			break;
		case 4:	// if user wants to go back
			ArmorShopMenu();	// call ArmorShopMenu function
			break;
		default:	// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}