#pragma once
#include <vector>
#include "Weapon.h"
class Shop
{
public:
	Shop();
	Shop(std::pair<int, int> potions, std::vector<std::pair<Weapon*, int>> weapons);
	std::pair<int, int> getPotions();
	std::vector<std::pair<Weapon*, int>> getWeapons();
	int potionsHeal = 10;
private:
	std::pair<int, int> potions; //first = stock, second = price
	std::vector<std::pair<Weapon*, int>> weapons; //first = weapon, second = price
};

