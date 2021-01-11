#include "stdafx.h"
#include "Minotaur.h"


Minotaur::Minotaur()
	: Enemy()
{
	attack = 250;
	maxHealth = 1000;
	health = maxHealth;
	name = "Minotaur";
}


Minotaur::~Minotaur()
{
}

int Minotaur::Attack()
{
	return attack;	// return attack value
}

void Minotaur::takeDamage(int damage)
{
	health -= damage;	// reduces health by damage value
	if (health <= 0)	// if the health is less than 0
		health = 0;		// set health to 0 (minotaur has died)
}

int Minotaur::getMaxHealth()
{
	return maxHealth;	// return maximum health value
}

int Minotaur::getAttackValue()
{
	return attack;		// return attack value
}

string Minotaur::getName()
{
	return name;		// return name of beast
}
