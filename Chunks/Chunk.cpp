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

void Chunk::setTile(int x, int y, Tile* tile)
{
	assert(0 <= x && x < SIZE && 0 <= y && y < SIZE && tile != nullptr);
	delete tiles[x][y];
	tiles[x][y] = tile;
}

Tile* Chunk::getTile(int x, int y) const
{
	assert(0 <= x && x < SIZE && 0 <= y && y < SIZE);
	return tiles[x][y];
}

void Chunk::generate(Tile** tilePrototypes, double* probabilities, int len)
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			double rand = MyToolkit::randomDouble();
			for (int k = 0; k < len; k++) {
				if (rand <= probabilities[k]) {
					tiles[i][j] = tilePrototypes[k]->clone();
					break;
				} else {
					rand -= probabilities[k];
				}
				
				// By the end of the list, a tile should have been choosen.
				// If the assert fails, than the sum of the probabilities is less than 1
				assert(k != len - 1);
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
