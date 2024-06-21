#include "AbandonedTownChunk.h"

#include <iostream>

#include "Tile.h"
#include "EmptyTile.h"
#include "Database.h"

AbandonedTownChunk::AbandonedTownChunk()
{
	// Temp - creates a chunk full of empty tiles
	const Tile* tiles[] = { Database::getInstance().getTile(TILES::EMPTY) };
	
	double probabilities[] = {1.};
	Chunk::generate(tiles, probabilities, 1);
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
