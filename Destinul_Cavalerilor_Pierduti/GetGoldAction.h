#pragma once
#include "NodeAction.h"
#include "Player.h"
#include "Node.h"
class GetGoldAction : public NodeAction
{
public:
	GetGoldAction(int gold);
	void execute(Node* node, Player* player) override;
private:
	int gold;
};

