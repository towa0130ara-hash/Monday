#include "BalletManager.h"
#include<iostream>

void BalletManager::StartBattle(Character* player, Character* enemy, Character* boss)
{
	std::cout << "勇者の名前:" << player->GetName() << std::endl;
	std::cout << "敵の名前:" << enemy->GetName() << std::endl;
	std::cout << "ボスの名前:" << boss->GetName() << std::endl;
	player->Attack();
	enemy->Attack();
	boss->Attack();

}