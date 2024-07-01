#include "EnemyTileDecorator.h"

#include <string>

#include "EnemyTile.h"
#include "TileMediator.h"

namespace abilities
{

EnemyTileDecorator::EnemyTileDecorator(EnemyTile* next) :
	next(next)
{
	next->setRootParent(this);
}

EnemyTileDecorator::~EnemyTileDecorator()
{
	delete next;
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

}
