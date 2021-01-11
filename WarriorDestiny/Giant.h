#include "stdafx.h"
#include "Enemy.h"
#pragma once

class Giant : public Enemy
{
public:
	Giant();
	~Giant();

	virtual int Attack();					// Attack() will return the attack value of Giant
	virtual void takeDamage(int damage);	// takeDamage() will subtract the user's character damage from the Giant's health

	int getMaxHealth();						// getMaxHealth() will return the value of Giant's maximum health
	int getAttackValue();					// getAttackValue() will return the value of Giant's attack
	string getName();						// getName() will return the name of the Enemy "Giant"
};