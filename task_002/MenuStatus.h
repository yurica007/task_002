#pragma once

#include "MenuBase.h"
#include "SceneTitle.h"
#include "Vec2.h"

class MenuStatus : public MenuBase
{
public:
	MenuStatus();
	virtual ~MenuStatus();

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