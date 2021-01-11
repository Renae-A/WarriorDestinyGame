#include "stdafx.h"
#include "Enemy.h"
#pragma once

class Centaur : public Enemy
{
public:
	Centaur();
	~Centaur();

	virtual int Attack();					// Attack() will return the attack value of Centaur
	virtual void takeDamage(int damage);	// takeDamage() will subtract the user's character damage from the Centaur's health

	int getMaxHealth();						// getMaxHealth() will return the value of Centaur's maximum health
	int getAttackValue();					// getAttackValue() will return the value of Centaur's attack
	string getName();						// getName() will return the name of the Enemy "Centaur"
};

