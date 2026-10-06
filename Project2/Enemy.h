#pragma once

#include "Character.h"

class Enemy : public Character
{
public:

    Enemy();

    // 敵の行動を決める
    int SelectAction();
};