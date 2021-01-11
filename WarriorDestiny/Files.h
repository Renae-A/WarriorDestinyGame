#include "SaveRecord.h"
#include <vector>
#include <string>
#pragma once

class Files
{
public:
	Files();
	~Files();

	// Load the SaveRecord data from text file into the Saves Collection
	bool						LoadText(const char* filename);
	// Load the SaveRecord data from binary file into the Saves Collection
	bool						LoadBinary(const char* filename);
	// Save the SaveRecord data to binary file
	bool						SaveBinary(const char* filename);
	// Seek/Overwrite a SaveRecord data at a specific location in the binary file
	bool						OverwriteBinary(const char* filename, SaveRecord& data, const unsigned int recordIndex);

	// Print the SaveRecord data to the console
	void						Print();

	// Find a SaveRecord by Name
	// Returns: A valid SaveRecord pointer if found. nullptr otherwise
	SaveRecord*					Find(const string& name);

protected:
	vector<SaveRecord>		Saves;	// The collection of SaveRecord data
};

