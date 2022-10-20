#pragma once

#include "MenuBase.h"
#include "SelectMenu.h"
#include "MenuFight.h"
#include "MenuAct.h"
#include "MenuItem.h"
#include "MenuMercy.h"
#include "MenuPlayerStatus.h"
#include "MenuEnemyStatus.h"

class TurnPlayer : public MenuBase
{
public:
	TurnPlayer() {
		m_isEnd = false;
		m_isReturn = false;
		m_turnEnd = true;

		m_CheckMenu = false;
		m_CheckFight = false;
		m_CheckAct = false;
		m_CheckItem = false;
		m_CheckMercy = false;
		waitCount = 0;
	}
	virtual ~TurnPlayer() {}

	virtual void init();
	virtual void end();
	virtual void update();
	virtual void draw();
	virtual bool isEnd() { return m_isEnd; }
	virtual bool isTurnEnd() { return  m_turnEnd; }
private:
	bool m_isEnd;
	bool m_isReturn;

	bool m_turnEnd;

	// 行動の選択項目
	SelectMenu m_Menu;
	bool m_CheckMenu;

	// FIGHT項目の行動
	MenuFight m_Fight;
	bool m_CheckFight;

	MenuAct m_Act;
	bool m_CheckAct;

	// ITEM項目の行動
	MenuItem m_Item;
	bool m_CheckItem;

	MenuMercy m_Mercy;
	bool m_CheckMercy;

	int waitCount;
};