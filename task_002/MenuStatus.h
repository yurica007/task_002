#pragma once

#include "MenuBase.h"
#include "SceneTitle.h"

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
	SceneTitle m_name;

	bool m_isEnd;
};