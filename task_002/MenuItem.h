#pragma once

#include "MenuBase.h"
#include "Vec2.h"
#include "SelectItem.h"

class MenuItem : public MenuBase
{
public:
	MenuItem();
	virtual ~MenuItem();

	virtual void init();
	virtual void end();
	virtual void update();
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }

private:
	SelectItem m_menu;
	bool m_checkMenu;
	bool m_checkMasage;

	bool m_isEnd;
};