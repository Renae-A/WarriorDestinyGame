#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void Game::SaveAndExit()
{
	int decision;
	bool decisionMade = false;

	// Loops through until a valid response is given by the user (valid input: 1, 2, 3 and 4)
	while (decisionMade == false)
	{
		cout << "What would you like to do?" << endl;
		cout << "If you decide to save, it will overwrite previous save file." << endl;
		cout << "1. Save and exit." << endl;
		cout << "2. Save and continue." << endl;
		cout << "3. Exit without saving." << endl;
		cout << "4. Go back." << endl;
		cin >> decision; cout << endl;

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}
		switch (decision)
		{
		case 1:						// if the user wants to save and exit game
			Save();					// call Save function
			cout << endl; cout << "Game save was successful." << endl; cout << endl;
			system("pause");
			exit(0);				// exit program
			decisionMade = true;	// User input is valid, exit loop
			break;
		case 2:						// if the user wants to save and continue game
			Save();					// call Save function
			cout << endl; cout << "Game save was successful." << endl; cout << endl;
			system("pause");
			menu();					// call menu function
			decisionMade = true;	// User input is valid, exit loop
			break;
		case 3:						// if the user wants to exit
			exit(0);				// exit program
			decisionMade = true;	// User input is valid, exit loop
			break;
		case 4:						// if the user wants to go back
			menu();					// call menu function
			decisionMade = true;	// User input is valid, exit loop
			break;
		default:					// If input is invalid, inform the user
			cout << "You did not enter a valid response. " << endl; cout << endl;
		}
	}
}

void Game::SaveDateAndTime()
{
	ofstream saveFile("savefile.dat", ios_base::out | ios_base::binary);	// opens the file to write to
	if (saveFile.good())	// if the file is open and works
	{
		time_t currentTime = time(NULL);	// set current time
		ctime_s(FOOTER_INFO, sizeof(FOOTER_INFO), &currentTime);	//  converts given time since epoch to a calendar local time and then to a textual representation
		saveFile.write(FOOTER_INFO, sizeof(FOOTER_INFO));	// write the current date and time to footer of file

		saveFile.close();	// close file
	}
	cout << "Save date and time to file successful." << endl; cout << endl;
	system("pause");
	menu();	// menu function is called
}

void Game::Save()
{
	ofstream saveFile("savefile.dat", ios_base::out | ios_base::binary);
	if (saveFile.good())
	{
		saveFile.write(HEADER_INFO, sizeof(HEADER_INFO));	// Save header info

		character.Save(saveFile);	// calls save function for character
		weaponStore.Save(saveFile);	// calls save function for weaponStore
		armorStore.Save(saveFile);	// calls save function for ArmorStore

		saveFile.close();	// close file
	}
}
