#include "Player.h"
#include "DxLib.h"

Player::Player()
    : Character()
{}

//========================================
// プレイヤーの行動選択
//========================================

int Player::SelectAction()
{
    while (true)
    {
        // 「1：攻撃」「2：回復」を表示
        DrawString( 100,250,"1 : Attack",GetColor(255, 255, 255));

        DrawString(100, 280,"2 : Heal",GetColor(255, 255, 255));

        DrawString(100, 320,"Press 1 or 2",GetColor(255, 255, 255));

        ScreenFlip();

        // 1キーが押された
        if (CheckHitKey(KEY_INPUT_1))
        {
            return 1;
        }

        // 2キーが押された
        if (CheckHitKey(KEY_INPUT_2))
        {
            return 2;
        }

        // ESCキーで終了
        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            return 0;
        }

        // CPU負荷を下げる
        WaitTimer(10);
    }
}