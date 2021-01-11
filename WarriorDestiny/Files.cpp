#include "stdafx.h"
#include "Files.h"
#include <fstream>
#include <algorithm>


Files::Files()
{
}


Files::~Files()
{
}

bool Files::LoadText(const char * filename)
{

	ifstream file(filename, ios_base::in);

	if (file.good())
	{
		// Keep reading SaveRecord structures and adding them to the vector
		SaveRecord sr;
		while (!file.eof())
		{
			// If a successful read of a save record from the text file,
			// then add it to our vector of saves
			if (sr.ReadFile(file))	// Read the next SaveRecord from file, & if successful then copy to the Saves collection
			{
				Saves.push_back(sr);
			}
		}
		file.close();
		return true;
	}
	return false;
}

bool Files::LoadBinary(const char * filename)
{
	ifstream file(filename, ios_base::in | ios_base::binary);

	if (file.good())
	{
		// Using a range-based for loop.
		SaveRecord sr;
		while (sr.ReadBinary(file))	// Read the next SaveRecord from file, & if successful then copy to the Saves collection
		{
			Saves.push_back(sr);
		}

		file.close();
		return true;
	}
	return false;
}

bool Files::SaveBinary(const char * filename)
{
	ofstream file(filename, ios_base::out | ios_base::binary);

	if (file.good())
	{
		// Using a range-based for loop.
		for (SaveRecord& sr : Saves)
		{
			sr.WriteBinary(file);
		}

		file.close();
		return true;
	}
	return false;
}

bool Files::OverwriteBinary(const char * filename, SaveRecord & data, const unsigned int saveIndex)
{
	// opening file in both "in/out" modes 
	ofstream file(filename, ios_base::in | ios_base::out | ios_base::binary);

	if (file.good())
	{
		// Seek file position to skip bytes. We want enough bytes to skip saveIndex * sizeof(SaveRecord) 
		file.seekp(saveIndex * sizeof(SaveRecord));

		// Then overwrite the record data
		data.WriteBinary(file);

		file.close();
		return true;
	}
	return false;
}

void Files::Print()
{
	unsigned int saveIndex = 0;
	for (auto it = Saves.begin(); it != Saves.end(); it++)
	{
		cout << "--- Save " << (saveIndex++) << endl;
		(*it).Print();
	}
}

SaveRecord * Files::Find(const string & name)
{
	// Use the find_if function in <algorithm> to search for a SaveRecord with the specified callNumber.
	// Create a lambda to compare each SaveRecord.Name against the input callNumber.
	//auto it = find_if(Saves.begin(), Saves.end(), [&](SaveRecord& sr) {return sr.Compare(saveNumber); });
	//if (it != Saves.end())	// If BookRecord is found, then return its address
		//return &(*it);
	//else
		return nullptr;	// No BookRecord found with the specified CallNumber
}

