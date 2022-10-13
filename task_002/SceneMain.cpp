#include "SceneMain.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	constexpr int kCenterPosX = 640;
	constexpr int kCenterPosY = 500;

	constexpr int kWidthLen = 360;
	constexpr int kHeightLen = 120;
}

void SceneMain::init()
{
	m_textPosY = 0;
	m_textVecY = 4;

	m_isEnd = false;

	m_menu.init();
	m_menu.addItem("FIGHT");
	m_menu.addItem("ACT");
	m_menu.addItem("ITEM");
	m_menu.addItem("MERCY");

	m_menu.setPos(320, 660);
	m_menu.setupCursor();

	m_checkFight = false;
	m_fight.init();
}

void SceneMain::end()
{
	m_menu.end();
	m_fight.end();
}

void SceneMain::update()
{
	if (Pad::isTrigger(PAD_INPUT_1))
	{
		m_isEnd = true;
	}

	if (Pad::isPress(PAD_INPUT_3))
	{
		m_checkFight = true;
	}
	m_menu.update();
	if (m_checkFight) m_fight.update();
}

void SceneMain::draw()
{
	DrawBox(kCenterPosX - kWidthLen, kCenterPosY - kHeightLen,
		kCenterPosX + kWidthLen, kCenterPosY + kHeightLen, GetColor(255, 255, 255), false);
	m_menu.draw();
	if (m_checkFight) m_fight.draw();
}