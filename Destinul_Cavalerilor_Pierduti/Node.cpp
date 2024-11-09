#include <iostream>
#include <string>
#include "Node.h"
#include "utility.h"
using namespace std;

Node::Node()
{
	this->story = "";
	this->option1 = "";
	this->option2 = "";
	this->fuctionID = 0;
	this->enemyHp = 0;
	this->enemyDmg = 0;
	this->gold = 0;
	this->nextNode1 = NULL;
	this->nextNode2 = NULL;
	this->player = NULL;
}

void Node::setStory(std::string story, std::string option1, std::string option2, Node* nextNode1, Node* nextNode2)
{
	this->story = story;
	this->option1 = option1;
	this->option2 = option2;
	this->nextNode1 = nextNode1;
	this->nextNode2 = nextNode2;

}

void Node::setCombat(int enemyHp, int enemyDmg, caracter* player, Node* nextNode1)
{
	this->nextNode1 = nextNode1;
	this->fuctionID = 1;
	this->enemyHp = enemyHp;
	this->enemyDmg = enemyDmg;
	this->player = player;
}

void Node::setGetGold(int gold, caracter* player, Node* nextNode1)
{
	this->nextNode1 = nextNode1;
	this->fuctionID = 2;
	this->gold = gold;
	this->player = player;
}

void Node::callFunction()
{
	if (this->fuctionID == 2)
	{
		this->getGold();
	}
	else if (this->fuctionID == 1)
	{
		this->combat();
	}
	else
	{
		cout << "Error: function ID not set" << endl;
	}
}

int Node::printStory() const
{
	cout << this->story << endl;
	if (this->option1 != "" && this->option2 != "") {
		cout << "1. " << this->option1 << endl;
		cout << "2. " << this->option2 << endl;
		int choice;
		cout << endl << "Choice: ";
		cin >> choice;
		return choice;
	}
	waitForKeyPress();
	return 1;
}

Node* Node::getNextNode(int id)
{
	if (id == 1)
	{
		return this->nextNode1;
	}
	else if (id == 2)
	{
		return this->nextNode2;
	}
	else
	{
		cout << "Error: invalid id" << endl;
		return NULL;
	}
}


void Node::combat() {
	int playerHp = this->player->getHp();
	int playerDmg = this->player->getDmg();
	int enemyHp = this->enemyHp;
	int enemyDmg = this->enemyDmg;
	

	while (playerHp > 0 && enemyHp > 0) {
		clear();
		string s = "";
		s += "Your HP: " + to_string(playerHp) + "												Enemy HP: " + to_string(enemyHp);
		cout << s << endl;
		s = "Choose your attack:\n1. Rock\n2. Paper\n3. Scissors\n\nChoose an option: ";
		cout << s;
		int choice;
		cin >> choice;
		int enemyChoice = rand() % 3 + 1;

		if (choice == 1)
			if (enemyChoice == 1) {
				s = "You chose Rock.\nEnemy chose Rock.\nEnemy strikes, but you blocked";
			}
			else if (enemyChoice == 2) {
				s = "You chose Rock.\nEnemy chose Paper.\nEnemy strikes\nYou lose " + to_string(this->enemyDmg) + "Hp";
				playerHp -= enemyDmg;
			}
			else {
				s = "You chose Rock.\nEnemy chose Scissors.\nYou strike\nEnemy loses " + to_string(playerDmg) + "Hp";
				enemyHp -= playerDmg;
			}
		else if (choice == 2)
			if (enemyChoice == 1) {
				s = "You chose Paper.\nEnemy chose Rock.\nYou strike\nEnemy loses " + to_string(playerDmg) + "Hp";
				enemyHp -= playerDmg;
			}
			else if (enemyChoice == 2) {
				s = "You chose Paper.\nEnemy chose Paper.\nYou strike, but enemy blocked";
			}
			else {
				s = "You chose Paper.\nEnemy chose Scissors.\nEnemy strikes\nYou lose " + to_string(this->enemyDmg) + "HP";
				playerHp -= enemyDmg;
			}
		else if (choice == 3)
			if (enemyChoice == 1)
			{
				s = "You chose Scissors.\nEnemy chose Rock.\nEnemy strikes\nYou lose " + to_string(this->enemyDmg) + "HP";
				playerHp -= enemyDmg;
			}
			else if (enemyChoice == 2) {
				s = "You chose Scissors.\nEnemy chose Paper.\nYou strike\nEnemy loses " + to_string(playerDmg) + "HP";
				enemyHp -= playerDmg;
			}
			else {
				s = "You chose Scissors.\nEnemy chose Scissors.\nYou strike, but enemy dodged";
			}
		else
			s = "Invalid choice";
		cout << s << endl;
		waitForKeyPress();
	}
	clear();
	if (playerHp <= 0) {
		
		cout << "You died" << endl;
		this->nextNode1 = NULL;
	}
	else {
		cout << "You won" << endl;
		cout << "You gained " << this->gold << " gold" << endl;
		this->player->setHp(playerHp);
		this->getGold();
	}
}

void Node::getGold()
{
	this->player->addGold(this->gold);
}