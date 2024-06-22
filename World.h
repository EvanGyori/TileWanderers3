/*
 The World class handles Chunk storage and creation.
 
 When a new Chunk type is created, to have the chunk naturally appear: refer to createChunk method TODO
*/

#pragma once

#include <unordered_map>
#include <utility>
#include <stack>

#include "Chunk.h"
#include "PairHash.h"

class World
{
public:
	/*
	 Default Constructor
	 Initializes an empty world
	*/
	World();
	World(const World&);

	~World();
	
	const World& operator=(const World&);
	
	// sets the tile at (x, y) in world coordinates to a copy of prototype
	// Call cleanupReplacedTiles() to deallocate memory for replaced tiles
	
	/*
	 Sets the tile at (x, y) in world coordinates to a copy of prototype.
	 The tile at the location is not deleted automatically. Call cleanupReplacedTiles to delete it.
	 If no chunk is at the location, one is created.
	 
	 prototype must not be nullptr
	*/
	void setTile(int x, int y, const Tile* prototype);
	
	/*
	 Deallocates tiles that are no longer stored in any chunk.
	 Since tiles replace themselves within their own methods on tile death,
	 cleanupReplacedTiles needs to be called outside of their method.
	*/
	void cleanupReplacedTiles();
	
	/*
	 Returns the chunk at (x, y) in chunk coordinates.
	 If there is no chunk, one is created.
	*/
	Chunk* getChunk(int x, int y);
	
	// Returns the tile at (x, y) in world coordinates. If there is no chunk at the spot, one is created.
	Tile* getTile(int x, int y);
	
private:
	std::unordered_map<std::pair<int, int>, Chunk*, MyToolkit::IntegerPairHash> chunks;
	std::stack<Tile*> replacedTiles;
	
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
