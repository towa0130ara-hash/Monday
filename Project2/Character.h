#pragma once
class Character
{
protected:

	//能力値
	int hp;
	int attack;
	int difense;
	int evade;

public:

	Character();

	//攻撃力
	void Attack(Character& target);

	//回復
	void Heal();

	//HPが０以下か
	bool Dead()const;

	//能力値取得
	int GetHp()const;
	int GetAttack()const;
	int GetDefense()const;
	int GetEavade()const;
};