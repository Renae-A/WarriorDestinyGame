#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <random>

using namespace std;

void Game::TicTacToe()
{
	cout << "~~~ Tic Tac Toe Game ~~~" << endl; cout << endl;

	cout << "Boy 1: Let me just draw up the boxes for a second. " << endl;
	cout << "Boy 1: Okay, I will let you go first." << endl;
	cout << "Boy 1: Choose an empty box to draw into." << endl; cout << endl;

	char boxes[3][3];

	int row, col;
	char empty = '-'; // the symbol - placed as elements

	for (row = 0; row < 3; row++) {			//initialises rows
		for (col = 0; col < 3; col++) {		//initialises columns
			boxes[row][col] = empty;		// adds - to each element
			std::cout << boxes[row][col];	// prints out each element 
		}
		// new line after row
		cout << endl;
	}
	PlayerShotTicTacToe(row, col, boxes);	// calls PlayerShotTicTacToe
}

void Game::PlayerShotTicTacToe(int & row, int & col, char boxes[3][3])
{
	int rowChoice;
	int colChoice;

	// loops through while all elements are '-'
	while (boxes[1][1] == '-' ||
		boxes[1][2] == '-' ||
		boxes[1][3] == '-' ||
		boxes[2][1] == '-' ||
		boxes[2][2] == '-' ||
		boxes[2][3] == '-' ||
		boxes[3][1] == '-' ||
		boxes[3][1] == '-' ||
		boxes[3][3] == '-')		
	{
		cout << "What row would you like to place your 'O'? (1, 2, or 3)" << endl;
		cin >> rowChoice; cout << endl;	// user input to decide what row they want their 'O' in
		cout << "What column would you like to place your 'O'? (1, 2, or 3)" << endl;
		cin >> colChoice; cout << endl;	// user input to decide what column they want their 'O' in

		rowChoice -= 1;	// rowChoice is 1 higher than the corresponding element so 1 is subtracted
		colChoice -= 1;	// colChoice is 1 higher than the corresponding element so 1 is subtracted

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
			cout << "Invalid Input Entered." << endl;
		}
		if (boxes[rowChoice][colChoice] != '-')	// if the user chooses a box that is not empty
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
			cout << "Boy 1: You can't put it in that box, there is already something drawn there!" << endl;
		}
		else	// if the user chooses a valid box
		{
			boxes[rowChoice][colChoice] = 'O';	// place 'O' in the element of user choice

			for (row = 0; row < 3; row++)  //initialises rows
			{
				for (col = 0; col < 3; col++) { //initialises columns
					cout << boxes[row][col]; // prints out each element 
				}
				// new line after row
				cout << endl;
			}
			cout << endl; cout << endl;
			TicTacToeGameOver(row, col, boxes);	// call TicTacToeGameOver function (to see if the game is finished)
			BoyShotTicTacToe(row, col, boxes);	// call BoyShotTicTacToe function
		}
	}
}

void Game::BoyShotTicTacToe(int & row, int & col, char boxes[3][3])
{
	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution<> distr(0, 2); // define the range
	int boyRow = distr(eng);	// Sets boy's row choice to a random number between the 0 and 2 (corresponding to the box's row elements)
	int boyCol = distr(eng);	// Sets boy's column choice to a random number between the 0 and 2 (corresponding to the box's column elements)

	if (boxes[boyRow][boyCol] != '-')	// if the boy chooses a box that is not empty
	{
		BoyShotTicTacToe(row, col, boxes);	// call BoyShotTicTacToe function to try again
	}
	else	// if the boy chooses a valid box
	{
		cout << "Boy 2's Turn:" << endl; cout << endl;
		boxes[boyRow][boyCol] = 'X';	// place 'X' in the element of boy choice

		for (row = 0; row < 3; row++)  //initialises rows
		{
			for (col = 0; col < 3; col++) { //initialises columns
				std::cout << boxes[row][col]; // prints out each element 
			}
			// new line after row
			cout << endl;
		}
		cout << endl; cout << endl;
		TicTacToeGameOver(row, col, boxes);		// call TicTacToeGameOver function (to see if the game is finished)
		PlayerShotTicTacToe(row, col, boxes);	// call PlayerShotTicTacToe function
	}
}

void Game::TicTacToeGameOver(int & row, int & col, char boxes[3][3])
{
	// If user wins

	if (boxes[0][0] == 'O' && boxes[0][1] == 'O' && boxes[0][2] == 'O')	// if all top row elements are 'O'
	{
		cout << "Boy 1: You win." << endl;
		cout << "Boy 1: Here's your gold." << endl; cout << endl;
		cout << "The boy disappointedly passes you 5 gold." << endl; cout << endl;
		character.playerStore.gold += 5;	// add 5 to user gold
		TicTacToeAnotherGame();				// call TicTacToeAnotherGame function
	}
	if (boxes[1][0] == 'O' && boxes[1][1] == 'O' && boxes[1][2] == 'O')	// if all middle row elements are 'O'
	{
		cout << "Boy 1: You win." << endl;
		cout << "Boy 1: Here's your gold." << endl; cout << endl;
		cout << "The boy disappointedly passes you 5 gold." << endl; cout << endl;
		character.playerStore.gold += 5;	// add 5 to user gold
		TicTacToeAnotherGame();				// call TicTacToeAnotherGame function
	}
	else if (boxes[2][0] == 'O' && boxes[2][1] == 'O' && boxes[2][2] == 'O')	// if all bottom row elements are 'O'
	{
		cout << "Boy 1: You win." << endl;
		cout << "Boy 1: Here's your gold." << endl; cout << endl;
		cout << "The boy disappointedly passes you 5 gold." << endl; cout << endl;
		character.playerStore.gold += 5;	// add 5 to user gold
		TicTacToeAnotherGame();				// call TicTacToeAnotherGame function
	}
	else if (boxes[0][0] == 'O' && boxes[1][0] == 'O' && boxes[2][0] == 'O')	// if all first column elements are 'O'
	{
		cout << "Boy 1: You win." << endl;
		cout << "Boy 1: Here's your gold." << endl; cout << endl;
		cout << "The boy disappointedly passes you 5 gold." << endl; cout << endl;
		character.playerStore.gold += 5;	// add 5 to user gold
		TicTacToeAnotherGame();				// call TicTacToeAnotherGame function
	}
	else if (boxes[0][1] == 'O' && boxes[1][1] == 'O' && boxes[2][1] == 'O')	// if all second column elements are 'O'
	{
		cout << "Boy 1: You win." << endl;
		cout << "Boy 1: Here's your gold." << endl; cout << endl;
		cout << "The boy disappointedly passes you 5 gold." << endl; cout << endl;
		character.playerStore.gold += 5;	// add 5 to user gold
		TicTacToeAnotherGame();				// call TicTacToeAnotherGame function
	}
	else if (boxes[0][2] == 'O' && boxes[1][2] == 'O' && boxes[2][2] == 'O')	// if all third column elements are 'O'
	{
		cout << "Boy 1: You win." << endl;
		cout << "Boy 1: Here's your gold." << endl; cout << endl;
		cout << "The boy disappointedly passes you 5 gold." << endl; cout << endl;
		character.playerStore.gold += 5;	// add 5 to user gold
		TicTacToeAnotherGame();				// call TicTacToeAnotherGame function
	}
	else if (boxes[0][0] == 'O' && boxes[1][1] == 'O' && boxes[2][2] == 'O')	// if bottom right, middle and top left elements are 'O'
	{
		cout << "Boy 1: You win." << endl;
		cout << "Boy 1: Here's your gold." << endl; cout << endl;
		cout << "The boy disappointedly passes you 5 gold." << endl; cout << endl;
		character.playerStore.gold += 5;	// add 5 to user gold
		TicTacToeAnotherGame();				// call TicTacToeAnotherGame function
	}
	else if (boxes[0][2] == 'O' && boxes[1][1] == 'O' && boxes[2][0] == 'O')	// if bottom left, middle and top right elements are 'O'
	{
		cout << "Boy 1: You win." << endl;
		cout << "Boy 1: Here's your gold." << endl; cout << endl;
		cout << "The boy disappointedly passes you 5 gold." << endl; cout << endl;
		character.playerStore.gold += 5;	// add 5 to user gold
		TicTacToeAnotherGame();				// call TicTacToeAnotherGame function
	}

	// If user loses

	else if (boxes[0][0] == 'X' && boxes[0][1] == 'X' && boxes[0][2] == 'X')	// if all top row elements are 'X'
	{
		cout << "Boy 1: I win!" << endl;
		cout << "Boy 1: I will take my gold now, thank you." << endl; cout << endl;
		cout << "You give the boy 5 gold." << endl; cout << endl;
		character.playerStore.gold -= 5;	// subtracts 5 from user gold
		TicTacToeAnotherGame();				// call TicTacToeAnotherGame function
	}
	else if (boxes[1][0] == 'X' && boxes[1][1] == 'X' && boxes[1][2] == 'X')	// if all middle row elements are 'X'
	{
		cout << "Boy 1: I win!" << endl;
		cout << "Boy 1: I will take my gold now, thank you." << endl; cout << endl;
		cout << "You give the boy 5 gold." << endl; cout << endl;
		character.playerStore.gold -= 5;	// subtracts 5 from user gold
		TicTacToeAnotherGame();				// call TicTacToeAnotherGame function
	}
	else if (boxes[2][0] == 'X' && boxes[2][1] == 'X' && boxes[2][2] == 'X')	// if all bottom row elements are 'X'
	{
		cout << "Boy 1: I win!" << endl;
		cout << "Boy 1: I will take my gold now, thank you." << endl; cout << endl;
		cout << "You give the boy 5 gold." << endl; cout << endl;
		character.playerStore.gold -= 5;	// subtracts 5 from user gold
		TicTacToeAnotherGame();				// call TicTacToeAnotherGame function
	}
	else if (boxes[0][0] == 'X' && boxes[1][0] == 'X' && boxes[2][0] == 'X')	// if all first column elements are 'X'
	{
		cout << "Boy 1: I win!" << endl;
		cout << "Boy 1: I will take my gold now, thank you." << endl; cout << endl;
		cout << "You give the boy 5 gold." << endl; cout << endl;
		character.playerStore.gold -= 5;	// subtracts 5 from user gold
		TicTacToeAnotherGame();				// call TicTacToeAnotherGame function
	}
	else if (boxes[0][1] == 'X' && boxes[1][1] == 'X' && boxes[2][1] == 'X')	// if all second column elements are 'X'
	{
		cout << "Boy 1: I win!" << endl;
		cout << "Boy 1: I will take my gold now, thank you." << endl; cout << endl;
		cout << "You give the boy 5 gold." << endl; cout << endl;
		character.playerStore.gold -= 5;	// subtracts 5 from user gold
		TicTacToeAnotherGame();				// call TicTacToeAnotherGame function
	}
	else if (boxes[0][2] == 'X' && boxes[1][2] == 'X' && boxes[2][2] == 'X')	// if all third column elements are 'X'
	{
		cout << "Boy 1: I win!" << endl;
		cout << "Boy 1: I will take my gold now, thank you." << endl; cout << endl;
		cout << "You give the boy 5 gold." << endl; cout << endl;
		character.playerStore.gold -= 5;	// subtracts 5 from user gold
		TicTacToeAnotherGame();				// call TicTacToeAnotherGame function
	}
	else if (boxes[0][0] == 'X' && boxes[1][1] == 'X' && boxes[2][2] == 'X')	// if bottom right, middle and top left elements are 'X'
	{
		cout << "Boy 1: I win!" << endl;
		cout << "Boy 1: I will take my gold now, thank you." << endl; cout << endl;
		cout << "You give the boy 5 gold." << endl; cout << endl;
		character.playerStore.gold -= 5;	// subtracts 5 from user gold
		TicTacToeAnotherGame();				// call TicTacToeAnotherGame function
	}
	else if (boxes[0][2] == 'X' && boxes[1][1] == 'X' && boxes[2][0] == 'X')	// if bottom left, middle and top right elements are 'X'
	{
		cout << "Boy 1: I win!" << endl;
		cout << "Boy 1: I will take my gold now, thank you." << endl; cout << endl;
		cout << "You give the boy 5 gold." << endl; cout << endl;
		character.playerStore.gold -= 5;	// subtracts 5 from user gold
		TicTacToeAnotherGame();				// call TicTacToeAnotherGame function
	}
}

void Game::TicTacToeAnotherGame()
{
	cout << "Boy 1: Would you like to play again?" << endl; cout << endl;
	cout << "1. Yes, play again." << endl;
	cout << "2. No, return to the choice between both games." << endl;
	cout << "3. No, return to Markets." << endl; cout << endl;
	int decision;

	bool validInput = false;
	// Loops through until a valid response is given by the user (valid input: 1, and 2)
	while (validInput == false)
	{
		cout << "Enter a number: ";
		cin >> decision; cout << endl;	// User input to decide if they want to play
		cout << endl;

		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}

		switch (decision)
		{
		case 1:					// If user wants to play again
			TicTacToe();		// Calls TicTacToe function
			validInput = true;	// User input is valid, exit loop
			break;
		case 2:					// If user wants to go back to boys' stall
			BoyStall();			// Calls BoyStall function
			validInput = true;	// User input is valid, exit loop
			break;
		case 3:					// If user wants to go back to markets
			Markets();			// Calls Markets function
			validInput = true;	// User input is valid, exit loop
			break;
		default:				// If input is invalid, inform the user
			cout << "Invalid Input Entered." << endl;
		}
	}
}

