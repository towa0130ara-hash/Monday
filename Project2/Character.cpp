#include "Character.h"
#include"Config.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

Character::Character()
{
	//HP
	hp = Config::MAX_HP;

	//攻撃力、防御力、回避力をランダムで設定
	attack = Config::STATUS_MIN + rand() % (Config::STATUS_MAX - Config::STATUS_MIN + 1);
	difense = Config::STATUS_MIN + rand() % (Config::STATUS_MAX - Config::STATUS_MIN + 1);
	evade = Config::STATUS_MIN + rand() % (Config::STATUS_MAX - Config::STATUS_MIN + 1);
}

//========================================
// 攻撃
//========================================

void Character::Attack(Character& target)
{
	//1～20のランダム値
	int randomVale = Config::RANDAMU_MIN + rand() % (Config::RANDAMU_MAX - Config::RANDAMU_MIN - 1);

	//回避判定
	if (randomVale>target.evade)
	{
		//ダメージ計算
		int damage = attack + randomVale - target.difense;

		//ダメージがマイナスにならないようにする
		if (damage<0)
		{
			damage = 0;
		}

		target.hp -= damage;
	}
}

//========================================
// 回復
//========================================

void Character::Heal()
{
	//1～１２のランダム値
	int  healValue = Config::RANDAMU_MIN + rand() % (Config::RANDAMU_MAX - Config::RANDAMU_MIN + 1);

	hp += healValue;

	//Hp１００を超えない
	if (hp>Config::MAX_HP)
	{
		hp = Config::MAX_HP;
	}
}

//========================================
// 死亡判定
//========================================

bool Character::Dead()const
{
	return hp <= 0;
}

//========================================
// HP取得
//========================================

int Character::GetHp()const
{
	return hp;
}

//========================================
// 攻撃力取得
//========================================

int Character::GetAttack()const
{
	return attack;
}

//========================================
// 防御力取得
//========================================

int Character::GetDefense()const
{
	return difense;
}

//========================================
// 回避力取得
//========================================

int Character::GetEavade()const
{
	return evade;
}