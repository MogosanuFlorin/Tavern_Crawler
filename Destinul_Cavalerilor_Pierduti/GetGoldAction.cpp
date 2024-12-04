#include "GetGoldAction.h"
#include "Player.h"
#include "Node.h"


GetGoldAction::GetGoldAction(int gold)
{
	this->gold = gold;
}

void GetGoldAction::execute(Node* node, Player* player)
{
	player->addGold(this->gold);
}