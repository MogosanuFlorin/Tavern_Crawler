#include "Shop.h"
#include <iostream>
#include <vector>
#include <string>
#include "Weapon.h"

Shop::Shop()
{
	this->potions = std::make_pair(0, 0);
	this->weapons = std::vector<std::pair<Weapon*, int>>();
}

Shop::Shop(std::pair<int, int> potions, std::vector<std::pair<Weapon*, int>> weapons)
{
	this->potions = potions;
	this->weapons = weapons;
}

std::pair<int, int> Shop::getPotions()
{
	return this->potions;
}

std::vector<std::pair<Weapon*, int>> Shop::getWeapons()
{
	return this->weapons;
}
