#include "World.h"

#include <iterator>
#include <cassert>

#include "Chunk.h"
#include "AbandonedTownChunk.h"

World::World()
{
}

World::World(const World& rhs)
{
	copy(rhs);
}

World::~World()
{
	cleanup();
}

const World& World::operator=(const World& rhs)
{
	if (&rhs != this) {
		cleanup();
		copy(rhs);
	}
	
	return *this;
}

Chunk* World::getChunk(int x, int y)
{
	std::pair<int, int> key(x, y);
	if (chunks.find(key) == chunks.end()) {
		createChunk(x, y);
	}

	return chunks[key];	
}

Tile* World::getTile(int x, int y)
{
	int chunkX = Chunk::posToChunkPos(x);
	int chunkY = Chunk::posToChunkPos(y);
	int tileX = Chunk::posToTilePos(x);
	int tileY = Chunk::posToTilePos(y);
	Chunk* chunk = getChunk(chunkX, chunkY);
	return chunk->getTile(tileX, tileY);
}

void World::createChunk(int x, int y)
{
	std::pair<int, int> key(x, y);
	assert(chunks.find(key) == chunks.end());

	Chunk* value = new AbandonedTownChunk;
	chunks.insert(std::make_pair(key, value));
}

void World::cleanup()
{
	// World stores pointers to chunks, so each chunk needs to be deleted
	for (auto it = chunks.begin(); it != chunks.end(); it++) {
		delete it->second;
	}
	
	chunks.clear();
}

void World::copy(const World& world)
{
	assert(chunks.empty());

	for (auto it = world.chunks.begin(); it != world.chunks.end(); it++) {
		chunks.insert(std::make_pair(it->first, it->second->clone()));
	}
}
