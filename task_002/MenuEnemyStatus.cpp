#include "MenuEnemyStatus.h"
#include "DxLib.h"

namespace
{
	constexpr float kHPPosX = 490.0f;
	constexpr float kHPPosY = 150.0f;

	constexpr int kHPMax = 100;
	constexpr float kGageSizeX = 300.0f;
	constexpr float kGageSizeY = 20.0f;
}

MenuEnemyStatus::MenuEnemyStatus()
{
	remainHP = 0;
	m_HPGauge.x = 0.0f;
	m_HPGauge.y = 0.0f;

	m_isEnd = false;
}

MenuEnemyStatus::~MenuEnemyStatus()
{

}

void MenuEnemyStatus::init()
{
	m_HPGauge.x = kHPPosX + kGageSizeX;
	m_HPGauge.y = kHPPosY + kGageSizeY;
}

void MenuEnemyStatus::end()
{

}

void MenuEnemyStatus::update()
{
	remainHP -= 1;
}

void MenuEnemyStatus::draw()
{
	DrawBoxAA(kHPPosX, kHPPosY, m_HPGauge.x, m_HPGauge.y, GetColor(125, 125, 125), false);
	DrawBoxAA(kHPPosX, kHPPosY, m_HPGauge.x, m_HPGauge.y, GetColor(255, 255, 255), true);
}