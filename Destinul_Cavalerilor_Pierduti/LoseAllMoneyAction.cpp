#include "LoseAllMoneyAction.h"

LoseAllMoneyAction::LoseAllMoneyAction()
{
}

void LoseAllMoneyAction::execute(Node* node, Player* player)
{
	player->setGold(0);
}
