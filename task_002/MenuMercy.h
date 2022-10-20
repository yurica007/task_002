#pragma once

#include "MenuBase.h"
#include "Vec2.h"

class MenuMercy : public MenuBase
{
public:
	MenuMercy()
	{
		m_isEnd = false;
//		m_isReturn = false;
	}
	virtual ~MenuMercy() {}

	virtual void init();
	virtual void end();
	virtual void update();
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
//	virtual bool isReturn() { return m_isReturn; }

private:
	bool m_isEnd;
//	bool m_isReturn;
};