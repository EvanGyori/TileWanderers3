#pragma once

#include <string>

#include "Tile.h"
#include "TileMediator.h"

class TileMediator;

class EnemyTile : public Tile
{
public:
	virtual ~EnemyTile();

	virtual void update(TileMediator&);
	
	virtual void changeHp(int deltaHp) = 0;
	
	virtual std::string getName() const = 0;
	virtual int getHp() const = 0;
	virtual int getMaxHp() const = 0;
	virtual int getDamage() const = 0;
	virtual std::string getAbilities() const = 0;
	
protected:
	virtual void handlePlayersTurn(TileMediator&) = 0;
	virtual void handleTilesTurn(TileMediator&) = 0;
	virtual void handleTilesDeath(TileMediator&) = 0;
	
	virtual void setRootParent(EnemyTile* root) = 0;
};
