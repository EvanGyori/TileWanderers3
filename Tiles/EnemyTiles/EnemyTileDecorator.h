/*
 Subclasses of EnemyTileDecorator tack on functionality to EnemyTile classes to add new abilities and layers.
 To instantiate an EnemyTile with some decorators, pass in the instance pointer of EnemyTile to the decorator's constructor
 and that decorator is passed in to the next decorator's constructor and so on for as many decorators as needed.
*/

#pragma once

#include <string>

#include "Tile.h"
#include "EnemyTile.h"
#include "TileMediator.h"

namespace Abilities
{

class EnemyTileDecorator : public EnemyTile
{
public:
	EnemyTileDecorator(EnemyTile* next);
	
	virtual ~EnemyTileDecorator();
	
	virtual Tile* clone() const;
	virtual const char* getCharacter() const;
	
	virtual void changeHp(int deltaHp);
	
	virtual std::string getName() const;
	virtual int getHp() const;
	virtual int getMaxHp() const;
	virtual int getDamage() const;
	virtual std::string getAbilities() const;
	
	virtual void handlePlayersTurn(TileMediator&);
	virtual void handleTilesTurn(TileMediator&);
	virtual void handleTilesDeath(TileMediator&);
	
	void setRootParent(EnemyTile* root);
	
protected:
	std::string concatenateAbility(std::string ability) const;
	
private:
	EnemyTile* next;
};

}
