#pragma once

#include "MenuBase.h"
#include "Vec2.h"

class MenuPlayerStatus : public MenuBase
{
public:
	MenuPlayerStatus();
	virtual ~MenuPlayerStatus();

	void init();
	void end();
	void update();
	void draw();

	bool isEnd() { return m_isEnd; }

private:
	int remainHP;

	Vec2 m_namePos;
	Vec2 m_HPGauge;
	Vec2 m_HPScore;

	bool m_isEnd;
};