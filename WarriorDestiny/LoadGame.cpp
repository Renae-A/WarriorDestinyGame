#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <fstream>

using namespace std;

void Game::LoadGame()
{
	ifstream loadFile("savefile.dat", ios_base::in | ios_base::binary);		// opens the file to read from
	

	if (loadFile.peek() == ifstream::traits_type::eof())	// if the file is empty
	{
		cout << "Previous game could not be located. Beginning new game..." << endl; cout << endl;	// inform user
		system("pause");
		NewGame();	// call NewGame function
	}

	if (loadFile.good())
	{
		// seek past header information
		loadFile.seekg(sizeof(HEADER_INFO));	// seek past the header of file
		character.Load(loadFile);				// load character from file
		weaponStore.Load(loadFile);				// load weaponStore from file
		armorStore.Load(loadFile);				// load armorStore from file
		loadFile.close();						// close file
		cout << "Game load was successful." << endl; cout << endl;
		menu();									// call menu function
	}
	else 
	{
		cout << "Previous game could not be located. Beginning new game..." << endl; cout << endl;	// inform user
		system("pause");
		NewGame();	// call NewGame function
	}
}


