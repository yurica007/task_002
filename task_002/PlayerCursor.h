#pragma once

#include "Vec2.h"

class PlayerCursor
{
public:
	PlayerCursor() {
		playerPos.x = 0.0f;
		playerPos.y = 0.0f;
		playerVec.x = 0.0f;
		playerVec.y = 0.0f;

		m_isEnd = false;
	}
	virtual ~PlayerCursor() {}

	void init();
	void end();
	void update();
	void draw();
	bool isEnd() { return m_isEnd; }

	Vec2 getPlayerPos() { return playerPos; }

private:
	Vec2 playerPos;
	Vec2 playerVec;

	bool m_isEnd;

};