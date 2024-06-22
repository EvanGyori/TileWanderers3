#include "Weapon.h"

#include <string>
#include <cstring>
#include <cmath>

#include "Random.h"

#include "Player.h"

Weapon::Weapon(const char* name, unsigned int damage, double critChance, double critMultiplier) :
	Item(name),
	damage(damage),
	critChance(critChance),
	critMultiplier(critMultiplier)
{
}

std::string Weapon::getLootTileDialog() const
{
	return "weapon\n";
}

void Weapon::equip(Player& player) const
{
	player.setWeapon(this);
}

int Weapon::computeDamage() const
{
	if (MyToolkit::randomDouble() <= critChance) {
		// Rounded up so that the critMultiplier still has an effect if it is low.
		return static_cast<int>(std::ceil(damage * critMultiplier));
	}
	
	return damage;
}

double Weapon::getAverageDamage() const
{
	return damage * (1 + critChance * (critMultiplier - 1));
}
