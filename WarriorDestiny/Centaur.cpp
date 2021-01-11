#include "stdafx.h"
#include "Centaur.h"


Centaur::Centaur()
	: Enemy()
{
	attack = 70;
	maxHealth = 140;
	health = maxHealth;
	name = "Centaur";
}


Centaur::~Centaur()
{
}

int Centaur::Attack()
{
	return attack;	// return attack value
}

void Centaur::takeDamage(int damage)
{
	health -= damage;	// reduces health by damage value
	if (health <= 0)	// if the health is less than 0
		health = 0;		// set health to 0 (centaur has died)
}

int Centaur::getMaxHealth()
{
	return maxHealth;	// return maximum health value
}

int Centaur::getAttackValue()
{
	return attack;		// return attack value
}

string Centaur::getName()
{
	return name;		// return name of beast
}
