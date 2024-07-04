#include "TileMediator.h"

#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <cassert>

#include "EnemyTile.h"
#include "Characters.h"
#include "Chunk.h"
#include "Player.h"
#include "World.h"
#include "Tile.h"
#include "InputBindings.h"
#include "Consumable.h"

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

void TileMediator::pauseConsole() const
{
	std::cout << "Press enter to continue...";
	std::string x;
	std::getline(std::cin, x);
}

void TileMediator::printMap() const
{
	// Top Border
	print(CHARS::BORDER_TOP_LEFT);
	for (int i = 0; i < 2 * mapInradius + 1; i++) {
		print(CHARS::BORDER_HORIZONTAL);
	}
	print(CHARS::BORDER_TOP_RIGHT);
	print("\n");
	
	// For each row y
	for (int y = player.getY() - static_cast<int>(mapInradius); y <= player.getY() + static_cast<int>(mapInradius); y++) {
		print(CHARS::BORDER_VERTICAL);
		
		// print tiles and player
		// For each column x
		for (int x = player.getX() - static_cast<int>(mapInradius); x <= player.getX() + static_cast<int>(mapInradius); x++) {
			assert(world.getTile(x, y) != nullptr);
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
	
	// Bottom border
	print(CHARS::BORDER_BOTTOM_LEFT);
	for (int i = 0; i < 2 * mapInradius + 1; i++) {
		print(CHARS::BORDER_HORIZONTAL);
	}
	print(CHARS::BORDER_BOTTOM_RIGHT);
	print("\n");
}

void TileMediator::printInventory() const
{
	// Temp TODO
	std::cout << "Inventory\n";
	for (int i = 0; i < player.getInventorySize(); i++) {
		std::cout << (i + 1) << ": " << player.getInventoryItem(i)->getName() << std::endl;
	}
}

void TileMediator::printBattle(EnemyTile* tile) const
{
	assert(tile != nullptr);
	
	// Temp TODO
	print(tile->getName());
	print(": ");
	print(std::to_string(tile->getHp()));
	print("\nPlayer: ");
	print(std::to_string(player.getHp()));
	print("\n");
}

bool TileMediator::handleMovementInput()
{
	std::string inputStr;
	std::getline(std::cin, inputStr);
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

bool TileMediator::handleInventoryInput(const Consumable** itemUsed)
{
	if (itemUsed != nullptr)
		(*itemUsed) = nullptr;
	std::string input;
	std::getline(std::cin, input);
	int index = 0;
	try {
		int index = std::stoi(input);
	} catch (std::invalid_argument) {}
	// printInventory method shows items starting at index 1
	if (0 < index && index <= player.getInventorySize()) {
		index--;
		const Consumable* item = player.getInventoryItem(index);
		if (itemUsed != nullptr)
			(*itemUsed) = item;
		item->consume(player);
		player.removeItemFromInventory(index);
		return true;
	}
	
	// If no item was used, check if player is exiting inventory
	return bindings.checkInput(BINDINGS::EXIT_INVENTORY, &input[0]);
}

bool TileMediator::handleBattleInput(EnemyTile* tile)
{
	std::string inputStr;
	std::getline(std::cin, inputStr);
	const char* input = &inputStr[0];
	if (bindings.checkInput(BINDINGS::OPEN_INVENTORY, input)) {
		const Consumable* itemUsed;
		do {
			clearConsole();
			printInventory();
		} while (!handleInventoryInput(&itemUsed));
		
		if (itemUsed != nullptr) {
			clearConsole();
			std::string message = "Player consumed " + std::string(itemUsed->getName()) + "\n";
			print(message, DEFAULT_PRINT_SPEED);
			pauseConsole();
		}
		
		// Returns false if no item was used so that the player may choose to do something else
		return itemUsed != nullptr;
	} else if (bindings.checkInput(BINDINGS::ATTACK, input)) {
		int damage = player.computeAttackDamage();
		tile->changeHp(-1 * damage);
		clearConsole();
		std::string message = "Player damaged tile for " + std::to_string(damage) + " health\n";
		print(message, DEFAULT_PRINT_SPEED);
		pauseConsole();
		return true;
	} else if (bindings.checkInput(BINDINGS::RETREAT, input)) {
		do {
			clearConsole();
			printMap();
			print("Choose where to retreat\n");
		} while (!handleMovementInput());
		return true;
	}
	
	return false;
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

bool TileMediator::isPlayerAlive() const
{
	return (player.getHp() > 0);
}

void TileMediator::attackPlayer(int damage)
{
	// Apply player's shield
	damage = player.attack(damage);
	clearConsole();
	std::string message = "Player was attacked for " + std::to_string(damage) + " health\n";
	print(message, DEFAULT_PRINT_SPEED);
	pauseConsole();
}

void TileMediator::setCurrentTile(const Tile* prototype)
{
	assert(prototype != nullptr);
	world.setTile(player.getX(), player.getY(), prototype);
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
