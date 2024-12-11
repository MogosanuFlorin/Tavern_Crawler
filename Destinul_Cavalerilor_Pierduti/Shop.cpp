#include "Shop.h"
#include <iostream>
#include <vector>
#include <string>
#include "Weapon.h"

Shop::Shop()
{
	items = {};
}

Shop::Shop(std::vector<ShopItem*> items)
{
	this->items = items;
}

std::vector<ShopItem*> Shop::getItems() const
{
	return items;
}
