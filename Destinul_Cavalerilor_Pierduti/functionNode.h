#pragma once
#include <string>
#include "storyNode.h"
#include "caracter.h"
using namespace std;

class functionNode
{
public:
	functionNode();
	void setFunction1(storyNode*, caracter*, int, int);
	void callFunction();
	void combat();
	void getGold();
	string story;
	storyNode* nextNode;
	int functionID;
	caracter* player;
	int enemyHp;
	int enemyDmg;

	

};