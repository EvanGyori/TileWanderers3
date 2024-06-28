#include "GameManager.h"

#include <cstdlib>
#include <ctime>

#include "Chunk.h"
#include "World.h"
#include "Player.h"
#include "TileMediator.h"
#include "InputBindings.h"
#include "Database.h"

GameManager::GameManager() :
	player(Chunk::SIZE / 2, Chunk::SIZE / 2),
	tileMediator(world, player, bindings)
{
}

void GameManager::run()
{
	srand(time(NULL));
	menu();
	tileMediator.revealArea(player.getX(), player.getY(), player.getSightRadius());
	world.setTile(player.getX(), player.getY(), Database::getInstance().getTile(TILES::EMPTY));
	while (player.getHp() > 0) {
		world.cleanupReplacedTiles();
		update();
	}
	quit();
}

void GameManager::menu()
{
	// TODO
}

void GameManager::update()
{
	world.getTile(player.getX(), player.getY())->update(tileMediator);
}

void GameManager::quit()
{
	// TODO
}
