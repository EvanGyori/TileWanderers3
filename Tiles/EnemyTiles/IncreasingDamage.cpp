#include "IncreasingDamage.h"

#include <string>

namespace Abilities
{

IncreasingDamage::IncreasingDamage(int incrementAmount, EnemyTile* next) :
	damageCounter(0),
	incrementAmount(incrementAmount),
	EnemyTileDecorator(next)
{
}

Tile* IncreasingDamage::clone() const
{
	return new IncreasingDamage(*this);
}

int IncreasingDamage::getDamage() const
{
	return damageCounter + EnemyTileDecorator::getDamage();
}

std::string IncreasingDamage::getAbilities() const
{
	std::string ability = "+" + std::to_string(incrementAmount) + " attack damage each round";
	return concatenateAbility(ability);
}

void IncreasingDamage::handleTilesTurn(TileMediator& mediator)
{
	EnemyTileDecorator::handleTilesTurn(mediator);
	damageCounter += incrementAmount;
	mediator.clearConsole();
	std::string message = "The tile's damage increased by " + std::to_string(incrementAmount) + "\n";
	mediator.print(message, TileMediator::DEFAULT_PRINT_SPEED);
	mediator.pauseConsole();
}

}
