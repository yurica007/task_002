#include "TurnPlayer.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	constexpr float kCenterPosX = 640.0f;
	constexpr float kCenterPosY = 500.0f;

	constexpr float kWidthLen = 360.0f;
	constexpr float kHeightLen = 120.0f;
	constexpr int kWaitCount = 45;
}

void TurnPlayer::init()
{
	m_isEnd = false;
	m_isReturn = false;
	m_turnEnd = true;

	m_CheckMenu = true;
	m_Menu.init();

	m_Menu.addItem("FIGHT");
	m_Menu.addItem("ACT");
	m_Menu.addItem("ITEM");
	m_Menu.addItem("MERCY");

	m_Menu.setPos(320, 640);
	m_Menu.setupCursor();

	m_CheckFight = false;
	m_Fight.init();

	m_CheckAct = false;
	m_Act.init();

	m_CheckItem = false;
	m_Item.init();

	m_CheckMercy = false;
	m_Mercy.init();

	waitCount = kWaitCount;
}

void TurnPlayer::end()
{
	m_Menu.end();
	m_Fight.end();
	m_Act.end();
	m_Item.end();
	m_Mercy.end();
}

void TurnPlayer::update()
{
	int menuIndex = m_Menu.getItemIndex();

	switch (menuIndex)
	{
	case 0:
		if (Pad::isTrigger(PAD_INPUT_1))
		{
			m_CheckMenu = false;
			m_CheckFight = true;
		}
		break;
	case 1:
		if (Pad::isTrigger(PAD_INPUT_1))
		{
			m_CheckMenu = false;
			m_CheckAct = true;
		}
		break;
	case 2:
		if (Pad::isTrigger(PAD_INPUT_1))
		{
			m_CheckMenu = false;
			m_CheckItem = true;
		}
		break;
	case 3:
		if (Pad::isTrigger(PAD_INPUT_1))
		{
			m_CheckMenu = false;
			m_CheckMercy = true;
		}
		break;
	default:
		break;
	}

	if (m_CheckMenu) m_Menu.update();

	if (waitCount > 0)
	{
		waitCount--;
	}
	else
	{
		if (m_CheckFight)
		{
			m_Fight.update();
			if(m_Fight.isEnd()) m_turnEnd = false;
		}
		if (m_CheckAct)
		{
			m_Act.update();
			if (m_Act.isEnd()) m_turnEnd = false;
		}
		if (m_CheckItem)
		{
			m_Item.update();
			if (m_Item.isEnd()) m_turnEnd = false;
		}
		if (m_CheckMercy)
		{
			m_Mercy.update();
			if (m_Mercy.isEnd()) m_turnEnd = false;
		}
	}
}

void TurnPlayer::draw()
{
	DrawBox(kCenterPosX - kWidthLen, kCenterPosY - kHeightLen,
		kCenterPosX + kWidthLen, kCenterPosY + kHeightLen, GetColor(255, 255, 255), false);

	if (m_CheckMenu) m_Menu.draw();
	if (m_CheckFight) m_Fight.draw();
	if (m_CheckAct) m_Act.draw();
	if (m_CheckItem) m_Item.draw();
	if (m_CheckMercy) m_Mercy.draw();
}