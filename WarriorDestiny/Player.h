#pragma once
#include "stdafx.h"
#include "Item.h"
#include "Body.h"
#include <string>

using namespace std;

class Player 
{
public:
	Player();
	~Player();

	// Game functions
	bool isAlive();							// isAlive() is a function to check if the user character is still alive or not during battle
	virtual void takeDamage(int damage);	// takeDamage(int damage) is a function that will take damage from the user's character health when attacked
	virtual int attack();					// attack() is a function that returns the attack value of the user character

	void setName(Player& character);		// setName(Player& character) takes in the user's character to allow them to set their name to a string of their choice
	string getName();						// getName() returns the user's character name
	int getMaxHealth();						// getMaxHealth() returns the user's character maximum health
	int getAttackValue();					// getAttackValue() returns the user's character attack value

	void increaseAttack(Item& item);		// increaseAttack(Item& item) takes in an item that the user wants to equip and increases the attack value by the bonus of the weapon
	void decreaseAttack(Item& item);		// decreaseAttack(Item& item) takes in an item that the user wants to unequip and decreases the attack value by the bonus of the weapon
	void increaseHealth(Item& item);		// increaseHealth(Item& item) takes in an item that the user wants to equip and increases the maximum health value by the bonus of the armor
	void decreaseHealth(Item& item);		// decreaseHealth(Item& item) takes in an item that the user wants to unequip and decreases the maximum health value by the bonus of the armor
	void levelUp(int healthBonus);			// levelUp(int healthBonus) takes in an integer of bonus health and adds it to the player's maximum health
	void restoreHealth();					// restoreHealth() sets the character health back to the character's maximum health


	UserBody playerBody;					// creates a playerBody for the player
	BodyPart lh, rh, head, arms, legs, feet, body;	// creates each of the body parts to the player
	Item Empty;								// declares an item called Empty (will be used for empty body parts)
	Inventory playerStore;					// creates an inventory for the player

	void Save(ostream& F);					// Save(ostream& F) is a function that gets called when the user wants to save their character to the game file F
	void Load(istream& F);					// Load(istream& F) is a function that gets called when the user wants to load their character from the game file F

protected:
	void initialisePlayerInventory();		// initialisePlayerInventory() is called when a new player is created which will set the inventory to the default conditions
	void initialisePlayerBody();			// initialisePlayerBody() is called when a new player is created which will set the user body to the default conditions

private:

	string name;							// user character name
	int maxHealth;							// user character maximum health
	int health;								// user character current health
	int attackValue;						// user character attack value
};

