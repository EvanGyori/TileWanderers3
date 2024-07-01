#include "EnemyTileDecorator.h"

#include <string>
#include <cassert>

#include "Tile.h"
#include "EnemyTile.h"
#include "TileMediator.h"

namespace Abilities
{

EnemyTileDecorator::EnemyTileDecorator(EnemyTile* next) :
	next(next)
{
	assert(next != nullptr);
	next->setRootParent(this);
}

EnemyTileDecorator::~EnemyTileDecorator()
{
	delete next;
}

Tile* EnemyTileDecorator::clone() const
{
	Tile* nextClone = next->clone();
	assert(dynamic_cast<EnemyTile*>(nextClone) != nullptr);
	return new EnemyTileDecorator(static_cast<EnemyTile*>(nextClone));
}

const char* EnemyTileDecorator::getCharacter() const
{
	return next->getCharacter();
}

void EnemyTileDecorator::changeHp(int deltaHp)
{
	next->changeHp(deltaHp);
}

std::string EnemyTileDecorator::getName() const
{
	return next->getName();
}

int EnemyTileDecorator::getHp() const
{
	return next->getHp();
}

int EnemyTileDecorator::getMaxHp() const
{
	return next->getMaxHp();
}

int EnemyTileDecorator::getDamage() const
{
	return next->getDamage();
}

std::string EnemyTileDecorator::getAbilities() const
{
	return next->getAbilities();
}

void EnemyTileDecorator::handlePlayersTurn(TileMediator& mediator)
{
	next->handlePlayersTurn(mediator);
}

void EnemyTileDecorator::handleTilesTurn(TileMediator& mediator)
{
	next->handleTilesTurn(mediator);
}

void EnemyTileDecorator::handleTilesDeath(TileMediator& mediator)
{
	next->handleTilesDeath(mediator);
}

void EnemyTileDecorator::setRootParent(EnemyTile* root)
{
	next->setRootParent(root);
}

std::string EnemyTileDecorator::concatenateAbility(std::string ability)
{
	std::string otherAbilities = getAbilities();
	return (otherAbilities == "") ? ability : (ability + ";" + otherAbilities);
}

}
