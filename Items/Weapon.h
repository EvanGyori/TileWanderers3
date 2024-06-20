#pragma once

#include <string>

#include "Item.h"
#include "Player.h"

class Player;

class Weapon : public Item
{
public:
	Weapon(const char* name, unsigned int damage, double critChance, double critMultiplier);
	
	// Returns a string containing what to print when the player is on a loot tile with a weapon
	std::string getLootTileDialog() const;
	
	// Sets the player's weapon to this
	void equip(Player&) const;
	
	// Determines and returns damage based on the chance of a critical attack.
	int computeDamage() const;

private:
	unsigned int damage;
	double critChance;
	double critMultiplier;
	
	// Given the chance of a critical attack, returns the average damage that will be returned from the computeDamage method
	double getAverageDamage() const;
};
