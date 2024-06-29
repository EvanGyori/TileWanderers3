#include "EnemyTile.h"

EnemyTile::~EnemyTile()
{
}

void EnemyTile::update(TileMediator& mediator)
{
	handlePlayersTurn(mediator);
	handleTilesTurn(mediator);
		
	if (getHp() <= 0) {
		handleTilesDeath(mediator);
	}
}
