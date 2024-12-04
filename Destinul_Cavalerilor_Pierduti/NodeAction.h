#pragma once
#include "Node.h"
#include "Player.h"
class NodeAction
{
public:
	virtual void execute(Node* node, Player* player) = 0;
	virtual ~NodeAction() = default;
};




