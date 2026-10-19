#pragma once
using namespace std;
class MagicalGirl
{
public:
	/// <summary>
	/// 戦闘行動
	/// </summary>
	virtual void Fight() = 0;

	/// <summary>
	/// 共通のプロフィール表示を用意する
	/// </summary>
	virtual void ShowProfile();

	/// <summary>
	/// 魔法少女デストラクタ
	/// </summary>
	virtual ~MagicalGirl();


};

