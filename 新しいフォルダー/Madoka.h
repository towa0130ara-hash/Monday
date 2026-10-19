#pragma once
#include "MagicalGirl.h"
class Madoka :public MagicalGirl
{
public:

	/// <summary>
	/// 戦闘行動（まどかオーバーライド）
	/// </summary>
	void Fight() override;

	/// <summary>
	/// プロフィール表示
	/// </summary>
	//	void ShowProfile() override;

};

