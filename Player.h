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
	
	void changeHp(int deltaHp);
	void changeX(int deltaX);
	void changeY(int deltaY);
	
	/*
	 Damages this player taking into account the shield.
	 Returns the resulting damage.
	*/
	int attack(int damage);
	
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
	
	/*
	 Returns damage as determined by weapon.
	 Returns zero if the player has no weapon.
	*/
	int computeAttackDamage() const;
	
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
