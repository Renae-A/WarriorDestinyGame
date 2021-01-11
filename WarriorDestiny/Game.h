#pragma once
#include "stdafx.h"
#include <string>
#include "AllEnemyHeaders.h"
#include "Item.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

static char HEADER_INFO[20] = "Renae V1.0";
static char FOOTER_INFO[30] = "";

class Game
{
public:

	Game();
	~Game();

	void menu();			// menu() displays the user's options within the town
	void NewGame();			// NewGame() creates a new game (Class game) and will introduce the story to the user 
	void LoadGame();		// LoadGame() allows the user to search the savefile.txt for a name that that used in a prior game session
	void SaveAndExit();		// SaveAndExit() allows the user to either save their game information to the savefile.text and exit or save their game information to the savefile.text and continue playing
	void SaveDateAndTime();	// SaveDateAndTime() is an optional function for if the user wants to save the current time and date into their save file at the footer
	void Save();			// Save contains the function to save all the game information

	void ManageInventory();	// ManageInventory() displays the user's inventory and their options within their inventory
	void Equip();			// Equip() allows the user to equip Items to BodyParts (which will result in their character improving their stats)
	void Unequip();			// Unequip() allows the user to unequip Items to BodyParts (which will result in their character reducing their stats)
	void EquippedItems();	// EquippedItems() displays each BodyPart and the Item equipped to the corresponding part.
	void ItemInfo();		// ItemInfo() allows the user to sort their items temporarily if they desire for easy readability and allows the user to research the Items' stats

	Player character;		// character is the user's character (only one should be created per game)
	Enemies theEnemies;		// theEnemies is a list of the classes information that derive from Enemy (this does not contain the classes themselves)

	Inventory weaponStore;	// weaponStore contains all the Weapon Shop's Item information
	Inventory armorStore;	// armorStore contains all the Armor Shop's Item information
	
	void ArmorShopMenu();	// ArmorShopMenu() displays the user's options within the Armor Shop
	void BuyArmor();		// BuyArmor() allows the user to purchase Items from the Armor Shop
	void SellArmor();		// SellArmor() allows the user to sell Items to the Armor Shop for gold
	void TalkArmor();		// TalkArmor() allows the user to talk to the armor smith for information

	void WeaponShopMenu();	// WeaponShopMenu() displays the user's options within the Weapon Shop
	void BuyWeapon();		// BuyWeapon() allows the user to purchase Items from the Weapon Shop
	void SellWeapon();		// SellWeapon() allows the user to sell Items to the Weapon Shop for gold
	void TalkWeapon();		// TalkWeapon() allows the user to talk to the weapon smith for information

	void Markets();			// Markets() displays the user's options within the Markets

	void ManStall();		// ManStall() allows the user to decide if they want to play a number guessing game with a man
	void NumberGame();		// NumberGame() allows the user to play a number guess game and displays the rules
	void FirstGuessNumberGame(int& min, int& max, int& guess, int& count, int& number);		// FirstGuessNumberGame takes parameters that are the reference of the minimum value of the range,
																							// the maximum of the range, the guess that the man makes, the count of guesses the man has made and
																							// and the number that the user has chosen. This function introduces the game before further guesses are made
	void NextGuessNumberGame(int& max, int& min, int& guess, int& count, int& number);		// NextGuessNumberGame takes parameters that are the reference of the minimum value of the range,
																							// the maximum of the range, the guess that the man makes, the count of guesses the man has made and
																							// and the number that the user has chosen. This function is looped until the game is complete
	void NumberGameAgain();		// NumberGameAgain() allows the user to decide if they want to play the number guessing game again																						
																							
	void BoyStall();		// BoyStall() allows the user to decide if they want to play a Tic Tac Toe game or a Rock, Paper Scissors clone game with two boys													
	void TicTacToeRules();	// TicTacToeRules() displays the rules for Tic Tac Toe and allows the user to decide on if they want to play
	void TicTacToe();		// TicTacToe() intitialises the game and displays the first 3x3 array (player board)
	void PlayerShotTicTacToe(int& row, int& col, char boxes[3][3]);		// PlayerShotTicTacToe takes in the parameters that are the reference of the amount of rows in the 3x3 array, the amount of
																		// columns in the 3x3 array and boxes array and its elements. This function allows the user to choose the row and column
																		// they want to place their 'O'
	void BoyShotTicTacToe(int& row, int& col, char boxes[3][3]);		// BoyShotTicTacToe takes in the parameters that are the reference of the amount of rows in the 3x3 array, the amount of
																		// columns in the 3x3 array and boxes array and its elements. This function chooses a random row and column for the boy to
 																		// place their 'X'
	void TicTacToeGameOver(int& row, int& col, char boxes[3][3]);		// TicTacToeGameOvertakes in the parameters that are the reference of the amount of rows in the 3x3 array, the amount of
																		// columns in the 3x3 array and boxes array and its elements. This function displays the results of the finished game and 
																		// either adds or subtracts gold depending on results
	void TicTacToeAnotherGame();	// TicTacToeAnotherGame() asks the user if they want to play another game of Tic Tac Toe

	void FireGrassWaterRules();		// FireGrassWaterRules() displays the rules for Fire, Grass, Water (Rock, Paper, Scissors) and allows the user to decide on if they want to play
	void FireGrassWater();			// FireGrassWater() gets the user to choose Fire, Grass or Water and a random choice of the three elements is made to determine if the user wins or not
	void FireGrassWaterAgain();		// FireGrassWaterAgain() asks the user if they want to play the game again

	void BattleArena();					// BattleArena() displays the user's options within the Battle Arena
	void PracticeBattle();				// PracticeBattle() displays the rules of the battle and allows the user to decide if they want to continue
	void StartPractice();				// StartPractice() allows the user to decide on which Enemy they are to battle with
	void PracticeResults(Enemy& beast);	// PracticeResults take the parameter reference of an Enemy which will be used to battle with the user's character. This function will display the results and 
										// add health and gold to the user character or subtract gold from the user character

	void Tournament();						// Tournament() displays the rules of the tournament and allows the user to decide if they want to continue
	void StartTournament();					// StartPractice() allows the user to decide on which Enemy they are to go into the tournament with
	void TournamentResults(int decision);	// TournamentResults take the parameter of an integer corresponding to an Enemy which will be used to go into tournament with the user's character. 
											// This function will display the results and add health and gold to the user character or subtract gold from the user character

	bool GhoulAlive(vector<Ghoul>& group);		// GhoulAlive takes in a vector reference of Ghouls that returns true if at least 1 Ghoul is alive or false if all Ghouls are dead 
	bool CyclopsAlive(vector<Cyclops>& group);	// CyclopsAlive takes in a vector reference of Cyclops that returns true if at least 1 Cyclops is alive or false if all Cyclops are dead 
	bool CentaurAlive(vector<Centaur>& group);	// CentaurAlive takes in a vector reference of Centaurs that returns true if at least 1 Centaur is alive or false if all Centaurs are dead 
	bool OgreAlive(vector<Ogre>& group);			// OgreAlive takes in a vector reference of Ogres that returns true if at least 1 Ogre is alive or false if all Ogres are dead 
	bool DemonAlive(vector<Demon>& group);		// DemonAlive takes in a vector reference of Demons that returns true if at least 1 Demon is alive or false if all Demons are dead 

	void BossCompetition();					// BossCompetition() displays the rules of the competition and allows the user to decide if they want to continue
	void StartCompetition();				// StartCompetition() allows the user to decide on which boss Enemy they are to battle with
	void CompetitionResults(Enemy& beast);	// CompetitionResults takes in the parameter reference of Enemy which will be used to determine how much gold and health the user will gain. This function 
											// displays the results of the competition

	void EnemyStatistics();		// EnemyStatistics() displays all the information about each Enemy they can battle with

	void ReturnHome();			// ReturnHome() will either tell the user that they need to earn more gold or allow them to return home for the conclusion of the game to be displayed

private:
	void WeaponInventoryInitialisation();	// WeaponInventoryInitialisation() intialises all the Items and their information in the Weapon Shop and returns this information as an Inventory
	void ArmorInventoryInitialisation();	// ArmorInventoryInitialisation() intialises all the Items and their information in the Armor Shop and returns this information as an Inventory
	void initialiseEnemyList();	// intialises all the Enemies and their information in a list

};

