/*
 The Player class stores the player's information such as position, inventory, and etc.
*/

#pragma once

#include <vector>

#include "Consumable.h"
#include "Weapon.h"
#include "Shield.h"

class Item;
class Weapon;
class Shield;

class Player
{
public:
	Player(int x, int y);
	
	void changeX(int deltaX);
	void changeY(int deltaY);
	
	// Appends a consumable item to the inventory list
	void addItemToInventory(const Consumable*);
	
	void removeItemFromInventory(unsigned int index);
	
	void setWeapon(const Weapon*);
	void setShield(const Shield*);
	
	// Returns world coordinates of the player's position
	int getX() const;
	int getY() const;
	
	unsigned int getSightRadius() const;
	
	int getMaxHp() const;
	int getHp() const;
	
	unsigned int getGold() const;
	
	const Consumable* getInventoryItem(unsigned int index) const;
	int getInventorySize() const;
	const Weapon* getWeapon() const;
	const Shield* getShield() const;
	
private:
	int x, y;
	unsigned int sightRadius;
	int maxHp;
	int hp;
	unsigned int gold;
	
	std::vector<const Consumable*> inventory;
	const Weapon* weapon;
	const Shield* shield;
};
