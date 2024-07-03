#include "EnemyTileImpl.h"

#include <string>
#include <cassert>

#include "Tile.h"
#include "TileMediator.h"
#include "Characters.h"

EnemyTileImpl::EnemyTileImpl(const char* name, int maxHp, int damage, const Tile* onDeathReplacement) :
	root(this),
	name(name),
	hp(maxHp),
	maxHp(maxHp),
	damage(damage),
	onDeathReplacement(onDeathReplacement)
{
}

EnemyTileImpl::EnemyTileImpl(const EnemyTileImpl& rhs) :
	root(this),
	name(rhs.name),
	hp(rhs.hp),
	maxHp(rhs.maxHp),
	damage(rhs.damage),
	onDeathReplacement(rhs.onDeathReplacement)
{
}

Tile* EnemyTileImpl::clone() const
{
	return new EnemyTileImpl(*this);
}

const char* EnemyTileImpl::getCharacter() const
{
	return CHARS::ENEMY_TILE;
}

void EnemyTileImpl::changeHp(int deltaHp)
{
	hp += deltaHp;
}

std::string EnemyTileImpl::getName() const
{
	return name;
}

int EnemyTileImpl::getHp() const
{
	return hp;
}

int EnemyTileImpl::getMaxHp() const
{
	return maxHp;
}

int EnemyTileImpl::getDamage() const
{
	return damage;
}

std::string EnemyTileImpl::getAbilities() const
{
	return "";
}

void EnemyTileImpl::handlePlayersTurn(TileMediator& mediator)
{
	do {
		mediator.clearConsole();
		mediator.printBattle(root);
	} while (!mediator.handleBattleInput(root));
}

void EnemyTileImpl::handleTilesTurn(TileMediator& mediator)
{
	mediator.attackPlayer(root->getDamage());
}

void EnemyTileImpl::handleTilesDeath(TileMediator& mediator)
{
	mediator.setCurrentTile(onDeathReplacement);
}

void EnemyTileImpl::setRootParent(EnemyTile* root)
{
	assert(root != nullptr);
	this->root = root;
}
