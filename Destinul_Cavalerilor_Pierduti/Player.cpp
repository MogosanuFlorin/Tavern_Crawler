#include "Player.h"


Player::Player()
{
	this->hp = 100;
	this->gold = 0;
	this->damage = 5;
}

void Player::setHp(int hp)
{
	this->hp = hp;
}

void Player::loseHp(int dmg)
{
	this->hp -= dmg;
}

void Player::addGold(int gold)
{
	this->gold += gold;
}