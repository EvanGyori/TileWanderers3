#include "EnemyTile.h"

EnemyTile::~EnemyTile()
{
}

void EnemyTile::update(TileMediator& mediator)
{
	while (mediator.isPlayerAlive() && getHp() > 0) {
		mediator.clearConsole();
		mediator.printBattle(this);
		handlePlayersTurn(mediator);
		handleTilesTurn(mediator);
	}
	
	if (getHp() <= 0) {
		handleTilesDeath(mediator);
	}
}
