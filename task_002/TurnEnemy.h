#pragma once

#include "MenuBase.h"
#include "ShotPatternI.h"
#include "PlayerCursor.h"

class TurnEnemy : public MenuBase
{
public:
	TurnEnemy() {
		m_isEnd = false;
		shotHitArea.x = 0.0f;
		shotHitArea.y = 0.0f;
		playerHitArea.x = 0.0f;
		playerHitArea.y = 0.0f;
	}
	virtual ~TurnEnemy() {}

	virtual void init();
	virtual void end();
	virtual void update();
	virtual void draw();
	virtual bool isEnd() { return m_isEnd; }
private:
	bool m_isEnd;

	Vec2 shotHitArea;
	Vec2 playerHitArea;

	ShotPatternI m_patternI;
	PlayerCursor m_cursor;
};