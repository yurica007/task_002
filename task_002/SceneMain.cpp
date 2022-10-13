#include "SceneMain.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	constexpr float kCenterPosX = 640.0f;
	constexpr float kCenterPosY = 500.0f;

	constexpr float kWidthLen = 360.0f;
	constexpr float kHeightLen = 120.0f;
}

void SceneMain::init()
{
	m_isEnd = false;

	m_pCheckMenu = true;
	m_pMenu.init();

	m_pMenu.addItem("FIGHT");
	m_pMenu.addItem("ACT");
	m_pMenu.addItem("ITEM");
	m_pMenu.addItem("MERCY");
	
	m_pMenu.setPos(320, 660);
	m_pMenu.setupCursor();
	
	m_pCheckFight = false;
	m_pFight.init();

	m_pCheckItem = false;
	m_pItem.init();
}

void SceneMain::end()
{
	m_pMenu.end();
	m_pFight.end();
	m_pItem.end();
}

void SceneMain::update()
{
	if (Pad::isTrigger(PAD_INPUT_2))
	{
		m_isEnd = true;
	}
	switch (m_pMenu.getItemIndex())
	{
	
	case 0:
		if (Pad::isTrigger(PAD_INPUT_1))
		{
			m_pCheckMenu = false;
			m_pCheckFight = true;
		}
		break;
	case 2:
		if (Pad::isTrigger(PAD_INPUT_1))
		{
			m_pCheckMenu = false;
			m_pCheckItem = true;
		}
		break;
	default:
		break;
	}

	if (m_pCheckMenu) m_pMenu.update();
	if (m_pCheckFight) m_pFight.update();
	if (m_pCheckItem) m_pItem.update();
}

void SceneMain::draw()
{
	DrawBox(kCenterPosX - kWidthLen, kCenterPosY - kHeightLen,
		kCenterPosX + kWidthLen, kCenterPosY + kHeightLen, GetColor(255, 255, 255), false);

	if (m_pCheckMenu) m_pMenu.draw();
	if (m_pCheckFight) m_pFight.draw();
	if (m_pCheckItem) m_pItem.draw();
}