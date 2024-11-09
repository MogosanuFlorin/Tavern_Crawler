#include <iostream>
#include "caracter.h"

caracter::caracter()
{
	this->hp = 100;
	this->gold = 0;
	this->damage = 5;
}

void caracter::setHp(int hp)
{
	this->hp = hp;
}

void caracter::loseHp(int dmg)
{
	this->hp -= dmg;
}

void caracter::addGold(int gold)
{
	this->gold += gold;
}