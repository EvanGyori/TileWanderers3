#include "GameManager.h"

#include "Chunk.h"
#include "World.h"
#include "Player.h"
#include "TileMediator.h"
#include "InputBindings.h"

GameManager::GameManager() :
	player(Chunk::SIZE / 2, Chunk::SIZE / 2),
	tileMediator(world, player, bindings)
{
}

void GameManager::run()
{
	menu();
	tileMediator.revealArea(player.getX(), player.getY(), player.getSightRadius());
	while (player.getHp() > 0) {
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
