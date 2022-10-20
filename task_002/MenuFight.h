#pragma once

#include "MenuBase.h"
#include "Vec2.h"

class MenuFight : public MenuBase
{
public:
	MenuFight()
	{
		m_damageCursorCenterX = 0.0f;
		m_damageCursorPos.x = 0;
		m_damageCursorPos.y = 0;
		m_damageCursorVec = 0.0;

		m_dealtDamage = 0.0f;
		ATK = 0;

		m_isEnd = false;
		m_isReturn = false;
	}
	virtual ~MenuFight() {}

	virtual void init();
	virtual void end();
	virtual void update();
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
	virtual bool isReturn() { return m_isReturn; }

private:
	// 攻撃カーソルの横の座標情報
	float m_damageCursorCenterX;
	// 攻撃カーソルの座標情報
	Vec2 m_damageCursorPos;
	// 攻撃カーソルの移動速度
	float m_damageCursorVec;

	// 攻撃力
	int ATK;
	// 与えるダメージ量
	float m_dealtDamage;

	bool m_isEnd;
	bool m_isReturn;
};