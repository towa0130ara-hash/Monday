#pragma once

#include "Character.h"

class Player : public Character
{
public:

    Player();

    // プレイヤーの行動を選択
    int SelectAction();
};