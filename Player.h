/*
 The Player class stores the player's information such as position, inventory, and etc.
*/

#pragma once

#include "Item.h"
#include "Weapon.h"
#include "Shield.h"

class Item;
class Weapon;
class Shield;

class Player
{
public:
	static constexpr unsigned int INVENTORY_SIZE = 10;

	Player(int x, int y);
	
	void changeX(int deltaX);
	void changeY(int deltaY);
	
	void setWeapon(const Weapon*);
	void setShield(const Shield*);
	
	// Returns world coordinates of the player's position
	int getX() const;
	int getY() const;
	
	unsigned int getSightRadius() const;
	
	int getMaxHp() const;
	int getHp() const;
	
	unsigned int getGold() const;
	
	const Item* getInventoryItem(unsigned int index) const;
	
private:
	int x, y;
	unsigned int sightRadius;
	int maxHp;
	int hp;
	unsigned int gold;
	
	const Item* inventory[INVENTORY_SIZE];
	const Weapon* weapon;
	const Shield* shield;
};
