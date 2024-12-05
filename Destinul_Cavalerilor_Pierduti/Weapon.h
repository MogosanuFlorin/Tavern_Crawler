#pragma once
#include <string>
class Weapon
{
public:
	Weapon();
	Weapon(std::string weaponName, int damage);
	void setWeaponName(std::string weaponName);
	std::string getWeaponName();
	void setDamage(int damage);
	int getDamage();

private:
	std::string weaponName;
	int damage;
};

