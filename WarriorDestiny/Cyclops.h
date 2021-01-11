#include "stdafx.h"
#include "Enemy.h"
#pragma once

class Cyclops : public Enemy
{
public:
	Cyclops();								
	~Cyclops();								

	virtual int Attack();					// Attack() will return the attack value of Cyclops
	virtual void takeDamage(int damage);	// takeDamage() will subtract the user's character damage from the Cyclops' health

	int getMaxHealth();						// getMaxHealth() will return the value of Cyclops' maximum health
	int getAttackValue();					// getAttackValue() will return the value of Cyclops' attack
	string getName();						// getName() will return the name of the Enemy "Cyclops"
};			
