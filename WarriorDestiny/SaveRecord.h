#include "Item.h"
#include "Player.h"
#include <string>
#include <iostream>
#pragma once

using namespace std;

struct SaveRecord
{

	SaveRecord();
	SaveRecord(const int* saveNumber, const char* name, const int* maxHealth, const int* attack, const UserBody* playerBody, const Inventory* playerStore);

	// Functions to read/write
	bool		ReadFile(istream& inStream);
	bool		SaveFile(ostream& outStream);
	bool		ReadBinary(istream& inStream);
	bool		WriteBinary(ostream& outStream);

	bool		Compare(const string& name);

	void		Print();

	void		SetSaveNumber(const int* saveNumber);
	void		SetName(const char* name);
	void		SetMaxHealth(const int* maxHealth);
	void		SetAttack(const int* attack);
	void		SetPlayerBody(const UserBody* playerBody);
	void		SetPlayerStore(const Inventory* playerStore);

protected:

	char		name[80];
	int			maxHealth;
	int			attack;
	UserBody	playerBody;
	Inventory	playerStore;


protected:
	// Helper function to clear a char array
	void clearCharArray(char arr[], unsigned int size);
};
