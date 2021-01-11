#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include "StringUtility.h"
#include <iostream>

using namespace std;

Player::Player()
{
	name = "Willard";				// Default name (however this is likely never to be used)
	maxHealth = 100;				// maxHealth intially set to 100 (will be modified in game)
	health = maxHealth;				// health intially set to maxHealth value (will be modified in game)
	attackValue = 10;				// attackValue intially set to 10 (will be modified in game)
	
	Empty = { 0, "Nothing", 0, 0 };	// defines what Empty means 
	
	initialisePlayerInventory();	// calls initialisePlayerInventory function
	initialisePlayerBody();			// calls initialisePlayerBody function
}

Player::~Player()
{
}

bool Player::isAlive()
{
	return health > 0;	// return true is character health is more than 0, false otherwise
}

void Player::takeDamage(int damage)
{
	health -= damage;	// reduces health by damage value
	if (health <= 0)	// if the health is less than 0
		health = 0;		// set health to 0 (player has died)
}

int Player::attack()
{
	return attackValue;		// returns character attack value
}

int Player::getMaxHealth()
{
	return maxHealth;		// returns character maximum health
}

int Player::getAttackValue()
{
	return attackValue;		// returns character attack value
}

void Player::increaseAttack(Item & item)
{
	attackValue += item.bonus;	// increases the attack value by the bonus of the weapon
}

void Player::decreaseAttack(Item & item)
{
	attackValue -= item.bonus;	// decreases the attack value by the bonus of the weapon
}

void Player::increaseHealth(Item & item)
{
	maxHealth += item.bonus;	// increases the maximum health value by the bonus of the armor
}

void Player::decreaseHealth(Item & item)
{
	maxHealth -= item.bonus;	// decreases the maximum health value by the bonus of the armor
}

void Player::levelUp(int healthBonus)
{
	maxHealth += healthBonus;	// level up character health by bonus int
}

void Player::restoreHealth()
{
	health = maxHealth;			// set health back to maximum health value
}


void Player::Save(ostream & F)
{
	WriteString(F, name);						// save name to file
	F.write((char*)&maxHealth, sizeof(int));	// save maximum health to file
	F.write((char*)&attackValue, sizeof(int));	// save attack value to file
	playerBody.Save(F);							// save player body to file
	playerStore.Save(F);						// save player inventory to file
}

void Player::Load(istream & F)
{
	ReadString(F, name);						// load name from file
	F.read((char*)&maxHealth, sizeof(int));		// load maximum health from file
	F.read((char*)&attackValue, sizeof(int));	// load attack value from file
	playerBody.Load(F);							// load player body from file
	playerStore.Load(F);						// load player inventory from file
}

void Player::initialisePlayerInventory()
{
	playerStore.gold = 100;

	playerStore.itemList.push_back({ 250, "Sword", 0, 25 });				// Player's Sword (price, name, quantity, bonus attack)
	playerStore.itemList.push_back({ 150, "Whip", 0, 20 });					// Player's Whip (price, name, quantity, bonus attack)
	playerStore.itemList.push_back({ 200, "Hammer", 0, 25 });				// Player's Hammer (price, name, quantity, bonus attack)
	playerStore.itemList.push_back({ 400, "Axe", 0, 30 });					// Player's Axe (price, name, quantity, bonus attack)
	playerStore.itemList.push_back({ 800, "Two-Handed_Sword", 0, 65 });		// Player's Two-Handed Sword (price, name, quantity, bonus attack)
	playerStore.itemList.push_back({ 500, "Bow_and_Arrows", 0, 35 });		// Player's Bow and Arrows (price, name, quantity, bonus attack)
	playerStore.itemList.push_back({ 300, "Helmet", 0, 20 });				// Player's Helmet (price, name, quantity, bonus hitpoints)
	playerStore.itemList.push_back({ 170, "Boots", 0, 10 });				// Player's Boots (price, name, quantity, bonus hitpoints)
	playerStore.itemList.push_back({ 200, "Gauntlets", 0, 15 });			// Player's Gauntlets (price, name, quantity, bonus hitpoints)
	playerStore.itemList.push_back({ 600, "Pants", 0, 30 });				// Player's Pants (price, name, quantity, bonus hitpoints)
	playerStore.itemList.push_back({ 550, "Shield", 0, 15 });				// Player's Shield (price, name, quantity, bonus hitpoints)
	playerStore.itemList.push_back({ 1000, "Chestplate", 0, 50 });			// Player's Chestplate (price, name, quantity, bonus hitpoints)	
}

void Player::initialisePlayerBody()
{

	// set all body parts to have no items
	lh.item = Empty;
	rh.item = Empty;
	head.item = Empty;
	arms.item = Empty;
	legs.item = Empty;
	feet.item = Empty;
	body.item = Empty;

	lh =	playerBody.BodyList[0] = { "Left Hand", lh.item, };		// Player's Left Hand (item, name)
	rh =	playerBody.BodyList[1] = { "Right Hand", rh.item };		// Player's Right Hand (item, name)
	head =	playerBody.BodyList[2] = { "Head", head.item };			// Player's Head (item, name)
	arms =	playerBody.BodyList[3] = { "Arms", arms.item };			// Player's Arms (item, name)
	legs =	playerBody.BodyList[4] = { "Legs", legs.item };			// Player's Legs (item, name)
	feet =	playerBody.BodyList[5] = { "Feet", feet.item };			// Player's Feet (item, name)
	body =	playerBody.BodyList[6] = { "Body", body.item };			// Player's Body (item, name)
}


void Player::setName(Player& character)
{
	string decision;
	cout << endl;
	cout << "What is your name? ";
	cin >> decision;			// user input to decide what name they want
	character.name = decision;	// sets character name to user input

	cout << "Your name is " << character.name << "." << endl;
	cout << endl;
}

string Player::getName()
{
	return string(name);	// returns character name
}
