#include <iostream>
#include <vector>
#include "ShopAction.h"
#include "Shop.h"
#include "Player.h"
#include "Weapon.h"
#include "Display.h"

ShopAction::ShopAction(Shop* shop)
{
	this->shop = shop;
}

void ShopAction::execute(Node* node, Player* player)
{
	std::pair<int, int> potions = this->shop->getPotions();
	std::vector<std::pair<Weapon*, int>> weapons = this->shop->getWeapons();

	int choice = 1;
	while (choice != 0) {
		Display::clear();
		std::cout << "Gold: " << player->getGold() << std::endl;
		std::cout << "Your health: " << player->getHp() << std::endl;
		std::cout << "Your weapon damage: " << player->getDmg() << std::endl;
		std::cout << std::endl;
		std::cout << "Shop: " << std::endl;
		std::cout << "1: Potions: " << potions.first << " - " << potions.second << " gold/potion" << std::endl;
		std::cout << std::endl;
		
		int count = 2;
		if (weapons.size() == 0)
		{
			std::cout << "No weapons available." << std::endl;
			count = 0;
		}
		else{
			std::cout << "Weapons: " << std::endl;
			for (auto weapon : weapons)
			{
				if (weapon.second != 0)
				{
					std::cout << count << ": " << weapon.first->getWeaponName() << std::endl;
					std::cout << "Damage: " << weapon.first->getDamage() << std::endl;
					std::cout << "Price: " << weapon.second << std::endl;
					std::cout << std::endl;
					count++;
				}
			}
		}
		std::cout << "If you want to buy something, press the number of the item you want to buy. If you want to exit the shop, press 0." << std::endl;
		std::cin >> choice;
		if (choice < 0 || choice > weapons.size() + 1)
		{
			std::cout << "Invalid choice." << std::endl;
			Display::waitForKeyPress();
			continue;
		}
		if (choice == 0)
		{
			return;
		}
		else if (choice == 1)
		{
			if (player->getGold() < potions.second)
			{
				std::cout << "You don't have enough gold to buy a potion." << std::endl;
				Display::waitForKeyPress();
				continue;
			}
			std::cout << "You bought a potion!" << std::endl;
			player->setGold(player->getGold() - potions.second);
			potions.first--;

			player->setHp(player->getHp() + 10);
			if (player->getHp() > 100)
				player->setHp(100);
		}
		else
		{
			if (player->getGold() < weapons[choice - 2].second)
			{
				std::cout << "You don't have enough gold to buy a " << weapons[choice - 2].first->getWeaponName() << "." << std::endl;
				Display::waitForKeyPress();
				continue;
			}
			Weapon* weaponBought = weapons[choice - 2].first;
			std::cout << "You bought a " << weapons[choice - 2].first->getWeaponName() << "!" << std::endl;
			player->setGold(player->getGold() - weapons[choice - 2].second);
			weapons.erase(weapons.begin() + (choice - 2));
			if (weaponBought->getDamage() > player->getDmg())
			{
				player->setDmg(weaponBought->getDamage());
			}

		}
	}
}
