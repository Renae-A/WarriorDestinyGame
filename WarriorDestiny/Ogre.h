#include "stdafx.h"
#include "Enemy.h"
#pragma once

class Ogre : public Enemy
{
public:
	Ogre();
	~Ogre();

	virtual int Attack();					// Attack() will return the attack value of Ogre
	virtual void takeDamage(int damage);	// takeDamage() will subtract the user's character damage from the Ogre's health

	int getMaxHealth();						// getMaxHealth() will return the value of Ogre's maximum health
	int getAttackValue();					// getAttackValue() will return the value of Ogre's attack
	string getName();						// getName() will return the name of the Enemy "Ogre"
};