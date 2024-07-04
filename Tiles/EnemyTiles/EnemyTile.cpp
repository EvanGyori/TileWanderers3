#include "EnemyTile.h"

EnemyTile::~EnemyTile()
{
}

void EnemyTile::update(TileMediator& mediator)
{
	handlePlayersTurn(mediator);
	
	if (getHp() > 0) {
		handleTilesTurn(mediator);
	} else {
		handleTilesDeath(mediator);
	}
}
