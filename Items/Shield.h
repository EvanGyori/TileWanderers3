#pragma once

#include <string>

#include "Item.h"
#include "Player.h"

class Player;

class Shield : public Item
{
public:
	Shield(const char* name, double blockChance, double blockPercentage);
	
	// Returns a string containing what to print for a loot tile containing a shield
	std::string getLootTileDialog() const;
	
	// Sets the player's weapon to this
	void equip(Player&) const;
	
	/*
	 Determines and returns the damage based on the chance of it
	 getting blocked and only a portion of the damage being returned.
	*/
	int computeDamageReceived(int damage) const;
	 
private:
	double blockChance;
	double blockPercentage;
};
