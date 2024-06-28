/*
 The TileMediator class handles operations that a Tile performs during its update method.
 This decouple the Tile from the World, Player, and InputBindings classes so
 that the tile only interacts directly with this class.
 
 This mediator also handles printing to the console so that the implementation may easily change depending on platform.
*/
#pragma once

#include <string>

//#include "World.h"
//#include "Player.h"

class World;
class Player;
class InputBindings;
class Tile;
class EnemyTile;
class Consumable;

// Manipulate write position
// https://stackoverflow.com/questions/27599233/how-to-manipulate-the-terminal-output-buffer-directly

class TileMediator
{
public:
	TileMediator(World& world, Player& player, InputBindings& bindings);

	void clearConsole() const;
	
	// Waits for user input to continue the program so that the user may read the console output
	void pauseConsole() const;
	
	// Prints the tiles around the player in a square
	void printMap() const;
	
	// Prints the player's inventory
	void printInventory() const;
	
	void printBattle(EnemyTile* tile) const;
	
	/*
	 Asks the user for movement input and moves the player in that direction.
	 Returns false if an invalid input is given.
	*/
	bool handleMovementInput();
	
	/*
	 Asks the user for inventory input to either use an item or exit the inventory.
	 Returns false if an invalid input is given.
	 Points itemUsed to the item that the player chooses to use.
	 Points itemUsed to nullptr if no item is used and the player exits the inventory.
	*/
	bool handleInventoryInput(const Consumable** itemUsed = nullptr);
	
	/*
	 Asks the player for battle input which may include attacking, inventory use, or retreating.
	 Returns false if an invalid input is given.
	*/
	bool handleBattleInput(EnemyTile* tile);
	
	// Reveals the tiles in a circular area with the circle's origin at x and y
	void revealArea(int x, int y, int radius);
	
	bool isPlayerAlive() const;
	
	// Uses the player's shield to calculate the final damage and applies it to the player
	void attackPlayer(int damage);
	
	// Sets the tile that the player is on to a copy of prototype
	void setCurrentTile(const Tile* prototype);
	
private:
	static const unsigned int defaultPrintSpeed = 10;

	World& world;
	Player& player;
	InputBindings& bindings;
	
	// Distance from center to edge
	unsigned int mapInradius;
	
	void print(std::string text, unsigned int millisecondsPerChar = 0) const;
};
