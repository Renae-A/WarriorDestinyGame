#include "stdafx.h"
#include "Enemy.h"
#pragma once

class Dragon : public Enemy
{
public:
	Dragon();
	~Dragon();

	virtual int Attack();					// Attack() will return the attack value of Dragon
	virtual void takeDamage(int damage);	// takeDamage() will subtract the user's character damage from the Dragon's health

	int getMaxHealth();						// getMaxHealth() will return the value of Dragon's maximum health
	int getAttackValue();					// getAttackValue() will return the value of Dragon's attack
	string getName();						// getName() will return the name of the Enemy "Dragon"
};
