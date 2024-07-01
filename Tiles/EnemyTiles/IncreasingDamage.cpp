#include "IncreasingDamage.h"

#include <format>

namespace Abilities
{

IncreasingDamage::IncreasingDamage(int incrementAmount) :
	damageCounter(0),
	incrementAmount(incrementAmount)
{

}

int IncreasingDamage::getDamage() const
{
	return damageCounter + EnemyTileDecorator::getDamage();
}

std::string IncreasingDamage::getAbilities() const
{
	return concatenateAbilities(std::format("+{} attack damage each round", incrementAmount));
}

void handleTilesTurn(TileMediator& mediator)
{
	EnemyTileDecorator::handleTilesTurn(mediator);
	damageCounter += incrementAmount;
	mediator.clearConsole();
	mediator.print(std::format("The tile's damage increased by {}\n", incrementAmount), TileMediator::DEFAULT_PRINT_SPEED);
	mediator.pauseConsole();
}

}
