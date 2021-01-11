#include "stdafx.h"
#include "SaveRecord.h"

SaveRecord::SaveRecord()
{
}

SaveRecord::SaveRecord(const int * saveNumber, const char * name, const int * maxHealth, const int * attack, const UserBody * playerBody, const Inventory * playerStore)
{
}

bool SaveRecord::ReadFile(istream & inStream)
{
	return false;
}

bool SaveRecord::SaveFile(ostream & outStream)
{
	return false;
}

bool SaveRecord::ReadBinary(istream & inStream)
{
	return false;
}

bool SaveRecord::WriteBinary(ostream & outStream)
{
	return false;
}

bool SaveRecord::Compare(const string & name)
{
	return false;
}

void SaveRecord::Print()
{
}

void SaveRecord::SetSaveNumber(const int * saveNumber)
{
}

void SaveRecord::SetName(const char * name)
{
}

void SaveRecord::SetMaxHealth(const int * maxHealth)
{
}

void SaveRecord::SetAttack(const int * attack)
{
}

void SaveRecord::SetPlayerBody(const UserBody * playerBody)
{
}

void SaveRecord::SetPlayerStore(const Inventory * playerStore)
{
}


