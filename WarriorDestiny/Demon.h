#include "stdafx.h"
#include "Enemy.h"
#pragma once

class Demon : public Enemy
{
public:
	Demon();
	~Demon();

	virtual int Attack();					// Attack() will return the attack value of Demon
	virtual void takeDamage(int damage);	// takeDamage() will subtract the user's character damage from the Demon's health

	int getMaxHealth();						// getMaxHealth() will return the value of Demon's maximum health
	int getAttackValue();					// getAttackValue() will return the value of Demon's attack
	string getName();						// getName() will return the name of the Enemy "Demon"
};
