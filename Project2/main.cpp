#include "DxLib.h"

#include "Player.h"
#include "Enemy.h"

#include<iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    //========================================
    // DxLib初期設定
    //========================================

    ChangeWindowMode(TRUE);

    if (DxLib_Init() == -1)
    {
        return -1;
    }

    // 乱数初期化
    srand(static_cast<unsigned int>(time(nullptr)));

    //========================================
    // プレイヤーと敵を作成
    //========================================

    Player player;
    Enemy enemy;

    //========================================
    // ゲームループ
    //========================================

    while (ProcessMessage() == 0)
    {
        //====================================
        // 画面クリア
        //====================================

        ClearDrawScreen();

        //====================================
        // プレイヤー情報
        //====================================

        DrawString(100,50,"PLAYER",GetColor(255, 255, 255));

        DrawFormatString(100,80, GetColor(255, 255, 255), "HP : %d",player.GetHp());

        DrawFormatString(100,110,GetColor(255, 255, 255), "Attack : %d",player.GetAttack());

        DrawFormatString(100, 140, GetColor(255, 255, 255), "Defense : %d",player.GetDefense());

        DrawFormatString(100,170, GetColor(255, 255, 255),"Evade : %d", player.GetEavade());

        //====================================
        // 敵情報
        //====================================

        DrawString(600,50,"ENEMY",GetColor(255, 255, 255));

        DrawFormatString(600, 80,GetColor(255, 255, 255), "HP : %d",enemy.GetHp());

        DrawFormatString(600,110, GetColor(255, 255, 255),"Attack : %d",enemy.GetAttack());

        DrawFormatString(600,140,GetColor(255, 255, 255),"Defense : %d", enemy.GetDefense());

        DrawFormatString(600, 170,GetColor(255, 255, 255),"Evade : %d",enemy.GetEavade());

        //====================================
        // プレイヤーのターン
        //====================================

        DrawString(100,250,"Player Turn",GetColor(255, 255, 255));

        DrawString(100,300,"1 : Attack",GetColor(255, 255, 255));

        DrawString(100,330, "2 : Heal",GetColor(255, 255, 255));

        ScreenFlip();

        // キー入力待ち
        int action = 0;

        while (action == 0)
        {
            if (ProcessMessage() == -1)
            {
                break;
            }

            if (CheckHitKey(KEY_INPUT_1))
            {
                action = 1;
            }

            if (CheckHitKey(KEY_INPUT_2))
            {
                action = 2;
            }
        }

        //====================================
        // プレイヤーの行動
        //====================================

        if (action == 1)
        {
            player.Attack(enemy);
        }
        else if (action == 2)
        {
            player.Heal();
        }

        //====================================
        // 敵が死亡したか
        //====================================

        if (enemy.Dead())
        {
            ClearDrawScreen();

            DrawString(500,300,"PLAYER WIN!",GetColor(255, 255, 255));

            ScreenFlip();

            WaitKey();

            break;
        }

        //====================================
        // 敵のターン
        //====================================

        ClearDrawScreen();

        DrawString(100,250,"Enemy Turn",GetColor(255, 255, 255));

        ScreenFlip();

        WaitTimer(1000);

        int enemyAction = enemy.SelectAction();

        if (enemyAction == 1)
        {
            enemy.Attack(player);
        }
        else
        {
            enemy.Heal();
        }

        //====================================
        // プレイヤーが死亡したか
        //====================================

        if (player.Dead())
        {
            ClearDrawScreen();

            DrawString(500,300,"ENEMY WIN!",GetColor(255, 255, 255));

            ScreenFlip();

            WaitKey();

            break;
        }

        //====================================
        // 次のターン
        //====================================

        WaitTimer(500);
    }

    //========================================
    // DxLib終了
    //========================================

    DxLib_End();

    return 0;
}