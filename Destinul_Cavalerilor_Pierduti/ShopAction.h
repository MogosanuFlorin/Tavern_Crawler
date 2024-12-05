#pragma once
#include "NodeAction.h"
#include "Node.h"
#include "Player.h"	
#include "Shop.h"
class ShopAction : public NodeAction
{
public:
	ShopAction(Shop* shop);
	void execute(Node* node, Player* player) override;
private:
	Shop* shop;
};

