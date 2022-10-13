#pragma once

#include <vector>
#include "SceneBase.h"
#include "SelectMenu.h"
#include "MenuFight.h"
#include "MenuItem.h"

class SceneMain : public SceneBase
{
public:
	SceneMain() {
		m_pCheckMenu = false;
		m_isEnd = false;
		m_pCheckFight = false;
		m_pCheckItem = false;
	}
	virtual ~SceneMain() {}

	virtual void init();
	virtual void end();
	virtual void update();
	virtual void draw();
	virtual bool isEnd() { return m_isEnd; }
private:
	bool m_isEnd;

	// 行動の選択項目
	SelectMenu m_pMenu;
	bool m_pCheckMenu;
	
	// FIGHT項目の行動
	MenuFight m_pFight;
	bool m_pCheckFight;
	
	// ITEM項目の行動
	MenuItem m_pItem;
	bool m_pCheckItem;
};