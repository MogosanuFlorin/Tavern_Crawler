#include <iostream>
#include <vector>
#include "ShopAction.h"
#include "Shop.h"
#include "Player.h"
#include "Weapon.h"
#include "ShopItem.h"
#include "Potion.h"
#include "Display.h"

ShopAction::ShopAction(Shop* shop)
{
	this->shop = shop;
}

void ShopAction::execute(Node* node, Player* player)
{
	
	std::vector<ShopItem*> shopItems = shop->getItems();
	Potion* potions = dynamic_cast<Potion*>(shopItems[0]);
	int choice = 1;
	while (choice != 0) {
		Display::clear();
		std::cout << "Gold: " << player->getGold() << std::endl;
		std::cout << "Your health: " << player->getHp() << std::endl;
		std::cout << "Your weapon damage: " << player->getDmg() << std::endl;
		std::cout << std::endl;
		std::cout << "Shop: " << std::endl;
		std::cout << "1: Potions: Stock: " << potions->getStock() << " Price: " << potions->getPrice() << " Heal: " << potions->getHealthRegain() << std::endl;
		std::cout << std::endl;
		
		int count = 2;
		if (shopItems.size() == 1)
		{
			std::cout << "No weapons available." << std::endl;
			count = 0;
		}
		else{
			std::cout << "Weapons: " << std::endl;
			std::cout << std::endl;
			for (int i=1; i<shopItems.size(); i++)
			{
				Weapon* weapon = dynamic_cast<Weapon*>(shopItems[i]);
				if (weapon->getStock() != 0)
				{
					std::cout << count << ": " << weapon->getWeaponName() << std::endl;
					std::cout << "Damage: " << weapon->getDamage() << std::endl;
					std::cout << "Price: " << weapon->getPrice() << std::endl;
					std::cout << std::endl;
					count++;
				}
			}
		}
		std::cout << "If you want to buy something, press the number of the item you want to buy. If you want to exit the shop, press 0." << std::endl;
		std::cin >> choice;
		if (choice < 0 || choice > shopItems.size())
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
			if (player->getGold() < potions->getPrice())
			{
				std::cout << "You don't have enough gold to buy a potion." << std::endl;
				Display::waitForKeyPress();
				continue;
			}
			std::cout << "You bought a potion!" << std::endl;
			player->setGold(player->getGold() - potions->getPrice());
			potions->setStock(potions->getStock() - 1);

			player->setHp(player->getHp() + potions->getHealthRegain());
			if (player->getHp() > 100)
				player->setHp(100);
		}
		else
		{
			Weapon* weapon = dynamic_cast<Weapon*>(shopItems[choice-1]);
			if (player->getGold() < weapon->getPrice())
			{
				std::cout << "You don't have enough gold to buy a " << weapon->getWeaponName() << "." << std::endl;
				Display::waitForKeyPress();
				continue;
			}
			std::cout << "You bought a " << weapon->getWeaponName() << "!" << std::endl;
			player->setGold(player->getGold() - weapon->getPrice());
			if (weapon->getDamage() > player->getDmg())
			{
				player->setDmg(weapon->getDamage());
			}
			shopItems.erase(shopItems.begin() + (choice - 1));
			

		}
	}
}
