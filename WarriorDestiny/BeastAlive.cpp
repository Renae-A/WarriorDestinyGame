#include "stdafx.h"
#include "Game.h"
#include "AllEnemyHeaders.h"
#include <iostream>
#include <vector>

// Is there any ghoul in the group still alive?
bool Game::GhoulAlive(vector<Ghoul>& group)
{
	return group.size() > 0;	// return true if there is at least 1 ghoul alive, false otherwise
}
// Is there any cyclops in the group still alive?
bool Game::CyclopsAlive(vector<Cyclops>& group)
{
	return group.size() > 0;	// return true if there is at least 1 cyclops alive, false otherwise
}
// Is there any centaur in the group still alive?
bool Game::CentaurAlive(vector<Centaur>& group)
{
	return group.size() > 0;	// return true if there is at least 1 centaur alive, false otherwise
}
// Is there any ogre in the group still alive?
bool Game::OgreAlive(vector<Ogre>& group)
{
	return group.size() > 0;	// return true if there is at least 1 ogre alive, false otherwise
}
// Is there any demon in the group still alive?
bool Game::DemonAlive(vector<Demon>& group)
{
	return group.size() > 0;	// return true if there is at least 1 demon alive, false otherwise
}
