/*
 GameManager handles the introduction, gameplay loop, and ending.
 Simply call the run method.
*/

#pragma once

#include "World.h"
#include "Player.h"
#include "InputBindings.h"
#include "TileMediator.h"

class GameManager
{
public:
	GameManager();

	void run();

protected:
	void menu();
	void update();
	void quit();

private:
	World world;
	Player player;
	InputBindings bindings;
	TileMediator tileMediator;
};
