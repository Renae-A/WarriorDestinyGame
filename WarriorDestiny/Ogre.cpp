#include "stdafx.h"
#include "Ogre.h"


Ogre::Ogre()
	: Enemy()
{
	attack = 120;
	maxHealth = 250;
	health = maxHealth;
	name = "Ogre";
}


Ogre::~Ogre()
{
}

int Ogre::Attack()
{
	return attack;	// return attack value
}

void Ogre::takeDamage(int damage)
{
	health -= damage;	// reduces health by damage value
	if (health <= 0)	// if the health is less than 0
		health = 0;		// set health to 0 (ogre has died)
}

int Ogre::getMaxHealth()
{
	return maxHealth;	// return maximum health value
}

int Ogre::getAttackValue()
{
	return attack;		// return attack value
}

string Ogre::getName()
{
	return name;		// return name of beast
}
