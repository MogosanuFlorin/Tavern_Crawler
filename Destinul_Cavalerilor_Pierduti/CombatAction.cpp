#include "CombatAction.h"
#include <iostream>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Display.h"

CombatAction::CombatAction(Enemy* enemy)
{
	this->enemyHp = enemy->getHp();
	this->enemyDmg = enemy->getDmg();
	this->enemyGoldDrop = enemy->getGoldDrop();
}

void CombatAction::execute(Node* node, Player* player) {
	int playerHp = player->getHp();
	int playerDmg = player->getDmg();

	while (playerHp > 0 && enemyHp > 0) {
		Display::clear();
		std::string s = "";
		s += "Your HP: " + std::to_string(playerHp) + "												Enemy HP: " + std::to_string(enemyHp);
		std::cout << s << std::endl;
		s = "Choose your attack:\n1. Rock\n2. Paper\n3. Scissors\n\nChoose an option: ";
		std::cout << s;
		int choice;
		std::cin >> choice;
		srand(static_cast<unsigned int>(time(0)));
		int enemyChoice = rand() % 3 + 1;

		if (choice == 1)
			if (enemyChoice == 1) {
				s = "You chose Rock.\nEnemy chose Rock.\nEnemy strikes, but you blocked";
			}
			else if (enemyChoice == 2) {
				s = "You chose Rock.\nEnemy chose Paper.\nEnemy strikes\nYou lose " + std::to_string(this->enemyDmg) + "Hp";
				playerHp -= enemyDmg;
			}
			else {
				s = "You chose Rock.\nEnemy chose Scissors.\nYou strike\nEnemy loses " + std::to_string(playerDmg) + "Hp";
				enemyHp -= playerDmg;
			}
		else if (choice == 2)
			if (enemyChoice == 1) {
				s = "You chose Paper.\nEnemy chose Rock.\nYou strike\nEnemy loses " + std::to_string(playerDmg) + "Hp";
				enemyHp -= playerDmg;
			}
			else if (enemyChoice == 2) {
				s = "You chose Paper.\nEnemy chose Paper.\nYou strike, but enemy blocked";
			}
			else {
				s = "You chose Paper.\nEnemy chose Scissors.\nEnemy strikes\nYou lose " + std::to_string(this->enemyDmg) + "HP";
				playerHp -= enemyDmg;
			}
		else if (choice == 3)
			if (enemyChoice == 1)
			{
				s = "You chose Scissors.\nEnemy chose Rock.\nEnemy strikes\nYou lose " + std::to_string(this->enemyDmg) + "HP";
				playerHp -= enemyDmg;
			}
			else if (enemyChoice == 2) {
				s = "You chose Scissors.\nEnemy chose Paper.\nYou strike\nEnemy loses " + std::to_string(playerDmg) + "HP";
				enemyHp -= playerDmg;
			}
			else {
				s = "You chose Scissors.\nEnemy chose Scissors.\nYou strike, but enemy dodged";
			}
		else
			s = "Invalid choice";
		std::cout << s << std::endl;
		Display::waitForKeyPress();
	}
	Display::clear();
	if (playerHp <= 0) {
		std::cout << "You died" << std::endl;
		player->setHp(0);
	}
	else {
		std::cout << "You won" << std::endl;
		std::cout << "You gained " << enemyGoldDrop << " gold." << std::endl;
		Display::waitForKeyPress();
		player->setHp(playerHp);
		player->addGold(enemyGoldDrop);
	}
}