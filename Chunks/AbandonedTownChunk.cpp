#include "AbandonedTownChunk.h"

#include <iostream>

#include "Tile.h"
#include "EmptyTile.h"

AbandonedTownChunk::AbandonedTownChunk()
{
	// Temp - creates a chunk full of empty tiles
	Tile* tiles[] = { new EmptyTile };
	double probabilities[] = {1};
	Chunk::generate(tiles, probabilities, 1);
	delete tiles[0];
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
