#include "Potion.h"

Potion::Potion() : ShopItem(), healthRegain(0) {}

Potion::Potion(int healthRegain, int stock, int price)
    : ShopItem(stock, price), healthRegain(healthRegain) {
}

void Potion::setHealthRegain(int healthRegain)
{
    this->healthRegain = healthRegain;
}

int Potion::getHealthRegain() const
{
    return this->healthRegain;
}