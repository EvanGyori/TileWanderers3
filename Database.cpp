#include "Database.h"

#include "Tile.h"
#include "EmptyTile.h"
#include "Item.h"
#include "Weapon.h"

#include <cassert>

Database* Database::instance = nullptr;

Database& Database::getInstance()
{
	if (!instance) {
		instance = new Database;
	}

	return *instance;
}

const Tile* Database::getTile(TILES id) const
{
	assert(id != TILES::COUNT);
	return tiles[static_cast<int>(id)];
}

const Item* Database::getItem(ITEMS id) const
{
	assert(id != ITEMS::COUNT);
	return items[static_cast<int>(id)];
}

Database::Database()
{
	createTiles();
	createItems();
}

Database::Database(const Database&)
{
	// Never called, singleton
}

Database::~Database()
{
	// Never called, singleton
}

void Database::createTiles()
{
	addTile(TILES::EMPTY, new EmptyTile);
}

void Database::createItems()
{
	addItem(ITEMS::SWORD, new Weapon("Sword", 1, 0.5, 2.));
}

void Database::addTile(TILES id, Tile* tile)
{
	assert(id != TILES::COUNT);
	tiles[static_cast<int>(id)] = tile;
}

void Database::addItem(ITEMS id, Item* item)
{
	assert(id != ITEMS::COUNT);
	items[static_cast<int>(id)] = item;
}
