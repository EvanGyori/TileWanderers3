/*
 The Chunk class handles tile storage and creation for a fixed size (Chunk::SIZE) square.
 Each Chunk subclass determines how the tiles are created and the type name.
 
 To create a new chunk type, create a subclass of Chunk and override the pure virtual functions to determine the name.
 In the subclass's constructor, call the generate method to determine which tiles to create and their probabilities.
*/

#pragma once

#include "Tile.h"

class Chunk
{
public:
	// The number of tiles that a chunk is wide and tall
	static constexpr int SIZE = 8;
	
	Chunk();
	Chunk(const Chunk&);
	
	virtual ~Chunk();
	
	const Chunk& operator=(const Chunk&);
	
	// Returns a copy of this object
	virtual Chunk* clone() const = 0;
	
	// Sets the tile at (x, y) to a copy of the specified tile
	// The pointer must not be null and should be a prototype as it is cloned
	void setTile(int x, int y, const Tile* tile, bool deletePreviousTile);
	
	// Returns the name of the type of chunk. Each Chunk subclass has its own name.
	virtual const char* getName() const = 0;
	
	// Returns the tile at (x, y)
	// 0 <= x, y < Chunk::size
	Tile* getTile(int x, int y) const;
	
	// Converts a world position into the coordinate of the chunk that is at that spot
	static int posToChunkPos(int pos);
	
	// Converts a world position to the coordinate of the tile relative to the chunk at that spot
	static int posToTilePos(int pos);
	
protected:
	// Generates the tiles array using the given tiles with their associated probabilities
	// The sum of all the probabilities must be equal to one and none should be negative
	void generate(const Tile** tilePrototypes, double* probabilities, int len);
	
private:
	Tile* tiles[SIZE][SIZE];
	
	// Deletes the tiles
	void cleanup();
	
	// Copies the tiles from the given chunk into this
	void copy(const Chunk&);
};
