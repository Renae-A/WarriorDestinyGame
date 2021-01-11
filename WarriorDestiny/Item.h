#pragma once
#include "StringUtility.h"
#include <string>
#include <vector>

using namespace std;

struct Item
{
	int price;				// price of item
	string name;			// name of item
	int quantity;			// quantity of item
	int bonus;				// extra maxHealth/extra attackValue when equipped

	bool operator < (const Item& other) const;		// comparison operator function to determine if Item is less than other
	bool operator == (const Item& other) const;		// comparison operator function to determine if Item is equal to than other
	bool operator > (const Item& other) const;		// comparison operator function to determine if Item is greater than other	

	void Save(ostream& F);		// function to save item to file
	void Load(istream& F);		// function to load item to game
};

struct Inventory
{
	int gold;					// amount of gold in inventory
	vector<Item> itemList;		// list of items in inventory

	void Save(ostream& F);		// function to save inventory to file
	void Load(istream& F);		// function to load inventory to game
};