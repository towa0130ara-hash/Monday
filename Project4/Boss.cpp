#include "Boss.h"
#include<iostream>

Boss::Boss(std::string name) :Character(name)
{

}

void Boss::Attack()
{
	std::cout << "強力な必殺技をはなった" << std::endl;
};