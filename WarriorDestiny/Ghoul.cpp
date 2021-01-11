#include "stdafx.h"
#include "Ghoul.h"


Ghoul::Ghoul()
	: Enemy()
{
	attack = 10;
	maxHealth = 50;
	health = maxHealth;
	name = "Ghoul";
}


Ghoul::~Ghoul()
{
}

int Ghoul::Attack()
{
	return attack;	// return attack value
}

void Ghoul::takeDamage(int damage)
{
	health -= damage;	// reduces health by damage value
	if (health <= 0)	// if the health is less than 0
		health = 0;		// set health to 0 (ghoul has died)
}

int Ghoul::getMaxHealth()
{
	return maxHealth;	// return maximum health value
}

int Ghoul::getAttackValue()
{
	return attack;		// return attack value
}

string Ghoul::getName()
{
	return name;		// return name of beast
}
