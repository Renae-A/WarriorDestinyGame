#include "stdafx.h"
#include "Dragon.h"


Dragon::Dragon()
	: Enemy()
{
	attack = 300;
	maxHealth = 2000;
	health = maxHealth;
	name = "Dragon";
}


Dragon::~Dragon()
{
}

int Dragon::Attack()
{
	return attack;	// return attack value
}

void Dragon::takeDamage(int damage)
{
	health -= damage;	// reduces health by damage value
	if (health <= 0)	// if the health is less than 0
		health = 0;		// set health to 0 (dragon has died)
}

int Dragon::getMaxHealth()
{
	return maxHealth;	// return maximum health value
}

int Dragon::getAttackValue()
{
	return attack;		// return attack value
}

string Dragon::getName()
{
	return name;		// return name of beast
}
