#pragma once

#include "Tile.h"
#include "TileMediator.h"

class EmptyTile : public Tile
{
public:
	virtual void update(TileMediator& mediator);
	
	virtual Tile* clone() const;
	
	virtual const char* getCharacter() const;
};
