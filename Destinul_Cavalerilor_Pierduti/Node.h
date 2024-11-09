#pragma once
#include "caracter.h"
class Node
{
public:
	Node();
	void setStory(std::string story, std::string option1, std::string option2, Node* nextNode1, Node* nextNode2);
	void setCombat(int enemyHp, int enemyDmg, caracter* player, Node* nextNode1);
	void setGetGold(int gold, caracter* player, Node* nextNode1);
	void callFunction();
	int printStory() const;
	int getFunctionID() { return this->fuctionID; }
	Node* getNextNode(int id);
private:
	std::string story;
	std::string option1;
	std::string option2;
	int fuctionID;
	int enemyHp;
	int enemyDmg;
	int gold;
	Node* nextNode1;
	Node* nextNode2;
	caracter* player;
	void getGold();
	void combat();
};

