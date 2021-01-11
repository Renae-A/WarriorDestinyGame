#include "stdafx.h"
#include "Giant.h"


Giant::Giant()
	: Enemy()
{
	attack = 200;
	maxHealth = 500;
	health = maxHealth;
	name = "Giant";
}


Giant::~Giant()
{
}

int Giant::Attack()
{
	return attack;	// return attack value
}

void Giant::takeDamage(int damage)
{
	health -= damage;	// reduces health by damage value
	if (health <= 0)	// if the health is less than 0
		health = 0;		// set health to 0 (giant has died)
}

int Giant::getMaxHealth()
{
	return maxHealth;	// return maximum health value
}

int Giant::getAttackValue()
{
	return attack;		// return attack value
}

string Giant::getName()
{
	return name;		// return name of beast
}
