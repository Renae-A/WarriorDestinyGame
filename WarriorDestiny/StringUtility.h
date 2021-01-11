#pragma once
#include <iostream>
#include <string>

using namespace std;

void WriteString(ostream& oStream, const string& text);	// WriteString takes in an ostream and string of text to save to the save file
void ReadString(istream& iStream, string& text);		// ReadString takes in an istream and string of text to read from the save file
