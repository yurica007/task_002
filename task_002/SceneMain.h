#pragma once
#include "SceneBase.h"
#include "SelectMenu.h"
#include "MenuFight.h"

class SceneMain : public SceneBase
{
public:
	SceneMain() {
		m_textPosY = 0;
		m_textVecY = 0;
		m_isEnd = false;
		m_checkFight = false;
	}
	virtual ~SceneMain() {}

	virtual void init();
	virtual void end();
	virtual void update();
	virtual void draw();
	virtual bool isEnd() { return m_isEnd; }
private:
	int m_textPosY;
	int m_textVecY;

	SelectMenu m_menu;

	bool m_isEnd;

	MenuFight m_fight;
	bool m_checkFight;
};