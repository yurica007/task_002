#pragma once

#include "MenuBase.h"
#include "Vec2.h"
#include "SelectItem.h"

class MenuItem : public MenuBase
{
public:
	MenuItem()
	{
		m_isEnd = false;
//		m_isReturn = false;

		m_checkMenu = false;
		m_checkMasage = false;
	}

	virtual ~MenuItem() {}

	virtual void init();
	virtual void end();
	virtual void update();
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
//	virtual bool isReturn() { return m_isReturn; }

private:
	bool m_isEnd;
//	bool m_isReturn;

	SelectItem m_menu;
	bool m_checkMenu;
	bool m_checkMasage;

};