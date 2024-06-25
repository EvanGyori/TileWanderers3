#pragma once

#include <string>

#include "Item.h"
#include "Player.h"

class Consumable : public Item
{
public:
	Consumable(const char* name);

	virtual std::string getLootTileDialog() const;
	
	void equip(Player&) const;
	
	virtual void consume(Player&) const = 0;
};
