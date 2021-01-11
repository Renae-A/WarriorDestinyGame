#include "stdafx.h"
#include "Item.h"


bool Item::operator<(const Item & other) const	// comparison operator function to determine if Item is less than other
{
	return (name < other.name);	
}

bool Item::operator==(const Item & other) const	// comparison operator function to determine if Item is equal to than other
{
	return (name == other.name);
}

bool Item::operator>(const Item & other) const	// comparison operator function to determine if Item is greater than other	
{
	return (name > other.name);
}

void Item::Save(ostream & F)
{
	F.write((char*)&price, sizeof(int));		// save price to file
	WriteString(F, name);						// save name to file
	F.write((char*)&quantity, sizeof(int));		// save quantity to file
	F.write((char*)&bonus, sizeof(int));		// save bonus to file
}

void Item::Load(istream & F)
{
	F.read((char*)&price, sizeof(int));			// load price from file
	ReadString(F, name);						// load name from file
	F.read((char*)&quantity, sizeof(int));		// load quantity from file
	F.read((char*)&bonus, sizeof(int));			// load bonus from file
}

void Inventory::Save(ostream & F)
{
	F.write((char*)&gold, sizeof(int));	// save gold to file
	
	int itemSize = itemList.size();

	// Write the length of the list 
	F.write((char*)&itemSize, sizeof(int));

	// Write the items in the list
	for (int i = 0; i < itemSize; i++)
	{
		itemList[i].Save(F);
	}
}

void Inventory::Load(istream & F)
{
	F.read((char*)&gold, sizeof(int));	// load gold from file

	int itemSize = 0;

	// Read the length of the list 
	F.read((char*)&itemSize, sizeof(int));

	// Read the items in the list
	Item item;
	itemList.clear();
	for (int i = 0; i < itemSize; i++)
	{
		item.Load(F);
		itemList.push_back(item);
	}
}
