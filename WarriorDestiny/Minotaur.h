#include "stdafx.h"
#include "Enemy.h"
#pragma once

class Minotaur : public Enemy
{
public:
	Minotaur();
	~Minotaur();
	
	virtual int Attack();					// Attack() will return the attack value of Minotaur
	virtual void takeDamage(int damage);	// takeDamage() will subtract the user's character damage from the Minotaur's health

	int getMaxHealth();						// getMaxHealth() will return the value of Minotaur's maximum health
	int getAttackValue();					// getAttackValue() will return the value of Minotaur's attack
	string getName();						// getName() will return the name of the Enemy "Minotaur"
};