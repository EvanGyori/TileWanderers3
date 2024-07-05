#include "Tile.h"

Tile::Tile() :
	hidden(true)
{
}

Tile::~Tile()
{
}

void Tile::reveal()
{
	hidden = false;
}

bool Tile::isHidden() const
{
	return hidden;
}

void Tile::handleMapUpdate(TileMediator& mediator)
{
	do {
		mediator.clearConsole();
		mediator.printMap();
	} while (!mediator.handleMovementInput(true));
}
