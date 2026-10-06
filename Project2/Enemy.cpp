#include "Enemy.h"

#include <cstdlib>

Enemy::Enemy()
    : Character()
{}

//========================================
// 敵の行動選択
//========================================

int Enemy::SelectAction()
{
    // 1 または 2
    return rand() % 2 + 1;
}