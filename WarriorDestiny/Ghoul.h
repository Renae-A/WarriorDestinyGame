#include "stdafx.h"
#include "Enemy.h"
#pragma once

class Ghoul : public Enemy
{
public:
	Ghoul();
	~Ghoul();

	virtual int Attack();					// Attack() will return the attack value of Ghoul
	virtual void takeDamage(int damage);	// takeDamage() will subtract the user's character damage from the Ghoul's health

	int getMaxHealth();						// getMaxHealth() will return the value of Ghoul's maximum health
	int getAttackValue();					// getAttackValue() will return the value of Ghoul's attack
	string getName();						// getName() will return the name of the Enemy "Ghoul"
};