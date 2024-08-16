#include "Shield.h"

#include <cmath>
#include <string>

#include "MyToolkit/Random.h"

#include "Player.h"

Shield::Shield(const char* name, double blockChance, double blockPercentage) :
	Item(name),
	blockChance(blockChance),
	blockPercentage(blockPercentage)
{
}

std::string Shield::getLootTileDialog() const
{
	return "Shield\n";
}

void Shield::equip(Player& player) const
{
	player.setShield(this);
}

int Shield::computeDamageReceived(int damage) const
{
	if (MyToolkit::randomDouble() <= blockChance) {
		// Rounded up so that a shield with 100% block chance does not always output zero for small attacks.
		return static_cast<int>(std::ceil(damage * (1 - blockPercentage)));
	}
	
	return damage;
}
