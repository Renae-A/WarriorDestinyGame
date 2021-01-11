#include "stdafx.h"
#include "Game.h"
#include <algorithm>

Game::Game()
{
	WeaponInventoryInitialisation();
	ArmorInventoryInitialisation();
	initialiseEnemyList();
}

Game::~Game()
{
}

void Game::WeaponInventoryInitialisation()
{
	weaponStore.gold = 1290;

	weaponStore.itemList.push_back({ 250, "Sword", 3, 25 });				// Store's Sword (price, name, quantity, bonus attack)
	weaponStore.itemList.push_back({ 150, "Whip", 6, 20 });					// Store's Whip (price, name, quantity, bonus attack)
	weaponStore.itemList.push_back({ 200, "Hammer", 2, 25 });				// Store's Hammer (price, name, quantity, bonus attack)
	weaponStore.itemList.push_back({ 400, "Axe", 3, 30 });					// Store's Axe (price, name, quantity, bonus attack)
	weaponStore.itemList.push_back({ 800, "Two-Handed Sword", 5, 65 });		// Store's Two-Handed Sword (price, name, quantity, bonus attack)
	weaponStore.itemList.push_back({ 500, "Bow and Arrows", 2, 35 });		// Store's Bow and Arrows (price, name, quantity, bonus attack)
}

void Game::ArmorInventoryInitialisation()
{
	armorStore.gold = 1740;

	armorStore.itemList.push_back({ 300, "Helmet", 3, 20 });			// Store's Helmet (price, name, quantity, bonus hitpoints)
	armorStore.itemList.push_back({ 170, "Boots", 6, 10 });				// Store's Boots (price, name, quantity, bonus hitpoints)
	armorStore.itemList.push_back({ 200, "Gauntlets", 2, 15 });			// Store's Gauntlets (price, name, quantity, bonus hitpoints)
	armorStore.itemList.push_back({ 600, "Pants", 3, 30 });				// Store's Pants (price, name, quantity, bonus hitpoints)
	armorStore.itemList.push_back({ 550, "Shield", 5, 15 });			// Store's Shield (price, name, quantity, bonus hitpoints)
	armorStore.itemList.push_back({ 1000, "Chestplate", 2, 50 });		// Store's Chestplate (price, name, quantity, bonus hitpoints)
}

void Game::initialiseEnemyList()
{
	theEnemies.enemyList[0] = { "Ghoul", 50 , 10 };						// anEnemy Ghoul(name, maxHealth, attack)
	theEnemies.enemyList[1] = { "Cyclops", 80, 30 };					// anEnemy Cyclops(name, maxHealth, attack)
	theEnemies.enemyList[2] = { "Centaur", 140, 70 };					// anEnemy Centaur(name, maxHealth, attack)
	theEnemies.enemyList[3] = { "Ogre", 250, 120 };						// anEnemy Ogre(name, maxHealth, attack)
	theEnemies.enemyList[4] = { "Demon", 300, 175 };					// anEnemy Demon(name, maxHealth, attack)
	theEnemies.enemyList[5] = { "Giant", 500, 200 };					// anEnemy Giant(name, maxHealth, attack)
	theEnemies.enemyList[6] = { "Minotaur", 1000, 250 };				// anEnemy Minotaur(name, maxHealth, attack)
	theEnemies.enemyList[7] = { "Dragon", 2000, 300 };					// anEnemy Dragon(name, maxHealth, attack)
}


