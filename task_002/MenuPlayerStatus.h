#pragma once

#include "MenuBase.h"
#include "SceneTitle.h"
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
	Vec2 m_namePos;
	Vec2 m_HPGauge;

	bool m_isEnd;
};