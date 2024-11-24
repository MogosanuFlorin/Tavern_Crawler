#pragma once
#include <unordered_map>
#include <string>
class Node;
class Player;
class Game
{
public:
	Game();
	void run();
private:
	Player* player;
	Node* currentNode;
	Node* getStartNode();
	std::unordered_map<std::string, Node*> nodes;
};

