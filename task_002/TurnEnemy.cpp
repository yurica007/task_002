#include "TurnEnemy.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	constexpr float kCenterPosX = 640.0f;
	constexpr float kCenterPosY = 500.0f;

	constexpr float kSquareRaddius = 120.0f;

	constexpr float kShotRaddius = 3.0f;
	constexpr float kPlayreRaddius = 7.0f;
}

void TurnEnemy::init()
{
	m_isEnd = false;

	shotHitArea = m_patternI.getShotPos();
	shotHitArea.x + kShotRaddius;
	shotHitArea.y + kShotRaddius;

	playerHitArea = m_cursor.getPlayerPos();
	playerHitArea.x + kPlayreRaddius;
	playerHitArea.y + kPlayreRaddius;

	m_patternI.init();
	m_cursor.init();

}

void TurnEnemy::end()
{
	m_patternI.end();
	m_cursor.end();
}

void TurnEnemy::update()
{
	if (Pad::isTrigger(PAD_INPUT_2))
	{
		m_isEnd = true;
	}
	m_patternI.update();
	m_cursor.update();

	if ((shotHitArea.x + playerHitArea.x) < (playerHitArea.x - shotHitArea.x))
	{
		m_isEnd = true;
	}
	if (m_isEnd) DrawString(10, 10, "hit", GetColor(255, 255, 255));
}

void TurnEnemy::draw()
{
	DrawBox(kCenterPosX - kSquareRaddius, kCenterPosY - kSquareRaddius,
		kCenterPosX + kSquareRaddius, kCenterPosY + kSquareRaddius, GetColor(255, 255, 255), false);
	m_patternI.draw();
	m_cursor.draw();
}