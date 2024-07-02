#pragma once

#include <string>

#include "Tile.h"
#include "TileMediator.h"

class TileMediator;

class EnemyTile : public Tile
{
public:
	virtual ~EnemyTile();

	// Controls the battle loop between the player and tile
	virtual void update(TileMediator&);
	
	virtual void changeHp(int deltaHp) = 0;
	
	virtual std::string getName() const = 0;
	virtual int getHp() const = 0;
	virtual int getMaxHp() const = 0;
	virtual int getDamage() const = 0;
	
	/*
	 Returns a string listing all of the special abilities of the tile.
	 These abilities are determined by the enemy tile decorators
	*/
	virtual std::string getAbilities() const = 0;
	
	// Handles the beginning of a battle with a player's input.
	virtual void handlePlayersTurn(TileMediator&) = 0;
	
	// Handles after the player gives input and now its the tile's turn to deal damage.
	virtual void handleTilesTurn(TileMediator&) = 0;
	
	virtual void handleTilesDeath(TileMediator&) = 0;
	
	/*
	 Each decorator must call this on its aggregate on instantiation.
	 When this is called on a decorator, it must pass the root to its aggregate.
	 The root is held so that an instance passes the root rather than itself to the TileMediator
	 so that polymorphism may properly be performed.
	*/
	virtual void setRootParent(EnemyTile* root) = 0;
};
