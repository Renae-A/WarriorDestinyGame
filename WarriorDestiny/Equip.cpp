#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Item.h"
#include <iostream>

using namespace std;

void Game::Equip()
{
	bool decisionMade = false;
	int decision;

	// Loops through until a valid response is given by the user (valid input: 0 - 12)
	while (decisionMade == false)
	{
		cout << "Choose a number from 1 - 12 to match listed item to equip. " << endl;
		cout << "Enter 0 to go back. " << endl;
		cin >> decision; cout << endl;	// user input of item they want to equip
		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}
		else if (decision == 0)		// if user wants to go back
		{
			ManageInventory();		// call ManageInventory function to go back
			decisionMade = true;	// The user has given valid input, exits loop
		}
		else if (decision >= 1 && decision <= 12)	// if the user chooses a valid item
		{
			decisionMade = true;	// The user has given valid input, exits loop
		}
		else	// The user has given invalid input
		{
			cout << "You did not enter a valid response. " << endl; cout << endl;	// inform the user that the input was invalid (loop again)
		}
	}

	Item& playerItem = character.playerStore.itemList[decision - 1];	// playerItem will be easier to use in code (is the user choice of item in the player inventory)

	switch (decision)
	{
	case 1:																				// if Item is one handed weapon (Sword)
	case 2:																				// if Item is one handed weapon (Whip)
	case 3:																				// if Item is one handed weapon (Hammer)
	case 4:																				// if Item is one handed weapon (Axe)
		if (playerItem.quantity == 0)															// if user does not have playerItem
		{
			cout << "You do not own " << playerItem.name << "." << endl;						// inform user
			Equip();																			// call Equip function
		}
		else if (character.lh.item.name != "Nothing" && character.rh.item.name != "Nothing")	// if the both hands of the user have Items equipped
		{
			cout << "You need to unequip your item from one of your hands first." << endl;		// inform user
			Equip();																			// call Equip function
		}
		else if (character.lh.item.name == "Nothing" && character.rh.item.name != "Nothing")	// if left hand is empty and right hand has Item equipped
		{
			if (playerItem.quantity == 1 && playerItem.name == character.rh.item.name)			// if the user has 1 of the Item they are trying to equip but already have it equipped
			{
				cout << "You already have " << playerItem.name << " equipped." << endl;			// inform user
				cout << "You do not own a second " << playerItem.name << "." << endl;
				Equip();																		// call Equip function
			}
			else																				// user has made a valid decision
			{
				cout << "You have equipped " << playerItem.name << " to left hand." << endl;	// inform user
				character.lh.item = playerItem;
				character.playerBody.BodyList[0].item = playerItem;								// the left hand now has the playerItem equipped
				character.increaseAttack(playerItem);											// increase the attack of user by the amount of bonus
				Equip();																		// call Equip function
			}
		}
		else if (character.lh.item.name != "Nothing" && character.rh.item.name == "Nothing")	// if right hand is empty and left hand has Item equipped
		{
			if (playerItem.quantity == 1 && playerItem.name == character.lh.item.name)			// if the user has 1 of the Item they are trying to equip but already have it equipped
			{
				cout << "You already have " << playerItem.name << " equipped." << endl;			// inform user
				cout << "You do not own a second " << playerItem.name << "." << endl;
				Equip();																		// call Equip function
			}
			else																				// user has made a valid decision
			{
				cout << "You have equipped " << playerItem.name << " to right hand." << endl;	// inform user
				character.rh.item = playerItem;
				character.playerBody.BodyList[1].item = playerItem;								// the right hand now has the playerItem equipped
				character.increaseAttack(playerItem);											// increase the attack of user by the amount of bonus
				Equip();																		// call Equip function
			}
		}
		else if (character.lh.item.name == "Nothing" && character.rh.item.name == "Nothing")	// if both hands are empty
		{
			bool decisionMade1 = false;
			int decision;

			// Loops through until a valid response is given by the user (valid input: 1 and 2)
			while (decisionMade1 == false)
			{
				cout << "Which hand would you like to equip " << playerItem.name << "?" << endl;
				cout << "1. Left Hand." << endl;
				cout << "2. Right Hand." << endl;
				cin >> decision; cout << endl;	// user input to decide which hand to equip playerItem
				if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
				{
					cin.clear();	// Clear the user input 
					cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
				}
				else if (decision == 1)
				{
					cout << "You have equipped " << playerItem.name << " to left hand." << endl;	// inform user
					character.lh.item = playerItem;		
					character.playerBody.BodyList[0].item = playerItem;								// the left hand now has the playerItem equipped
					character.increaseAttack(playerItem);											// increase the attack of user by the amount of bonus
					Equip();																		// call Equip function
					decisionMade1 = true;															// The user has given valid input, exits loop
				}
				else if (decision == 2)
				{
					cout << "You have equipped " << playerItem.name << " to right hand." << endl;	// inform user
					character.rh.item = playerItem;	
					character.playerBody.BodyList[1].item = playerItem;								// the right hand now has the playerItem equipped
					character.increaseAttack(playerItem);											// increase the attack of user by the amount of bonus
					Equip();																		// call Equip function
					decisionMade1 = true;															// The user has given valid input, exits loop
				}
				else																				// user has made a valid decision
				{
					cout << "You did not enter a valid response. " << endl; cout << endl;			// inform user
				}
			}
		}
		break;
	case 5:																					// if Item is two handed weapon (TwoHandedSword)
	case 6:																					// if Item is two handed weapon (BowAndArrows)
		if (playerItem.quantity == 0)																// if user does not have playerItem
		{
			cout << "You do not own " << playerItem.name << "." << endl;							// inform user
			Equip();																				// call Equip function
		}
		else if (character.lh.item.name != "Nothing" && character.rh.item.name != "Nothing")		// if the both hands of the user have Items equipped
		{
			cout << "You need to unequip your item from both of your hands first." << endl;			// inform user
			Equip();																				// call Equip function
		}
		else if (character.lh.item.name == "Nothing" && character.rh.item.name != "Nothing")		// if left hand is empty and right hand has Item equipped
		{
			cout << "You need to unequip your item from your right hand first." << endl;			// inform user
			Equip();																				// call Equip function
		}
		else if (character.lh.item.name != "Nothing" && character.rh.item.name == "Nothing")		// if right hand is empty and left hand has Item equipped
		{
			cout << "You need to unequip your item from your left hand first." << endl;				// inform user
			Equip();																				// call Equip function
		}
		else if (character.lh.item.name == "Nothing" && character.rh.item.name == "Nothing")		// if both hands are empty
		{
			cout << "You have equipped " << playerItem.name << " to both hands." << endl;			// inform user
			character.lh.item = playerItem;
			character.playerBody.BodyList[0].item = playerItem;										// the left hand now has the playerItem equipped
			character.rh.item = playerItem;															
			character.playerBody.BodyList[1].item = playerItem;										// the right hand now has the playerItem equipped
			character.increaseAttack(playerItem);													// increase the attack of user by the amount of bonus
			Equip();																				// call Equip function
		}
		break;
	case 7:																					// if Item is head armor (Helmet)
		if (playerItem.quantity == 0)																// if user does not have playerItem
		{
			cout << "You do not own " << playerItem.name << "." << endl;							// inform user
			Equip();																				// call Equip function
		}
		else if (character.head.item.name != "Nothing")												// if user head already has Item equipped
		{
			cout << "You need to unequip your item from your head first." << endl;					// inform user
			Equip();																				// call Equip function
		}
		else if (character.head.item.name == "Nothing")												// if there is no Item equipped on head
		{
			cout << "You have equipped " << playerItem.name << " to head." << endl;					// inform user
			character.head.item = playerItem;														
			character.playerBody.BodyList[2].item = playerItem;										// the head now has the playerItem equipped
			character.increaseHealth(playerItem);													// increase the maximum health of user by the amount of bonus
			Equip();																				// call Equip function
		}																						
		break;
	case 8:																					// if Item is feet armor (Boots)
		if (playerItem.quantity == 0)																// if user does not have playerItem
		{
			cout << "You do not own " << playerItem.name << "." << endl;							// inform user
			Equip();																				// call Equip function
		}
		else if (character.feet.item.name != "Nothing")												// if user feet already has Item equipped
		{
			cout << "You need to unequip your item from your feet first." << endl;					// inform user
			Equip();																				// call Equip function
		}
		else if (character.feet.item.name == "Nothing")												// if there is no Item equipped on feet
		{
			cout << "You have equipped " << playerItem.name << " to feet." << endl;					// inform user
			character.head.item = playerItem;														
			character.playerBody.BodyList[5].item = playerItem;										// the feet now have the playerItem equipped
			character.increaseHealth(playerItem);													// increase the maximum health of user by the amount of bonus
			Equip();																				// call Equip function
		}
		break;
	case 9:																					// if Item is arm armor (Gauntlets)
		if (playerItem.quantity == 0)																// if user does not have playerItem
		{
			cout << "You do not own " << playerItem.name << "." << endl;							// inform user
			Equip();																				// call Equip function
		}
		else if (character.arms.item.name != "Nothing")												// if user arms already has Item equipped
		{
			cout << "You need to unequip your item from your arms first." << endl;					// inform user
			Equip();																				// call Equip function
		}
		else if (character.arms.item.name == "Nothing")												// if there is no Item equipped on arms
		{
			cout << "You have equipped " << playerItem.name << " to arms." << endl;					// inform user
			character.arms.item = playerItem;
			character.playerBody.BodyList[3].item = playerItem;										// the arms now have the playerItem equipped
			character.increaseHealth(playerItem);													// increase the maximum health of user by the amount of bonus
			Equip();																				// call Equip function
		}
		break;
	case 10:																				// if Item is leg armor (Pants)
		if (playerItem.quantity == 0)																// if user does not have playerItem
		{
			cout << "You do not own " << playerItem.name << "." << endl;							// inform user
			Equip();																				// call Equip function
		}
		else if (character.legs.item.name != "Nothing")												// if user legs already has Item equipped
		{
			cout << "You need to unequip your item from your legs first." << endl;					// inform user
			Equip();																				// call Equip function
		}
		else if (character.legs.item.name == "Nothing")												// if there is no Item equipped on feet
		{
			cout << "You have equipped " << playerItem.name << " to legs." << endl;					// inform user
			character.legs.item = playerItem;	
			character.playerBody.BodyList[4].item = playerItem;										// the legs now have the playerItem equipped
			character.increaseHealth(playerItem);													// increase the maximum health of user by the amount of bonus
			Equip();																				// call Equip function
		}
		break;
	case 11:																				// if Item is one handed armor (Shield)
		if (playerItem.quantity == 0)																// if user does not have playerItem
		{
			cout << "You do not own " << playerItem.name << "." << endl;							// inform user
			Equip();																				// call Equip function
		}
		else if (character.lh.item.name != "Nothing" && character.rh.item.name != "Nothing")		// if the both hands of the user have Items equipped
		{
			cout << "You need to unequip your item from one of your hands first." << endl;			// inform user
			Equip();																				// call Equip function
		}
		else if (character.lh.item.name == "Nothing" && character.rh.item.name != "Nothing")
		{
			if (playerItem.quantity == 1 && character.rh.item.name == "Shield")
			{
				cout << "You already have " << playerItem.name << " equipped." << endl;				// inform user
				cout << "You do not own a second " << playerItem.name << "." << endl;
				Equip();																			// call Equip function
			}
			else
			{
				cout << "You have equipped " << playerItem.name << " to left hand." << endl;		// inform user
				character.lh.item = playerItem;	
				character.playerBody.BodyList[0].item = playerItem;									// the left hand now has the playerItem equipped
				character.increaseAttack(playerItem);												// increase the attack of user by the amount of bonus
				Equip();																			// call Equip function
			}
		}
		else if (character.lh.item.name != "Nothing" && character.rh.item.name == "Nothing")
		{
			if (playerItem.quantity == 1 && character.lh.item.name == "Shield")
			{
				cout << "You already have " << playerItem.name << " equipped." << endl;				// inform user
				cout << "You do not own a second " << playerItem.name << "." << endl;
				Equip();																			// call Equip function
			}
			else
			{
				cout << "You have equipped " << playerItem.name << " to right hand." << endl;		// inform user
				character.rh.item = playerItem;		
				character.playerBody.BodyList[1].item = playerItem;									// the right hand now has the playerItem equipped
				character.increaseAttack(playerItem);												// increase the attack of user by the amount of bonus
				Equip();																			// call Equip function
			}
		}
		else if (character.lh.item.name == "Nothing" && character.rh.item.name == "Nothing")
		{
			bool decisionMade1 = false;
			int decision;

			while (decisionMade1 == false)
			{
				cout << "Which hand would you like to equip " << playerItem.name << "?" << endl;
				cout << "1. Left Hand." << endl;
				cout << "2. Right Hand." << endl;
				cin >> decision; cout << endl;
				if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
				{
					cin.clear();	// Clear the user input 
					cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
				}
				else if (decision == 1)
				{
					cout << "You have equipped " << playerItem.name << " to left hand." << endl;	// inform user
					character.lh.item = playerItem;	
					character.playerBody.BodyList[0].item = playerItem;								// the left hand now has the playerItem equipped
					character.increaseHealth(playerItem);											// increase the attack of user by the amount of bonus
					Equip();																		// call Equip function
					decisionMade1 = true;
				}
				else if (decision == 2)
				{
					cout << "You have equipped " << playerItem.name << " to right hand." << endl;	// inform user
					character.rh.item = playerItem;
					character.playerBody.BodyList[1].item = playerItem;								// the right hand now has the playerItem equipped
					character.increaseHealth(playerItem);											// increase the attack of user by the amount of bonus
					Equip();																		// call Equip function
					decisionMade1 = true;
				}
				else																				// user has made an invalid decision
				{
					cout << "You did not enter a valid response. " << endl; cout << endl;			// inform user
				}
			}
		}
	case 12:																				// if Item is body armor (Chestplate)
		if (playerItem.quantity == 0)																// if user does not have playerItem
		{
			cout << "You do not own " << playerItem.name << "." << endl;							// inform user
			Equip();																				// call Equip function
		}
		else if (character.body.item.name != "Nothing")												// if user body already has Item equipped
		{
			cout << "You need to unequip your item from your body first." << endl;					// inform user
			Equip();																				// call Equip function
		}
		else if (character.body.item.name == "Nothing")												// if user body already has Item equipped
		{
			cout << "You have equipped " << playerItem.name << " to body." << endl;					// inform user
			character.body.item = playerItem;	
			character.playerBody.BodyList[6].item = playerItem;										// the body now has the playerItem equipped
			character.increaseHealth(playerItem);													// increase the maximum health of user by the amount of bonus
			Equip();																				// call Equip function
		}
		break;
	default:																				
		cout << "You did not enter a valid response. " << endl; cout << endl;						// inform user
		Equip();																					// call Equip function
		break;
	}
}