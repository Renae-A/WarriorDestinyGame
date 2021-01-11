#include <string>
#include "EnemyList.h"
#pragma once

using namespace std;

class Enemy 
{
public:
	Enemy();
	~Enemy();

	string GetName();						// GetName() returns the name of the Enemy
	virtual int Attack();					// Attack() returns the value of attack
	virtual void takeDamage(int damage);	// takeDamage takes the parameter of an integer damage which will be deducted from the Enemy's health
	bool isAlive();							// isAlive is called to check if an Enemy is alive which will return true or false if the Enemy is dead 
	int getHealth();						

	Enemies theEnemies;						// theEnemies (the list of Enemies) is being declared 

protected:
	int attack;								// the value of attack the Enemy has
	int health;								// the value of health the Enemy currently has
	int maxHealth;							// the value of maxHealth the Enemy has
	string name;							// name of the Enemy
};

