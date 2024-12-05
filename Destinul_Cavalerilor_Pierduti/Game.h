#pragma once
#include <unordered_map>
#include <string>
#include "Node.h"
#include "Player.h"
#include "Enemy.h"
#include "Shop.h"
#include "Weapon.h"
class Game
{
public:
	Game();
	void run();
private:
	Player* player;
	Node* currentNode;
	Node* getStartNode();
	void loadEnemies();
	void loadShops();
	void loadWeapons();
	std::unordered_map<std::string, Node*> nodes;
	std::unordered_map<std::string, Enemy*> enemies;
	std::unordered_map<std::string, Shop*> shops;
	std::unordered_map<std::string, Weapon*> weapons;
};

