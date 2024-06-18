#include "EmptyTile.h"

#include "Characters.h"

void EmptyTile::update(TileMediator& mediator)
{
	handleMapUpdate(mediator);
}

Tile* EmptyTile::clone() const
{
	return new EmptyTile;
}

const char* EmptyTile::getCharacter() const
{
	return CHARS::EMPTY_TILE;
}
