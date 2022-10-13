#include "MenuFight.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	// 四角の中央の位置
	constexpr float kCenterPosX = 640.0f;
	constexpr float kCenterPosY = 500.0f;

	// 攻撃カーソルの高さと幅
	constexpr float kCursorHeight = 120.0f;
	constexpr float kCursorWidth = 20.0f;

	// 攻撃カーソルの移動速度
	constexpr float kCurcorSpeed = 15.0f;
}

MenuFight::MenuFight()
{
	m_damageCursorCenterX = 0.0f;
	m_damageCursorPos.x = 0;
	m_damageCursorPos.y = 0;
	m_damageCursorVec = 0.0;

	m_dealtDamage = 0.0f;
	ATK = 0;

	m_isEnd = false;
}

MenuFight::~MenuFight()
{

}

void MenuFight::init()
{
	m_damageCursorCenterX = 0.0f;
	m_damageCursorPos.x = 280.0f;
	m_damageCursorPos.y = kCenterPosY;
	m_damageCursorVec = kCurcorSpeed;

	m_dealtDamage = 0.0f;
	ATK = 10;
}

void MenuFight::end()
{
	
}

void MenuFight::update()
{
	m_damageCursorPos.x += m_damageCursorVec;
	m_damageCursorCenterX = m_damageCursorPos.x + kCursorWidth / 2;

	if (Pad::isPress(PAD_INPUT_3))
	{
		m_damageCursorVec = 0.0f;
		m_isEnd = true;

		if (m_damageCursorCenterX < kCenterPosX)
		{
			m_dealtDamage = m_damageCursorCenterX / kCenterPosX;
		}
		else
		{
			m_dealtDamage = kCenterPosX / m_damageCursorCenterX;
		}

	}

	if ((m_damageCursorPos.x + kCursorWidth) >= 1000.0f)
	{
		m_damageCursorVec = 0.0f;
		m_isEnd = true;
	}
}

void MenuFight::draw()
{
	DrawFormatString(10, 10, GetColor(255, 255, 255),
		"攻撃力：%d", ATK);

	DrawFormatString(10, 30, GetColor(255, 255, 255),
		"ダメージ数：%f", ATK * m_dealtDamage);

	DrawBoxAA(m_damageCursorPos.x, m_damageCursorPos.y - kCursorHeight,
		m_damageCursorPos.x + kCursorWidth, m_damageCursorPos.y + kCursorHeight, GetColor(255, 0, 0), true);
}