#include "Player.h"

#include <cassert>

#include "Chunk.h"
#include "Consumable.h"
#include "Weapon.h"
#include "Shield.h"

Player::Player(int x, int y) :
	x(x), y(y),
	sightRadius(2),
	maxHp(100),
	hp(100),
	gold(0),
	weapon(nullptr),
	shield(nullptr)
{
}

void Player::changeHp(int deltaHp)
{
	hp += deltaHp;
}

void Player::changeX(int deltaX)
{
	x += deltaX;
}

void Player::changeY(int deltaY)
{
	y += deltaY;
}

int Player::attack(int damage)
{
	if (shield != nullptr) {
		damage = shield->computeDamageReceived(damage);
	}
	
	changeHp(-1 * damage);
	return damage;
}

void Player::addItemToInventory(const Consumable* item)
{
	inventory.push_back(item);
}

void Player::removeItemFromInventory(unsigned int index)
{
	inventory.erase(inventory.begin() + index);
}

void Player::setWeapon(const Weapon* weapon)
{
	assert(weapon != nullptr);
	this->weapon = weapon;
}

void Player::setShield(const Shield* shield)
{
	assert(shield != nullptr);
	this->shield = shield;
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

int Player::computeAttackDamage() const
{
	return (weapon != nullptr) ? weapon->computeDamage() : 0;
}

const Consumable* Player::getInventoryItem(unsigned int index) const
{
	assert(index < getInventorySize());
	return inventory[index];
}

int Player::getInventorySize() const
{
	return inventory.size();
}

const Weapon* Player::getWeapon() const
{
	return weapon;
}

const Shield* Player::getShield() const
{
	return shield;
}
