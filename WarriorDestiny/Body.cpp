#include "stdafx.h"
#include "Body.h"

void UserBody::Save(ostream& F)		// save body list to file
{
	for (int i = 0; i < 7; i++)		// for each body part in the body list
	{
		BodyList[i].Save(F);		// save to file
	}
}

void UserBody::Load(istream & F)	// load body list to game
{
	for (int i = 0; i < 7; i++)		// for each body part in the body list
	{
		BodyList[i].Load(F);		// load to game
	}
}

void BodyPart::Save(ostream & F)	// save body part to file
{
	WriteString(F, name);			// save name to file
}

void BodyPart::Load(istream & F)	// load body list to game
{
	ReadString(F, name);			// load name to file
}
