// Weapon.cpp
#include "Weapon.h"

Weapon::Weapon() : ShopItem(), damage(0), weaponName("") {}

Weapon::Weapon(std::string weaponName, int damage, int stock, int price)
    : ShopItem(stock, price), weaponName(weaponName), damage(damage) {
}

void Weapon::setWeaponName(std::string weaponName)
{
    this->weaponName = weaponName;
}

std::string Weapon::getWeaponName() const
{
    return this->weaponName;
}

void Weapon::setDamage(int damage)
{
    this->damage = damage;
}

int Weapon::getDamage() const
{
    return this->damage;
}