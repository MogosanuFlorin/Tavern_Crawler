#pragma once
class Node;
class Player;
class Enemy;
class NodeAction
{
public:
	virtual void execute(Node* node, Player* player) = 0;
	virtual ~NodeAction() = default;
};

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

class GetGoldAction : public NodeAction
{
public:
	GetGoldAction(int gold);
	void execute(Node* node, Player* player) override;
private:
	int gold;
};


