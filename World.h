/*
 The World class handles Chunk storage and creation.
 
 When a new Chunk type is created, to have the chunk naturally appear: refer to createChunk method TODO
*/

#pragma once

#include <unordered_map>
#include <utility>

#include "Chunk.h"
#include "PairHash.h"

class World
{
public:
	World();
	World(const World&);

	~World();
	
	const World& operator=(const World&);
	
	// Returns the chunk at (x, y) in chunk coordinates. If there is no chunk, one is created.
	Chunk* getChunk(int x, int y);
	
	// Returns the tile at (x, y) in world coordinates. If there is no chunk at the spot, one is created.
	Tile* getTile(int x, int y);
	
private:
	std::unordered_map<std::pair<int, int>, Chunk*, MyToolkit::IntegerPairHash> chunks;
	
	/*
	 Creates a random chunk at the location.
	 There must be no chunk already created at the location
	 otherwise the operation is invalid.
	*/
	void createChunk(int x, int y);
	
	// Deletes all chunks stored in this
	void cleanup();
	
	/*
	 Copies the specified world data into this.
	 If this has any chunks, call cleanup beforehand to prevent memory leaks.
	 chunks must be empty otherwise the operation is invalid.
	*/
	void copy(const World&);
};
