#include "stdafx.h"
#include "Cyclops.h"


Cyclops::Cyclops()
	: Enemy()
{
	attack = 30;
	maxHealth = 80;
	health = maxHealth;
	name = "Cyclops";
}


Cyclops::~Cyclops()
{
}

int Cyclops::Attack()
{
	return attack;	// return attack value
}

void Cyclops::takeDamage(int damage)
{
	health -= damage;	// reduces health by damage value
	if (health <= 0)	// if the health is less than 0
		health = 0;		// set health to 0 (cyclops has died)
}

int Cyclops::getMaxHealth()
{
	return maxHealth;	// return maximum health value
}

int Cyclops::getAttackValue()
{
	return attack;		// return attack value
}

string Cyclops::getName()
{
	return name;		// return name of beast
}
