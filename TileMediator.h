#pragma once

#include <string>

//#include "World.h"
//#include "Player.h"

class World;
class Player;
class InputBindings;
class EnemyTile;

// Manipulate write position
// https://stackoverflow.com/questions/27599233/how-to-manipulate-the-terminal-output-buffer-directly

class TileMediator
{
public:
	TileMediator(World& world, Player& player, InputBindings& bindings);

	void clearConsole() const;
	
	// Prints the tiles around the player in a square
	void printMap() const;
	
	// Prints the player's inventory
	void printInventory() const;
	
	void printBattle(EnemyTile* tile) const;
	
	// Asks the user for movement input and moves the player in that direction
	// Returns false if an invalid input is given.
	bool handleMovementInput();
	
	//void handleInventoryInput();
	//void handleBattleInput();
	
	// Reveals the tiles in a circular area with the circle's origin at x and y
	void revealArea(int x, int y, int radius);
	
	bool isPlayerAlive() const;
	
private:
	World& world;
	Player& player;
	InputBindings& bindings;
	
	// Distance from center to edge
	unsigned int mapInradius;
	
	void print(std::string text, unsigned int millisecondsPerChar = 0) const;
};
