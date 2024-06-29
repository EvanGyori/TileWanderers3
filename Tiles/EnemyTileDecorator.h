#pragma once

#include <string>

#include "EnemyTile.h"
#include "TileMediator.h"

class EnemyTileDecorator : public EnemyTile
{
public:
	EnemyTileDecorator(EnemyTile* next);
	
	virtual ~EnemyTileDecorator();
	
	virtual void changeHp(int deltaHp);
	
	virtual std::string getName() const;
	virtual int getHp() const;
	virtual int getMaxHp() const;
	virtual int getDamage() const;
	virtual std::string getAbilities() const;
	
protected:
	virtual void handlePlayersTurn(TileMediator&);
	virtual void handleTilesTurn(TileMediator&);
	virtual void handleTilesDeath(TileMediator&);
	
	void setRootParent(EnemyTile* root);
	
private:
	EnemyTile* next;
};
