#pragma once

#include <string>

#include "Item.h"
#include "Player.h"

class Player;

class Shield : public Item
{
public:
	Shield(const char* name, double blockChance, double blockPercentage);
	
	std::string getLootTileDialog() const;
	
	void equip(Player&) const;
	
	int computeDamageReceived(int damage) const;
	 
private:
	double blockChance;
	double blockPercentage;
};
