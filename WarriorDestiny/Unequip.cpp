#include "stdafx.h"
#include "Game.h"
#include "Item.h"
#include <iostream>

using namespace std;

void Game::Unequip()
{
	Item Empty = { 0, "Nothing", 0, 0 };	// Empty represents nothing being equipped to a body part

	bool decisionMade1 = false;
	int decision;

	// Loops through until a valid response is given by the user (valid input: 0 - 12)
	while (decisionMade1 == false)
	{
		cout << "Choose a number from 1 - 12 to match listed item to unequip. " << endl;
		cout << "Enter 0 to go back. " << endl;	
		cin >> decision; cout << endl;	// user input of item they want to unequip
		if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
		{
			cin.clear();	// Clear the user input 
			cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
		}
		else if (decision == 0)		// if user wants to go back
		{
			ManageInventory();		// call ManageInventory function to go back
			decisionMade1 = true;	// The user has given valid input, exits loop
		}
		else if (decision >= 1 && decision <= 12)	// if the user chooses a valid item
		{
			decisionMade1 = true;	// The user has given valid input, exits loop
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
			Unequip();																			// call Unequip function
		}
		else if (character.lh.item.name != playerItem.name  && character.rh.item.name != playerItem.name)	// if the both hands of the user have different Items than playerItem 
		{
			cout << "You do not have " << playerItem.name << " equipped." << endl;							// inform user
			Unequip();																						// call Unequip function
		}
		else if (character.lh.item.name == playerItem.name && character.rh.item.name != playerItem.name)	// if left hand has the playerItem and right hand does not
		{
			cout << "You have unequipped " << playerItem.name << " from left hand." << endl;				// inform user
			character.lh.item = Empty;	
			character.playerBody.BodyList[0].item = Empty;													// the left hand now has the playerItem unequipped
			character.decreaseAttack(playerItem);															// decrease the attack of user by the amount of bonus
			Unequip();																						// call Unequip function
		}																									
		else if (character.lh.item.name != playerItem.name && character.rh.item.name == playerItem.name)	// if right hand has playerItem and left hand does not
		{																									
			cout << "You have unequipped " << playerItem.name << " from right hand." << endl;				// inform user
			character.rh.item = Empty;		
			character.playerBody.BodyList[1].item = Empty;													// the right hand now has the playerItem unequipped
			character.decreaseAttack(playerItem);															// decrease the attack of user by the amount of bonus
			Unequip();																						// call Unequip function
		}																									
		else if (character.lh.item.name == playerItem.name && character.rh.item.name == playerItem.name)	// if both hands have the playerItem equipped
		{
			bool decisionMade1 = false;																		
			int decision;

			// if the user has 2 of the Item they are trying to unequip but already have both equipped
			while (decisionMade1 == false)
			{																								
				cout << "Which hand would you like to unequip " << playerItem.name << "?" << endl;
				cout << "1. Left Hand." << endl;															
				cout << "2. Right Hand." << endl;
				cout << "3. Both Hands." << endl;															
				cin >> decision; cout << endl;	// user input to decide which hand/s to remove playerItem from
				if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)			
				{																							
					cin.clear();	// Clear the user input 												
					cin.ignore();	// Ignore the user input through this loop (which will allow another att
				}
				else if (decision == 1)																		// if user wants to unequip left hand Item
				{																							
					cout << "You have unequipped " << playerItem.name << " from left hand." << endl;		// inform user
					character.lh.item = Empty;	
					character.playerBody.BodyList[0].item = Empty;											// the left hand now has the playerItem unequipped
					character.decreaseAttack(playerItem);													// decrease the attack of user by the amount of bonus
					Unequip();																				// call Unequip function
					decisionMade1 = true;																	// The user has given valid input, exits loop
				}
				else if (decision == 2)																		// if user wants to unequip right hand Item
				{
					cout << "You have unequipped " << playerItem.name << " from right hand." << endl;		// inform user
					character.rh.item = Empty;	
					character.playerBody.BodyList[1].item = Empty;											// the right hand now has the playerItem unequipped
					character.decreaseAttack(playerItem);													// decrease the attack of user by the amount of bonus
					Unequip();																				// call Unequip function
					decisionMade1 = true;																	// The user has given valid input, exits loop
				}
				else if (decision == 3)																		// if user wants to unequip Item from both hands
				{
					cout << "You have unequipped " << playerItem.name << " from both hands." << endl;		// inform user
					character.lh.item = Empty;	
					character.playerBody.BodyList[0].item = Empty;											// the left hand now has the playerItem unequipped
					character.rh.item = Empty;		
					character.playerBody.BodyList[1].item = Empty;											// the right hand now has the playerItem unequipped
					character.decreaseAttack(playerItem);													// decrease the attack of user by the amount of bonus 
					character.decreaseAttack(playerItem);													// decrease the attack of user by the amount of bonus
					Unequip();																				// call Unequip function
					decisionMade1 = true;																	// The user has given valid input, exits loop
				}
				else																						// user has made a valid decision
				{
					cout << "You did not enter a valid response. " << endl; cout << endl;					// inform user
				}
			}
		}
		break;
	case 5:																							// if Item is two handed weapon (TwoHandedSword)
	case 6:																							// if Item is two handed weapon (BowAndArrows)
		if (playerItem.quantity == 0)																		// if user does not have playerItem
		{
			cout << "You do not own " << playerItem.name << "." << endl;									// inform user
			Unequip();																						// call Unequip function
		}
		else if (character.lh.item.name == playerItem.name && character.rh.item.name == playerItem.name)	// if playerItem is equipped
		{																							
			cout << "You have unequipped " << playerItem.name << " from both hands." << endl;				// both hands now has the playerItem unequipped
			character.lh.item = Empty;	
			character.playerBody.BodyList[0].item = Empty;													 
			character.rh.item = Empty;		
			character.playerBody.BodyList[1].item = Empty;													// decrease the attack of user by the amount of bonus
			character.decreaseAttack(playerItem);															// call Unequip function
			Unequip();																				
		}
		else																								// if hands do not have playerItem equipped
		{
			cout << "You do not have " << playerItem.name << " equipped." << endl;							// inform user
			Unequip();																						// call Unequip function
		}
		break;
	case 7:																							// if Item is head armor (Helmet)
		if (playerItem.quantity == 0)																		// if user does not have playerItem
		{
			cout << "You do not own " << playerItem.name << "." << endl;									// inform user
			Unequip();																						// call Unequip function
		}
		else if (character.head.item.name != playerItem.name)												// if user does not have playerItem equipped to body part
		{
			cout << "You do not have " << playerItem.name << " equipped." << endl;							// inform user
			Unequip();																						// call Unequip function
		}
		else if (character.head.item.name == playerItem.name)												// if playerItem is equipped 
		{
			cout << "You have unequipped " << playerItem.name << " from head." << endl;						// inform user
			character.head.item = Empty;		
			character.playerBody.BodyList[2].item = Empty;													// the head now has the playerItem unequipped
			character.decreaseHealth(playerItem);															// decrease the maximum health of user by the amount of bonus
			Unequip();																						// call Unequip function
		}
		break;
	case 8:																							// if Item is feet armor (Boots)
		if (playerItem.quantity == 0)																		// if user does not have playerItem
		{
			cout << "You do not own " << playerItem.name << "." << endl;									// inform user
			Unequip();																						// call Unequip function
		}
		else if (character.feet.item.name != playerItem.name)												// if user does not have playerItem equipped to body part
		{
			cout << "You do not have " << playerItem.name << " equipped." << endl;							// inform user
			Unequip();																						// call Unequip function
		}
		else if (character.feet.item.name == playerItem.name)												// if playerItem is equipped
		{
			cout << "You have unequipped " << playerItem.name << " from feet." << endl;						// inform user
			character.feet.item = Empty;	
			character.playerBody.BodyList[5].item = Empty;													// the feet now has the playerItem unequipped
			character.decreaseHealth(playerItem);															// decrease the maximum health of user by the amount of bonus
			Unequip();																						// call Unequip function
		}
		break;
	case 9:																							// if Item is arm armor (Gauntlets)
		if (playerItem.quantity == 0)																		// if user does not have playerItem
		{
			cout << "You do not own " << playerItem.name << "." << endl;									// inform user
			Unequip();																						// call Unequip function
		}
		else if (character.arms.item.name != playerItem.name)												// if user does not have playerItem equipped to body part
		{
			cout << "You do not have " << playerItem.name << " equipped." << endl;							// inform user
			Unequip();																						// call Unequip function
		}
		else if (character.arms.item.name == playerItem.name)												// if playerItem is equipped
		{
			cout << "You have unequipped " << playerItem.name << " from arms." << endl;						// inform user
			character.arms.item = Empty;	
			character.playerBody.BodyList[3].item = Empty;													// the arms now has the playerItem unequipped
			character.decreaseHealth(playerItem);															// decrease the maximum health of user by the amount of bonus
			Unequip();																						// call Unequip function
		}
		break;
	case 10:																						// if Item is leg armor (Pants)
		if (playerItem.quantity == 0)																		// if user does not have playerItem
		{
			cout << "You do not own " << playerItem.name << "." << endl;									// inform user
			Unequip();																						// call Unequip function
		}
		else if (character.legs.item.name != playerItem.name)												// if user does not have playerItem equipped to body part
		{
			cout << "You do not have " << playerItem.name << " equipped." << endl;							// inform user
			Unequip();																						// call Unequip function
		}
		else if (character.legs.item.name == playerItem.name)												// if playerItem is equipped
		{
			cout << "You have unequipped " << playerItem.name << " from legs." << endl;						// inform user
			character.legs.item = Empty;	
			character.playerBody.BodyList[4].item = Empty;													// the legs now has the playerItem unequipped
			character.decreaseHealth(playerItem);															// decrease the maximum health of user by the amount of bonus
			Unequip();																						// call Unequip function
		}
		break;
	case 11:																						// if Item is one handed armor (Shield)
		if (playerItem.quantity == 0)																		// if user does not have playerItem
		{
			cout << "You do not own " << playerItem.name << "." << endl;									// inform user
			Unequip();																						// call Unequip function
		}
		else if (character.lh.item.name != playerItem.name && character.rh.item.name != playerItem.name)	// if user does not have playerItem equipped in either hand
		{
			cout << "You do not have " << playerItem.name << " equipped." << endl;							// inform user
			Unequip();																						// call Unequip function
		}
		else if (character.lh.item.name == playerItem.name && character.rh.item.name != playerItem.name)	// if playerItem is equipped in left hand only
		{
			cout << "You have unequipped " << playerItem.name << " from left hand." << endl;				// inform user	
			character.lh.item = Empty;	
			character.playerBody.BodyList[0].item = Empty;													// the left hand now has the playerItem unequipped
			character.decreaseHealth(playerItem);															// decrease the health of user by the amount of bonus
			Unequip();																						// call Unequip function
		}																									
		else if (character.lh.item.name != playerItem.name && character.rh.item.name == playerItem.name)	// if playerItem is equipped in right hand only
		{
			cout << "You have unequipped " << playerItem.name << " from right hand." << endl;				// inform user	
			character.rh.item = Empty;		
			character.playerBody.BodyList[1].item = Empty;													// the right hand now has the playerItem unequipped
			character.decreaseHealth(playerItem);															// decrease the maximum health of user by the amount of bonus
			Unequip();																						// call Unequip function
		}
		else if (character.lh.item.name == playerItem.name && character.rh.item.name == playerItem.name)	// if playerItem is equipped in both hands
		{
			bool decisionMade1 = false;
			int decision;

			while (decisionMade1 == false)
			{
				cout << "Which hand would you like to unequip " << playerItem.name << "?" << endl;
				cout << "1. Left Hand." << endl;
				cout << "2. Right Hand." << endl;
				cout << "3. Both Hands." << endl;
				cin >> decision; cout << endl;
				if (cin.fail())		// If the user input is invalid (e.g. a char instead of an int)
				{
					cin.clear();	// Clear the user input 
					cin.ignore();	// Ignore the user input through this loop (which will allow another attempt of user input once the loop is passed through)
				}
				else if (decision == 1)																		// if user chooses left hand
				{
					cout << "You have unequipped " << playerItem.name << " from left hand." << endl;		// inform user	
					character.lh.item = Empty;	
					character.playerBody.BodyList[0].item = Empty;											// the left hand now has the playerItem unequipped
					character.decreaseHealth(playerItem);													// decrease the maximum health of user by the amount of bonus
					Unequip();																				// call Unequip function
					decisionMade1 = true;
				}
				else if (decision == 2)																		// if user chooses right hand
				{
					cout << "You have unequipped " << playerItem.name << " from right hand." << endl;		// inform user	
					character.rh.item = Empty;		
					character.playerBody.BodyList[1].item = Empty;											// the right hand now has the playerItem unequipped
					character.decreaseHealth(playerItem);													// decrease the maximum health of user by the amount of bonus
					Unequip();																				// call Unequip function
					decisionMade1 = true;
				}	
				else if (decision == 3)																		// if user chooses both hands
				{	
					cout << "You have unequipped " << playerItem.name << " from both hands." << endl;		// inform user	
					character.lh.item = Empty; 	
					character.playerBody.BodyList[0].item = Empty;											// the left hand now has the playerItem unequipped
					character.rh.item = Empty;	
					character.playerBody.BodyList[1].item = Empty;											// the left hand now has the playerItem unequipped
					character.decreaseHealth(playerItem);													// decrease the maximum health of user by the amount of bonus
					character.decreaseHealth(playerItem);													// decrease the maximum health of user by the amount of bonus
					Unequip();																				// call Unequip function
					decisionMade1 = true;
				}
				else																						// user has made an invalid decision
				{
					cout << "You did not enter a valid response. " << endl; cout << endl;					// inform user	
				}
			}
		}
	case 12:																							// if Item is body armor (Chestplate)
		if (playerItem.quantity == 0)																			// if user does not have playerItem
		{
			cout << "You do not own " << playerItem.name << "." << endl;										// inform user
			Unequip();																							// call Unequip function
		}
		else if (character.body.item.name != playerItem.name)													// if user does not have playerItem equipped to body part
		{
			cout << "You do not have " << playerItem.name << " equipped." << endl;								// inform user
			Unequip();																							// call Unequip function
		}
		else if (character.body.item.name == playerItem.name)
		{
			cout << "You have unequipped " << playerItem.name << " from body." << endl;							// inform user
			character.body.item = Empty;		
			character.playerBody.BodyList[6].item = Empty;														// the body now has the playerItem unequipped
			character.decreaseHealth(playerItem);																// decrease the maximum health of user by the amount of bonus
			Unequip();																							// call Unequip function
		}
		break;
	default:																							// If input is invalid
		cout << "You did not enter a valid response. " << endl; cout << endl;									// inform user
		Unequip();																								// call Unequip function
		break;
	}
}
