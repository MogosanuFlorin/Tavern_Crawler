#include "Weapon.h"

Weapon::Weapon()
{
	this->damage = 0;
	this->weaponName = "";
}

Weapon::Weapon(std::string weaponName, int damage)
{
	this->damage = damage;
	this->weaponName = weaponName;
}

void Weapon::setWeaponName(std::string weaponName)
{
	this->weaponName = weaponName;
}

std::string Weapon::getWeaponName()
{
    return this->weaponName;
}

void Weapon::setDamage(int damage)
{
	this->damage = damage;
}

int Weapon::getDamage()
{
    return this->damage;
}
