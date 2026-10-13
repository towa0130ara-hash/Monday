#include "Enemy.h"
#include<iostream>

Enemy::Enemy(std::string name) :Character(name)
{}

void Enemy::Attack()
{
	std::cout << "嚙みつき攻撃しました" << std::endl;
}