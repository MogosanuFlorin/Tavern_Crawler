#pragma once
#include "NodeAction.h"
class LoseAllMoneyAction : public NodeAction
{
public:
	LoseAllMoneyAction();
	void execute(Node* node, Player* player) override;
private:
};

