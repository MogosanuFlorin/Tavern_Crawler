#include "Game.h"
#include "Player.h"
#include "Node.h"
#include "Enemy.h"
#include "Display.h"
#include "GetGoldAction.h"
#include "CombatAction.h"
#include "ShopAction.h"
#include "ShopItem.h"
#include "Shop.h"
#include "Weapon.h"
#include "Potion.h"
#include "LoseAllMoneyAction.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>

Game::Game()
{
	this->player = new Player();
	loadEnemies();
	loadWeapons();
	loadShops();
	this->currentNode = getStartNode();
}

void Game::run()
{
    /*std::cout << currentNode->printStory();
	Display::waitForKeyPress();*/
	while (currentNode && player->getHp() > 0) {
		int choice = currentNode->printStory();

		currentNode->callAction(player);

		currentNode = currentNode->getNextNode(choice);
	}

	Display::clear();
	if (player->getHp() <= 0) {
		std::cout << "You have perished. Game Over!\n";
	}
	else {
		std::cout << "Your adventure has ended. Thank you for playing!\n";
	}
}

Node* Game::getStartNode()
{
    std::ifstream file("demo.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << "story.txt" << std::endl;
        return nullptr;
    }
    std::cout << "File opened" << std::endl;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string nodeName, leftChildName, rightChildName, actionName;
        std::vector<std::string> options;
        std::string option;
        int gold;

        if (!(iss >> nodeName >> leftChildName >> rightChildName >> actionName)) {
            continue;
        }

        std::string story;
        std::string storyLine;
        while (std::getline(file, storyLine) && storyLine != "end") {
            story += storyLine + "\n";
        }

        while (std::getline(file, option) && !option.empty()) {
            options.push_back(option);
        }

        Node* node = nullptr;
        if (nodes.find(nodeName) == nodes.end()) {
            node = new Node();
            nodes[nodeName] = node;
        }
        else {
            node = nodes[nodeName];
        }

        if (!leftChildName.empty() && nodes.find(leftChildName) == nodes.end() && leftChildName != "null") {
            nodes[leftChildName] = new Node();
        }
        if (!rightChildName.empty() && nodes.find(rightChildName) == nodes.end() && rightChildName != "null") {
            nodes[rightChildName] = new Node();
        }

        node->setStory(story, options, {
            leftChildName == "null" ? nullptr : nodes[leftChildName],
            rightChildName == "null" ? nullptr : nodes[rightChildName]
            });

        if (!actionName.empty() && actionName != "null") {
			if (actionName == "GetGoldAction") {
				node->setAction(new GetGoldAction(20));
			}
			else if (actionName == "CombatAction") {
				node->setAction(new CombatAction(this->enemies[nodeName]));
			}
			else if (actionName == "ShopAction") {
				node->setAction(new ShopAction(this->shops[nodeName]));
			}
            else if (actionName == "LoseAllMoneyAction") {
				node->setAction(new LoseAllMoneyAction());
            }
        }

        /*std::cout << "Created node: " << nodeName << std::endl;
        std::cout << "Story: " << story << std::endl;
        std::cout << "Options: ";
        for (const auto& opt : options) {
            std::cout << opt << " ";
        }
        std::cout << std::endl;
        std::cout << "Left Child: " << leftChildName << ", Right Child: " << rightChildName << std::endl;
        Display::waitForKeyPress();*/
    }
    file.close();
    return nodes.empty() ? nullptr : nodes["start"];
	
    
}

void Game::loadEnemies() {
    std::ifstream file("enemies.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << "enemies.txt" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string enemyName;
        int hp, dmg, goldDrop;
        if (!(iss >> enemyName >> hp >> dmg >> goldDrop)) {
            continue;
        }
        enemies[enemyName] = new Enemy(hp, dmg, goldDrop);

		/*std::cout << "Created enemy: " << enemyName << std::endl;
		std::cout << "HP: " << hp << ", Damage: " << dmg << ", Gold Drop: " << goldDrop << std::endl;
		Display::waitForKeyPress();*/
    }
    file.close();
}

void Game::loadShops()
{
    std::ifstream file("shop.txt");
	if (!file.is_open()) {
		std::cerr << "Failed to open file: " << "shop.txt" << std::endl;
		Display::waitForKeyPress();
		return;
	}
	std::string line;
    while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string shopName;
		int potionsStock, potionsPrice, potionHeal;
        std::vector<ShopItem*> shopItems;
		std::string weaponName;
		if (!(iss >> shopName >> potionsStock >> potionsPrice >> potionHeal)) continue;
		Potion* potions = new Potion(potionHeal, potionsStock, potionsPrice);
		shopItems.push_back(potions);
        while (std::getline(file, line) && !line.empty()) {
            int price;
            std::istringstream iss(line);
			if (!(iss >> weaponName >> price)) continue;
            weapons[weaponName]->setPrice(price);
			shopItems.push_back(weapons[weaponName]);
        }

		this->shops[shopName] = new Shop(shopItems);
        
		/*std::cout << "Created shop: " << shopName << std::endl;
		std::cout << "Potions: " << potionsStock << " - " << potionsPrice << " gold/potion" << std::endl;
		std::cout << "Weapons: " << std::endl;
        for (auto weapon : weapons) {
			std::cout << weapon.first->getWeaponName() << " - " << weapon.second << " gold" << std::endl;
        }
		Display::waitForKeyPress();*/

    }
    file.close();
}

void Game::loadWeapons()
{
    std::ifstream file("weapon.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << "enemies.txt" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
		std::string weaponName;
		int damage;
        if (!(iss >> weaponName >> damage)) {
            continue;
        }
		weapons[weaponName] = new Weapon(weaponName, damage, 1, 0);

		/*std::cout << "Created weapon: " << weaponName << std::endl;
		std::cout << "Damage: " << damage << std::endl;
		Display::waitForKeyPress();*/
    }
    file.close();
}
