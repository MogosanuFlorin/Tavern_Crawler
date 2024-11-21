#include "Enemy.h"

Enemy::Enemy()
{
	this->hp = 0;
	this->dmg = 0;
	this->goldDrop = 0;
}

Enemy::Enemy(int hp, int dmg, int gold)
{
	this->hp = hp;
	this->dmg = dmg;
	this->goldDrop = gold;
}

int Enemy::getHp() const
{
	return this->hp;
}

int Enemy::getDmg() const
{
	return this->dmg;
}

int Enemy::getGoldDrop() const
{
	return this->goldDrop;
}

void Enemy::setHp(int hp)
{
	this->hp = hp;
}

void Enemy::setDmg(int dmg)
{
	this->dmg = dmg;
}

void Enemy::setGoldDrop(int goldDrop)
{
	this->goldDrop = goldDrop;
}
