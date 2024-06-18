#include "TileMediator.h"

#include <string>
#include <iostream>
#include <thread>
#include <chrono>

#include "Characters.h"
#include "Chunk.h"
#include "Player.h"
#include "World.h"
#include "Tile.h"
#include "InputBindings.h"

TileMediator::TileMediator(World& world, Player& player, InputBindings& bindings) :
	world(world),
	player(player),
	bindings(bindings),
	mapInradius(5)
{
}

void TileMediator::clearConsole() const
{
	system("clear");
}

void TileMediator::printMap() const
{
	print(CHARS::BORDER_TOP_LEFT);
	for (int i = 0; i < 2 * mapInradius + 1; i++) {
		print(CHARS::BORDER_HORIZONTAL);
	}
	print(CHARS::BORDER_TOP_RIGHT);
	print("\n");
	
	for (int y = player.getY() - static_cast<int>(mapInradius); y <= player.getY() + static_cast<int>(mapInradius); y++) {
		print(CHARS::BORDER_VERTICAL);
		
		// print tiles and player
		for (int x = player.getX() - static_cast<int>(mapInradius); x <= player.getX() + static_cast<int>(mapInradius); x++) {
			if (x == player.getX() && y == player.getY()) {
				print(CHARS::PLAYER);
			} else if (world.getTile(x, y)->isHidden()) {
				print(CHARS::HIDDEN_TILE);
			} else {
				print(world.getTile(x, y)->getCharacter());
			}	
		}
		
		print(CHARS::BORDER_VERTICAL);
		print("\n");
	}
	
	print(CHARS::BORDER_BOTTOM_LEFT);
	for (int i = 0; i < 2 * mapInradius + 1; i++) {
		print(CHARS::BORDER_HORIZONTAL);
	}
	print(CHARS::BORDER_BOTTOM_RIGHT);
	print("\n");
}

void TileMediator::printInventory() const
{
	for (int i = 0; i < Player::INVENTORY_SIZE; i++) {
		std::cout << (i + 1) << ": " << player.getInventoryItem(i)->getName() << std::endl;
	}
}

bool TileMediator::handleMovementInput()
{
	std::string inputStr;
	std::cin >> inputStr;
	const char* input = &inputStr[0];
	bool moved = true;
	if (bindings.checkInput(BINDINGS::MOVE_UP, input)) {
		player.changeY(-1);
	} else if (bindings.checkInput(BINDINGS::MOVE_LEFT, input)) {
		player.changeX(-1);
	} else if (bindings.checkInput(BINDINGS::MOVE_DOWN, input)) {
		player.changeY(1);
	} else if (bindings.checkInput(BINDINGS::MOVE_RIGHT, input)) {
		player.changeX(1);
	} else {
		moved = false;
	}
	
	if (moved) {
		revealArea(player.getX(), player.getY(), player.getSightRadius());
	}
	
	return moved;
}

void TileMediator::revealArea(int x, int y, int radius)
{
	// Iterate over square that circumscribes the circle
	for (int i = x - radius; i <= x + radius; i++) {
		for (int j = y - radius; j <= y + radius; j++) {
			int dx = x - i;
			int dy = y - j;
			// Compare distance squared so that the square root does not need to be taken
			int distanceSquared = dx * dx + dy * dy;
			if (distanceSquared <= radius * radius) {
				world.getTile(i, j)->reveal();
			}
		}
	}
}

void TileMediator::print(std::string text, unsigned int millisecondsPerChar) const
{
	if (millisecondsPerChar == 0) {
		std::cout << text;
	} else {
		for (auto it = text.begin(); it != text.end(); it++) {
			if (it != text.begin()) {
				std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsPerChar));
			}
			std::cout << *it << std::flush;
		}
	}
}
