#include"Enemy.h"
#include<iostream>

Enemy::Enemy()
{
	std::cout << "Enemyを生成しました" << std::endl;
}

Enemy::~Enemy()
{
	std::cout << "Enemyを破棄しました" << std::endl;
}

void Enemy::Update()
{
	std::cout << "Enemyを更新しました" << std::endl;
}

void Enemy::Draw()
{
	std::cout << "Enemyを描画しました" << std::endl;
}