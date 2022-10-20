#pragma once

#include "Vec2.h"

class ShotPatternI
{
public:
	ShotPatternI() {
		moveCount = 0;
		waitCount = 0;

		shot1Pos.x = 0.0f;
		shot1Pos.y = 0.0f;
		shot1Vec.x = 0.0f;
		shot1Vec.y = 0.0f;
		
		shot2Pos.x = 0.0f;
		shot2Pos.y = 0.0f;
		shot2Vec.x = 0.0f;
		shot2Vec.y = 0.0f;

		shot3Pos.x = 0.0f;
		shot3Pos.y = 0.0f;
		shot3Vec.x = 0.0f;
		shot3Vec.y = 0.0f;

		shot4Pos.x = 0.0f;
		shot4Pos.y = 0.0f;
		shot4Vec.x = 0.0f;
		shot4Vec.y = 0.0f;

		shot5Pos.x = 0.0f;
		shot5Pos.y = 0.0f;
		shot5Vec.x = 0.0f;
		shot5Vec.y = 0.0f;

		m_isEnd = false;
	}
	virtual ~ShotPatternI() {}

	void init();
	void end();
	void update();
	void draw();

	virtual bool isEnd() { return m_isEnd; }

	Vec2 getShotPos() { return shot1Pos; }

private:
	int moveCount;
	int waitCount;
	
	Vec2 shot1Pos;
	Vec2 shot1Vec;

	Vec2 shot2Pos;
	Vec2 shot2Vec;

	Vec2 shot3Pos;
	Vec2 shot3Vec;
	
	Vec2 shot4Pos;
	Vec2 shot4Vec;

	Vec2 shot5Pos;
	Vec2 shot5Vec;

	bool m_isEnd;
};