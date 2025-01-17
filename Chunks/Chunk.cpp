#include "Chunk.h"

#include <cassert>
#include <iostream>

#include "Random.h"

Chunk::Chunk()
{
	// Does nothing, a subclass's constructor determines how to create the tiles array
}

Chunk::Chunk(const Chunk& rhs)
{
	copy(rhs);
}

Chunk::~Chunk()
{
	cleanup();
}

const Chunk& Chunk::operator=(const Chunk& rhs)
{
	if (this != &rhs) {
		cleanup();
		copy(rhs);
	}
	
	return *this;
}

Tile* Chunk::setTile(int x, int y, const Tile* prototype)
{
	assert(0 <= x && x < SIZE && 0 <= y && y < SIZE && prototype != nullptr);
	Tile* originalTile = tiles[x][y];
	tiles[x][y] = prototype->clone();
	
	// Tile is returned rather than deleted so that tiles can replace themselves on death.
	return originalTile;
}

Tile* Chunk::getTile(int x, int y) const
{
	assert(0 <= x && x < SIZE && 0 <= y && y < SIZE);
	return tiles[x][y];
}

int Chunk::posToChunkPos(int pos)
{
	if (pos >= 0) {
		return pos / SIZE;
	} else {
		return (pos + 1) / SIZE - 1;
	}
}

int Chunk::posToTilePos(int pos)
{
	if (pos >= 0) {
		return pos % SIZE;
	} else {
		// Tweaks are to ensure that -8 to -1 outputs 0 to 7, -16 to -9 outputs 0 to 7 and so forth.
		return SIZE - ((-1 * (pos + 1)) % SIZE) - 1;
	}
}

void Chunk::generate(const Tile** tilePrototypes, double* probabilities, int len)
{
	assert(tilePrototypes != nullptr && probabilities != nullptr);

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			double rand = MyToolkit::randomDouble();
			for (int k = 0; k < len; k++) {
				assert(tilePrototypes[k] != nullptr && probabilities[k] >= 0);
				if (rand <= probabilities[k]) {
					tiles[i][j] = tilePrototypes[k]->clone();
					break;
				} else {
					rand -= probabilities[k];
				}
				
				/* Due to potential rounding errors from floating point types, a tile is picked anyways
				// By the end of the list, a tile should have been choosen.
				// If the assert fails, than the sum of the probabilities is less than 1
				assert(k != len - 1);
				*/
				tiles[i][j] = tilePrototypes[k]->clone();
			}
		}
	}
}

void Chunk::cleanup()
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			delete tiles[i][j];
			tiles[i][j] = nullptr;
		}
	}
}

void Chunk::copy(const Chunk& chunk)
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			assert(tiles[i][j] == nullptr);
			tiles[i][j] = chunk.tiles[i][j]->clone();
		}
	}
}
