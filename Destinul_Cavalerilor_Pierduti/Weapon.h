#pragma once
#include <string>
#include "ShopItem.h"
class Weapon : public ShopItem
{
public:
    Weapon();
    Weapon(std::string weaponName, int damage, int stock, int price);
    void setWeaponName(std::string weaponName);
    std::string getWeaponName() const;
    void setDamage(int damage);
    int getDamage() const;

private:
    std::string weaponName;
    int damage;
};

