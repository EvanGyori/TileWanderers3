#include "EnemyTile.h"

EnemyTile::~EnemyTile()
{
}

void EnemyTile::update(TileMediator& mediator)
{
	while (mediator.isPlayerAlive() && getHp() > 0) {
		handlePlayersTurn(mediator);
		handleTilesTurn(mediator);
	}
	
	if (getHp() <= 0) {
		handleTilesDeath(mediator);
	}
}
