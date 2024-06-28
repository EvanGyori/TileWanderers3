#include "AbandonedTownChunk.h"

#include <iostream>

#include "Tile.h"
#include "EmptyTile.h"
#include "Database.h"

AbandonedTownChunk::AbandonedTownChunk()
{
	// Temp - creates a chunk full of empty tiles
	Database& database = Database::getInstance();
	const Tile* tiles[] = { database.getTile(TILES::EMPTY), database.getTile(TILES::ENEMY) };
	
	double probabilities[] = {0.8, 0.2};
	Chunk::generate(tiles, probabilities, 2);
}

AbandonedTownChunk::AbandonedTownChunk(const Chunk& rhs) : Chunk(rhs)
{
}

Chunk* AbandonedTownChunk::clone() const
{
	return new AbandonedTownChunk(*this);
}

const char* AbandonedTownChunk::getName() const
{
	return "Abandoned Town";
}
