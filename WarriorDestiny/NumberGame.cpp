#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <random>

using namespace std;

void Game::NumberGame()
{
	int min = 1;	// Default value of minimum set to 1
	int max = 100;	// Default value of maximum set to 100
	int count = 1;	// count is set to 1 (if AI guesses correctly first turn, count is already set to 1 and no increment is made) 

	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution<> distr(min, max); // define the range
	int guess = distr(eng);	// Sets guess value to a random number between the maximum and minimum of the range

	cout << "~~~ Number Guess Game ~~~" << endl; cout << endl;

	cout << "Strange man: I will be guessing a number that you choose from my card pile. " << endl;
	cout << "Strange man: The cards range between 1 to 100." << endl;
	cout << "Strange man: Be warned, if I catch you cheating. I will keep your gold." << endl; cout << endl;
	cout << "5 gold has been removed from your inventory." << endl; cout << endl;
	character.playerStore.gold -= 5;	// subtracts 5 from the user gold

	bool invalidInput = true;
	int number;

	// Loops through until a valid response is given by the user (valid input: 1 - 100)
	while (invalidInput == true)
	{
		cout << "Strange man: Now pick a number from the card pile and do not tell me what number it is!" << endl; cout << endl;
		cout << "Your number: ";

		cin >> number; cout << endl;	// user input number choice for game

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}

		if (number < 1 || number > 100)	// user chooses a invalid number
		{
			cout << "Invalid Input Entered." << endl;	// inform user
			cout << "You must enter a number between 1 and 100." << endl;
		}
		else	// user chooses a valid number
		{
			invalidInput = false;	// User input is valid, exit loop
		}
	}
	FirstGuessNumberGame(min, max, guess, count, number);	// call FirstGuessNumberGame function
}

void Game::NextGuessNumberGame(int& max, int& min, int& guess, int& count, int& number)
{
	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution<> distr(min, max); // define the range
	guess = distr(eng);	// Sets guess value to a random number between the maximum and minimum of the range 

	char guessComparison;
	bool validInput = false;

	// Loops through until a valid response is given by the user (valid input: 'H' or 'h', 'L' or 'l' and 'E' or 'e')
	while (validInput == false)
	{
		cout << "Is your number higher or lower than " << guess << "?" << endl; cout << endl;
		cout << "Enter 'H' if your number is higher." << endl;
		cout << "Enter 'L' if your number is lower." << endl;
		cout << "Enter 'E' if your number is equal." << endl;
		cin >> guessComparison; cout << endl;	// Takes in a char input from the user to determine whether the user's number is higher, lower or equal to the guess
		cout << endl;

		if (cin.fail())		// If the user input is invalid (e.g. a int instead of a char)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}

		switch (guessComparison)
		{
		case 'H':	// if user claims their number is higher than the guess
		case 'h':
			if (guess > number)	// if the user's number is lower than guess
			{
				cout << "A small child runs past you and sees you lie to the man." << endl;
				cout << "Child: That's not true, their number is " << number << "!" << endl;
				cout << "The man squints his eyes at you." << endl;
				cout << "Strange man: I told you if I catch you cheating I will keep your gold." << endl; cout << endl;
				NumberGameAgain();	// call NumberGameAgain function 
			}
			min = (guess + 1);	// As the user states their number is higher than guess, it sets the minimum value to the guess value (new range is between guess and maximum)
			count++;	// The guess counter is incremented as a new guess was made
			NextGuessNumberGame(max, min, guess, count, number);	// Returns to the beginning of this function to start another guess
			validInput = true;	// The user has given valid input, exits loop
			break;
		case 'L':	// if user claims their number is lower than the guess
		case 'l':
			if (guess < number)	// if the user's number is higher than guess
			{
				cout << "A gush of wind blows your card out of your hands." << endl;
				cout << "The man looks at your card and catches you lying to him. " << endl;
				cout << "The man frowns at you." << endl;
				cout << "Strange man: I told you if I catch you cheating I will keep your gold." << endl; cout << endl;
				NumberGameAgain();	// call NumberGameAgain function 
			}
			max = (guess - 1);	// As the user states their number is lower than guess, it sets the maximum value to the guess value (new range is between minimum and guess)
			count++;	// The guess counter is incremented as a new guess was made
			NextGuessNumberGame(max, min, guess, count, number);	// Returns to the beginning of this function to start another guess
			validInput = true;	// The user has given valid input, exits loop
			break;
		case 'E':	// if user claims their number is equal to the guess
		case 'e':
			if (guess != number) // if user number is not equal to guess
			{ 
				cout << "Show me your card..." << endl;
				cout << "You have lied! You do not have that number!" << endl;
				cout << "Your gold is now mine." << endl; cout << endl;
				ManStall();	// call ManStall function
				validInput = true;	// User input is valid, exit loop
				break;
			}
			else if (guess == number) // if user number is equal to guess
			{
				cout << "The man guessed your number in " << count << " guesses." << endl; cout << endl;
				if (count > 7)	// the number of guesses is higher than 7
				{
					cout << "The creepy man grumbles to himself and hands over 10 gold." << endl; cout << endl;
					character.playerStore.gold += 10;	// add 10 to user gold
				}
				else
				{
					cout << "The man grins.." << endl;
					cout << "Strange man: I won, bad luck kid." << endl; cout << endl;
				}
				NumberGameAgain();	// call NumberGameAgain function 
			}
		}
	}
}

void Game::FirstGuessNumberGame(int& min, int& max, int& guess, int& count, int& number)
{
	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution<> distr(min, max); // define the range
	guess = distr(eng);	// Sets guess value to a random number between the maximum and minimum of the range
	
	char guessComparison;
	bool validInput = false;

	// Loops through until a valid response is given by the user (valid input: 'H' or 'h', 'L' or 'l' and 'E' or 'e')
	while (validInput == false)
	{
		cout << "Is your number higher or lower than " << guess << "?" << endl; cout << endl;
		cout << "Enter 'H' if your number is higher." << endl;
		cout << "Enter 'L' if your number is lower." << endl;
		cout << "Enter 'E' if your number is equal." << endl;
		cin >> guessComparison; cout << endl;
		cout << endl;

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of a int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}

		switch (guessComparison)
		{
		case 'H':	// if user claims their number is higher than the guess
		case 'h':
			if (guess > number)	// if the user's number is lower than guess
			{
				cout << "A group of people who had been watching you, notice your lie." << endl;
				cout << "Townsman: What are you doing? Your number is " << number << "." << endl;
				cout << "The strange man overhears the townsman's comment." << endl;
				cout << "Strange man: I told you if I catch you cheating I will keep your gold." << endl; cout << endl;
				NumberGameAgain();	// call NumberGameAgain function 
			}
			min = (guess + 1);	// As the user states their number is higher than guess, it sets the minimum value to the guess value (new range is between guess and maximum)
			count++;	// The guess counter is incremented as a new guess was made
			NextGuessNumberGame(max, min, guess, count, number);
			validInput = true;
			break;
		case 'L':	// if user claims their number is lower than the guess
		case 'l':
			if (guess < number)	// if the user's number is higher than guess
			{
				cout << "You think you have fooled the strange man so you let out a chuckle." << endl;
				cout << "The man is suspicious." << endl;
				cout << "Strange man: Let me see your card, and if you are telling the truth, I will return your money." << endl;
				cout << "You show the card to the man." << endl;
				cout << "Strange man: I told you if I catch you cheating I will keep your gold." << endl; cout << endl;
				NumberGameAgain();	// call NumberGameAgain function 
			}
			max = (guess - 1);	// As the user states their number is lower than guess, it sets the maximum value to the guess value (new range is between minimum and guess)
			count++;	// The guess counter is incremented as a new guess was made
			NextGuessNumberGame(max, min, guess, count, number);	// call NextGuessNumberGame function
			validInput = true;	// The user has given valid input, exits loop
			break;
		case 'E':	// if user claims their number is equal to the guess
		case 'e':
			if (guess != number) // if user number is not equal to guess
			{
				cout << "Show me your card..." << endl;
				cout << "You have lied! You do not have that number!" << endl;
				cout << "Your gold is now mine." << endl; cout << endl;
				ManStall();	// call ManStall function
				validInput = true;	// User input is valid, exit loop
				break;
			}
			else if (guess == number) // if user number is equal to guess
			{
				cout << "The man guessed your number in " << count << " guesses." << endl;
				bool anotherRound = false;

				if (count > 7)	// the number of guesses is higher than 7
				{
					cout << "The creepy man grumbles to himself and hands over 10 gold." << endl; cout << endl;
					character.playerStore.gold += 10;	// add 10 to user gold
				}
				else
				{
					cout << "The man grins.." << endl;
					cout << "Strange man: I won, bad luck kid." << endl; cout << endl;
				}
				NumberGameAgain();	// call NumberGameAgain function 
			}
		}
	}
}

void Game::NumberGameAgain()
{
	bool anotherRound = false;
	int playAgain;

	// Loops through until a valid response is given by the user (valid input: 1 or 2)
	while (anotherRound == false)
	{
		cout << "Would you like to play again?" << endl;
		cout << "1. Yes." << endl;
		cout << "2. No." << endl;
		cin >> playAgain; cout << endl;	// Takes in user input to decide whether or not they want to play the game again
		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}
		if (playAgain == 1)	// If the player wishes to play again
		{
			NumberGame();	// Returns to the NumberGame function 
			anotherRound = true;	// The user has given valid input, exits loop
		}
		else if (playAgain == 2) // If the player does not wish to play again
		{
			Markets();	// Exits from NumberGame back to Markets function
			anotherRound = true;	// The user has given valid input, exits loop
		}
		else	// If input is invalid, inform the user
		{
			cout << "Invalid Input Entered." << endl;
		}
	}
}