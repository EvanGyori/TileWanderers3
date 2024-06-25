#include "Consumable.h"

#include <string>

#include "Item.h"
#include "Player.h"

Consumable::Consumable(const char* name) :
	Item(name)
{
}

std::string Consumable::getLootTileDialog() const
{
	return "Consumable\n";
}

void Consumable::equip(Player& player) const
{
	player.addItemToInventory(this);
}
