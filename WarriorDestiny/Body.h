#pragma once
#include "Item.h"
#include "StringUtility.h"
#include <string>

using namespace std;

// BodyPart is used to create the user's body parts and add or remove Items from that body part
struct BodyPart
{
	string name;			// name of the BodyPart
	Item item;				// the Item equipped to the BodyPart
	
	void Save(ostream& F);	// function to save body part to file
	void Load(istream& F);	// function to load body part to game
};

// UserBody is a list of the user's body parts and the Items on those body parts 
struct UserBody
{
	BodyPart BodyList[7];	// a list of every BodyPart the user's character has

	void Save(ostream& F);	// function to save user body to file
	void Load(istream& F);	// function to load user body to game
};