/*
	IncreasingDamage ability,
	Each time the tile attacks, its damage increases.
*/

#pragma once

#include <string>

#include "EnemyTileDecorator.h"
#include "TileMediator.h"

namespace Abilities
{

class IncreasingDamage : public EnemyTileDecorator
{
public:
	// incrementAmount is the amount the tile's damage increases each turn after it attacks.
	IncreasingDamage(int incrementAmount, EnemyTile* next);
	
	int getDamage() const;
	std::string getAbilities() const;
	
protected:
	// Appends damage increase to tiles turn
	void handleTilesTurn(TileMediator&);

private:
	// Amount the damage has increased so far
	int damageCounter;
	
	int incrementAmount;
};

}
