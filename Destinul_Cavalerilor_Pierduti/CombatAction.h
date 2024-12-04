#pragma once
#include "NodeAction.h"
#include "Player.h"
#include "Enemy.h"
#include "Node.h"
class CombatAction : public NodeAction
{
public:
	CombatAction(Enemy* enemy);
	void execute(Node* node, Player* player) override;
private:
	int enemyHp;
	int enemyDmg;
	int enemyGoldDrop;
};

