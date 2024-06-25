/*
 The Tile base abstract data type contains the generic methods for each subclass.
 
 To create a new tile prototype, refer to the Database class header.
 
 To create a new tile type, create a subclass of tile and implement the pure virtual functions.
 The tile handles the majority of the gameplay loop, so there is lots of freedom to be had.
 The TileMediator methods allow for the tile to interact with other objects
*/

#pragma once

#include "TileMediator.h"

class Tile
{
public:
	Tile();

	virtual ~Tile();

	/*
	 Handles gameplay loop. Run for the current tile on a loop.
	 Make sure that any tile ends the method by moving the player
	 to a seperate tile or changing the current tile so that no infinite loops occur.
	*/
	virtual void update(TileMediator& mediator) = 0;
	
	/*
	 Returns a pointer to a copy of this tile.
	 For instantiating a copy of a prototype
	*/
	virtual Tile* clone() const = 0;
	
	// Marks the tile to be visible when printed onto the map
	void reveal();
	
	// Returns the tile's unicode character to be printed to the map
	virtual const char* getCharacter() const = 0;
	
	// Returns true if the tile should not be shown on the map
	bool isHidden() const;
	
protected:
	// Prints the map and prompts the player for movement or inventory input
	void handleMapUpdate(TileMediator& mediator);
	
private:
	bool hidden;
};
