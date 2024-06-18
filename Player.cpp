#include "Player.h"

#include <cassert>

#include "Chunk.h"
#include "Item.h"

Player::Player(int x, int y) :
	x(x), y(y),
	sightRadius(2),
	maxHp(100),
	hp(100),
	gold(0),
	weapon(nullptr)
{
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		inventory[i] = nullptr;
	}
}

void Player::changeX(int deltaX) {
	x += deltaX;
}

void Player::changeY(int deltaY) {
	y += deltaY;
}

void Player::setWeapon(const Weapon* weapon)
{
	assert(weapon != nullptr);
	this->weapon = weapon;
}

int Player::getX() const
{
	return x;
}

int Player::getY() const
{
	return y;
}

unsigned int Player::getSightRadius() const
{
	return sightRadius;
}

int Player::getMaxHp() const
{
	return maxHp;
}

int Player::getHp() const
{
	return hp;
}

unsigned int Player::getGold() const
{
	return gold;
}

const Item* Player::getInventoryItem(unsigned int index) const
{
	assert(index < INVENTORY_SIZE);
	return inventory[index];
}
