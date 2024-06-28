/*
 The Database class is a singleton that contains the prototypes used for
 tile and item instantiation.
 
 The TILES and ITEMS enum contain the identifiers for each prototype.
 DO NOT use the COUNT enumeration in each of the enums except when getting
 the number of prototypes.
 
 To instantiate a Tile, retrieve the prototype from the getTile method
 with the appropiate id and call its clone method.
 
 Items do not need to be instantiated. Instead, a pointer to its single
 instance is passed around.
 
 To create a new tile prototype:
 	Create an id in the TILES enum before COUNT,
 	in the private method createTiles, add an addTile statement for the new tile like so:
	addTile(TILES::ID, new AnySubclassOfTile);
	The tile wont occur naturally until it is added to a chunk, refer to the Chunk class header.
	
 To create a new item prototype:
 	Create an id in the ITEMS enum before COUNT,
	in the private method createItems, add an addItem statement for the new item like so:
	addItem(ITEMS::ID, new AnySubclassOfItem);
	The item wont occur naturally until it is added to a tile
	
 For more options and creating new Tile and Item types, a subclass would need to be made.
 Refer to the Tile and Item class headers.
*/

#pragma once

#include "Tile.h"
#include "Item.h"

enum class TILES
{
	EMPTY,
	ENEMY,
	COUNT // Do not use
};

enum class ITEMS
{
	SWORD,
	COUNT // Do not use
};

class Database
{
public:
	// Returns the single instance of Database since it is a singleton
	static Database& getInstance();
	
	/*
	 Returns the prototype tile associated with the id.
	 Using TILES::COUNT is invalid.
	*/
	const Tile* getTile(TILES id) const;
	
	/*
	 Returns the prototype item associated with the id.
	 Using ITEMS::COUNT is invalid
	*/
	const Item* getItem(ITEMS id) const;

private:
	static Database* instance;
	Tile* tiles[static_cast<int>(TILES::COUNT)];
	Item* items[static_cast<int>(ITEMS::COUNT)];
	
	// Hide constructor, copy constructor, and destructor from client to create singleton
	Database();
	
	// Do not use, is hidden from client
	Database(const Database&);
	~Database();
	
	// Instantiates prototypes
	void createTiles();
	void createItems();
	
	// Shorthand for adding prototype to array
	void addTile(TILES id, Tile* tile);
	void addItem(ITEMS id, Item* item);
};
