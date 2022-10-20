#pragma once

#include "MenuBase.h"
#include "Vec2.h"

class MenuPlayerStatus : public MenuBase
{
public:
	MenuPlayerStatus();
	virtual ~MenuPlayerStatus();

	virtual void init();
	virtual void end();
	virtual void update();
	virtual void draw();

	bool isEnd() { return m_isEnd; }

private:
	int remainHP;

	Vec2 m_namePos;
	Vec2 m_HPGauge;
	Vec2 m_HPScore;

	bool m_isEnd;
};