#pragma once

#include <string>

//#include "Player.h"

class Player;

class Item
{
public:
	Item(const char* name);

	// Returns a string containing what to print when the player is on a loot tile
	virtual std::string getLootTileDialog() const = 0;
	
	// Adds the item to the player, whether that be to the inventory, weapon, or shield slot.
	virtual void equip(Player&) const = 0;
	
	const char* getName() const;
	
private:
	const char* name;
};
