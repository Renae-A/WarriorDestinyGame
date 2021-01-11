#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

void WriteString(std::ostream& oStream, const std::string& text)
{
	int textLength = text.size();
	oStream.write((char*)&textLength, sizeof(int));	// Have to write out the length of string first
	oStream.write(text.c_str(), text.size());		// Then write out the characters in the string
}

void ReadString(std::istream& iStream, std::string& text)
{
	int textLength = 0;
	iStream.read((char*)&textLength, sizeof(int));		// Read in the length of the string first
	char* tempArray = new char[textLength + 1];			// Create a temporary buffer + 1 for null-terminator (nb: might be able to do this using string class itself)
	iStream.read(tempArray, textLength);				// Read in the character data into the temporary buffer
	tempArray[textLength] = '\0';						// Place null-terminator at end of string
	text = tempArray;									// Assign the character buffer to the output string
	delete[] tempArray;									// Release the temp buffer
}

