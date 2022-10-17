#include "MenuPlayerStatus.h"
#include "DxLib.h"

namespace
{
	constexpr int kHPMax = 40;
	constexpr float kGageSizeX = 200.0f;
	constexpr float kGageSizeY = 15.0f;
}

MenuPlayerStatus::MenuPlayerStatus()
{
	remainHP = 0;
	m_namePos.x = 0.0f;
	m_namePos.y = 0.0f;
	m_HPGauge.x = 0.0f;
	m_HPGauge.y = 0.0f;
	m_HPScore.x = 0.0f;
	m_HPScore.y = 0.0f;
	
	m_isEnd = false;
}

MenuPlayerStatus::~MenuPlayerStatus()
{

}

void MenuPlayerStatus::init()
{
	remainHP = kHPMax;
	m_namePos.x = 420.0f;
	m_namePos.y = 690.0f;
	m_HPGauge.x = m_namePos.x + 100.0f;
	m_HPGauge.y = m_namePos.y;
	m_HPScore.x = m_HPGauge.x + kGageSizeX + 20.0f;
	m_HPScore.y = m_HPGauge.y;
}

void MenuPlayerStatus::end()
{
	
}

void MenuPlayerStatus::update()
{
	remainHP -= 1;
}

void MenuPlayerStatus::draw()
{
	DrawStringF(m_namePos.x, m_namePos.y, "You", GetColor(255, 255, 255));
	DrawBoxAA(m_HPGauge.x, m_HPGauge.y, m_HPGauge.x + kGageSizeX, m_HPGauge.y + kGageSizeY, GetColor(125, 125, 125), false);
	DrawBoxAA(m_HPGauge.x, m_HPGauge.y, m_HPGauge.x + kGageSizeX, m_HPGauge.y + kGageSizeY, GetColor(255, 255, 255), true);
	DrawFormatStringF(m_HPScore.x, m_HPScore.y, GetColor(255, 255, 255), "%d / %d", remainHP, kHPMax);
}