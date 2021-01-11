#include "stdafx.h"
#include "Demon.h"


Demon::Demon()
	: Enemy()
{
	attack = 175;
	maxHealth = 300;
	health = maxHealth;
	name = "Demon";
}


Demon::~Demon()
{
}

int Demon::Attack()
{
	return attack;	// return attack value
}

void Demon::takeDamage(int damage)
{
	health -= damage;	// reduces health by damage value
	if (health <= 0)	// if the health is less than 0
		health = 0;		// set health to 0 (demon has died)
}

int Demon::getMaxHealth()
{
	return maxHealth;	// return maximum health value
}

int Demon::getAttackValue()
{
	return attack;		// return attack value
}

string Demon::getName()
{
	return name;		// return name of beast
}
