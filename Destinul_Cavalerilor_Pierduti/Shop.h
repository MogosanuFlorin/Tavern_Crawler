#pragma once
#include <vector>
#include "Potion.h"
#include "Weapon.h"
#include "ShopItem.h"
class Shop
{
public:
	Shop();
	Shop(std::vector<ShopItem*> items);
	std::vector<ShopItem*>getItems() const;
private:
	std::vector<ShopItem*> items;
};

