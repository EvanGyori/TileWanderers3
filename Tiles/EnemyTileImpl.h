#pragma once

#include <string>

#include "EnemyTile.h"
#include "Tile.h"
#include "TileMediator.h"

class EnemyTileImpl : public EnemyTile
{
public:
	EnemyTileImpl(const char* name, int maxHp, int damage, const Tile* onDeathReplacement);
	
	Tile* clone() const;
	const char* getCharacter() const;

	void changeHp(int deltaHp);
	
	std::string getName() const;
	int getHp() const;
	int getMaxHp() const;
	int getDamage() const;
	std::string getAbilities() const;
	
protected:
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
