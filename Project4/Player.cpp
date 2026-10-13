#include "Player.h"
#include<iostream>

Player::Player(std::string name) :Character(name)
{}

void Player::Attack()
{
	std::cout << "剣で攻撃した" << std::endl;
}