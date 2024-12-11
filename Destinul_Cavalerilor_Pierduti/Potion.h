#pragma once
#include "ShopItem.h"

class Potion : public ShopItem
{
public:
    Potion();
    Potion(int healthRegain, int stock, int price);
    void setHealthRegain(int healthRegain);
    int getHealthRegain() const;

private:
    int healthRegain;
};

