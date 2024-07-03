#pragma once

#include <string>

#include "EnemyTile.h"
#include "Tile.h"
#include "TileMediator.h"

class EnemyTileImpl : public EnemyTile
{
public:
	/*
	 When this tile's hp is less than or equal to zero, the tile prototype, onDeathReplacement, replaces this tile in the chunk
	*/
	EnemyTileImpl(const char* name, int maxHp, int damage, const Tile* onDeathReplacement);
	
	EnemyTileImpl(const EnemyTileImpl&);
	
	Tile* clone() const;
	const char* getCharacter() const;

	void changeHp(int deltaHp);
	
	std::string getName() const;
	int getHp() const;
	int getMaxHp() const;
	int getDamage() const;
	std::string getAbilities() const;
	
	void handlePlayersTurn(TileMediator&);
	void handleTilesTurn(TileMediator&);
	void handleTilesDeath(TileMediator&);
	
	void setRootParent(EnemyTile* root);
	
private:
	EnemyTile* root;

	const char* name;
	int hp;
	int maxHp;
	int damage;
	const Tile* onDeathReplacement;
};
