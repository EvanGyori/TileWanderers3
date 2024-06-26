#pragma once

#include <string>

#include "Item.h"
#include "Player.h"

class Consumable : public Item
{
public:
	Consumable(const char* name);

	virtual std::string getLootTileDialog() const;
	
	// Adds this item to the player's inventory
	void equip(Player&) const;
	
	/*
	 Applys the effect of this item to the player.
	 The effect is determined by the subclass.
	*/
	virtual void consume(Player&) const = 0;
};
