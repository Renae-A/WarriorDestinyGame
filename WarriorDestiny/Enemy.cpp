#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

string Enemy::GetName()
{
	return name;		// return name of beast
}

int Enemy::Attack()
{
	return attack;	// return attack value
}

void Enemy::takeDamage(int damage)
{
	health -= damage;	// reduces health by damage value
	if (health <= 0)	// if the health is less than 0
		health = 0;		// set health to 0 (enemy has died)
}

bool Enemy::isAlive()
{
	return health > 0;	// return true if health is mroe than 0, false otherwise
}

int Enemy::getHealth()
{
	return health;	// return health value
}



