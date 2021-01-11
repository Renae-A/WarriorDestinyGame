#include "stdafx.h"
#include <iostream>
#include <string>
#pragma once

using namespace std;

struct anEnemy
{
	string name;	// the Enemy's name
	int maxHealth;	// the Enemy's maximum health
	int attack;		// the Enemy's attack value
};

struct Enemies
{
	anEnemy enemyList[8];	// the list of enemies and their information
};