#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "functionNode.h"
#include "storyNode.h"
#include "caracter.h"
using namespace std;

void clear() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

functionNode::functionNode()
{
	this->story = "";
	this->nextNode = NULL;
	this->functionID = 0;
	this->player = NULL;
	this->enemyHp = 0;
	this->enemyDmg = 0;
}

void functionNode::setFunction1(storyNode* nextNode, caracter* player, int enemyHp, int enemyDmg)
{
	this->functionID = 1;
	this->nextNode = nextNode;
	this->player = player;
	this->enemyHp = enemyHp;
	this->enemyDmg = enemyDmg;
}

void functionNode::callFunction()
{
	if (this->functionID == 1)
	{
		combat();
	}
	else if (this->functionID == 2)
	{
		getGold();
	}
}

void functionNode::combat()
{
	int viataPlayer = this->player->getHp();
	int dmgPlayer = this->player->getDmg();
	srand(static_cast<unsigned int>(time(0))); //seed random number generator
	while (viataPlayer > 0 && this->enemyHp > 0)
	{
		clear();
		string s = "";
		s += "Your HP: " + to_string(viataPlayer) + "												Enemy HP: " + to_string(this->enemyHp);
		cout << s << endl;
		s = "Choose your attack:\n1. Rock\n2. Paper\n3. Scissors\nChoose an option: ";
		int choice;
		cin >> choice;

		int enemyChoice = rand() % 3 + 1;

		if (choice == 1)
			if (enemyChoice == 1) {
				s = "You chose Rock.\nEnemy chose Rock.\nEnemy strikes, but you blocked";
			}
			else if (enemyChoice == 2) {
				s = "You chose Rock.\nEnemy chose Paper.\nEnemy strikes\n You lose " + to_string(this->enemyDmg) + "Hp";
				viataPlayer -= this->enemyDmg;
			}
			else {
				s = "You chose Rock.\nEnemy chose Scissors.\nYou strike\n Enemy loses " + to_string(dmgPlayer) + "Hp";
				this->enemyHp -= dmgPlayer;
			}
		else if (choice == 2)
			if (enemyChoice == 1) {
				s = "You chose Paper.\nEnemy chose Rock.\nYou strike\n Enemy loses " + to_string(dmgPlayer) + "Hp";
				this->enemyHp -= dmgPlayer;
			}
			else if (enemyChoice == 2) {
				s = "You chose Paper.\nEnemy chose Paper.\nYou strike, but enemy blocked";
			}
			else {
				s = "You chose Paper.\nEnemy chose Scissors.\nEnemy strikes\n You lose " + to_string(this->enemyDmg) + "HP";
				viataPlayer -= this->enemyDmg;
			}
		else if (choice == 3)
			if (enemyChoice == 1)
			{
				s = "You chose Scissors.\nEnemy chose Rock.\nEnemy strikes\n You lose " + to_string(this->enemyDmg) + "HP";
				viataPlayer -= this->enemyDmg;
			}
			else if (enemyChoice == 2) {
				s = "You chose Scissors.\nEnemy chose Paper.\nYou strike\n Enemy loses " + to_string(dmgPlayer) + "HP";
				this->enemyHp -= dmgPlayer;
			}
			else {
				s = "You chose Scissors.\nEnemy chose Scissors.\nYou strike, but enemy dodged";
			}
		else
			s = "Invalid choice";

		cout << s << endl;
	}

	if (viataPlayer <= 0)
	{
		cout << "Ai murit" << endl;
		exit(0);
	}
	else
	{
		cout << "Ai invins inamicul" << endl;
		this->player->setHp(viataPlayer);
	}

}

void functionNode::getGold()
{
	this->player->addGold(10);
}