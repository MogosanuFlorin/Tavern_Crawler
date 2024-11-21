#pragma once
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
};

