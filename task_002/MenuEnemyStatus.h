#pragma once

#include "MenuBase.h"
#include "Vec2.h"

class MenuEnemyStatus : public MenuBase
{
public:
	MenuEnemyStatus();
	virtual ~MenuEnemyStatus();

	virtual void init();
	virtual void end();
	virtual void update();
	virtual void draw();

	bool isEnd() { return m_isEnd; }

private:
	int remainHP;
	Vec2 m_HPGauge;

	bool m_isEnd;	
};