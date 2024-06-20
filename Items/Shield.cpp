#include "Shield.h"

#include <cmath>
#include <string>

#include "Random.h"

#include "Player.h"

Shield::Shield(const char* name, double blockChance, double blockPercentage) :
	Item(name),
	blockChance(blockChance),
	blockPercentage(blockPercentage)
{
}

std::string Shield::getLootTileDialog() const
{
	return "shield";
}

void Shield::equip(Player& player) const
{
	player.setShield(this);
}

int Shield::computeDamageReceived(int damage) const
{
	if (MyToolkit::randomDouble() <= blockChance) {
		return static_cast<int>(std::ceil(damage * (1 - blockPercentage)));
	}
	
	return damage;
}
