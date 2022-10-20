#include "ShotPatternI.h"
#include "DxLib.h"

namespace
{
	constexpr float kCircleRaddius = 3.0f;

	constexpr float kShotPattern1VecY = -3.0f;
	constexpr float kShotPattern2VecX = 1.0f;
	constexpr float kShotPattern2VecY = -2.5f;
	constexpr float kShotPattern3VecX = 2.0f;
	constexpr float kShotPattern3VecY = -2.0f;
}

void ShotPatternI::init()
{
	moveCount = 60;
	waitCount = 60;

	shot1Pos.x = 640.0f;
	shot1Pos.y = 360.0f;
	shot1Vec.x = 0.0f;
	shot1Vec.y = kShotPattern1VecY;

	shot2Pos.x = shot1Pos.x;
	shot2Pos.y = shot1Pos.y;
	shot2Vec.x = kShotPattern2VecX;
	shot2Vec.y = kShotPattern2VecY;

	shot3Pos.x = shot1Pos.x;
	shot3Pos.y = shot1Pos.y;
	shot3Vec.x = kShotPattern3VecX;
	shot3Vec.y = kShotPattern3VecY;

	shot4Pos.x = shot1Pos.x;
	shot4Pos.y = shot1Pos.y;
	shot4Vec.x = -kShotPattern2VecX;
	shot4Vec.y = kShotPattern2VecY;

	shot5Pos.x = shot1Pos.x;
	shot5Pos.y = shot1Pos.y;
	shot5Vec.x = -kShotPattern3VecX;
	shot5Vec.y = kShotPattern3VecY;
}

void ShotPatternI::end()
{

}

void ShotPatternI::update()
{
	if (moveCount > 0)
	{
		moveCount--;
	}
	else
	{
		shot1Vec.y = 0.0f;
		shot2Vec.y = 0.0f; shot2Vec.x = 0.0f;
		shot3Vec.y = 0.0f; shot3Vec.x = 0.0f;
		shot4Vec.y = 0.0f; shot4Vec.x = 0.0f;
		shot5Vec.y = 0.0f; shot5Vec.x = 0.0f;
		if(waitCount > 0)
		{
			waitCount--;
		}
		else
		{
			shot1Vec.y = 4.0f;
			shot2Vec.y = 3.5f; shot2Vec.x = -0.25f;
			shot3Vec.y = 3.0f; shot3Vec.x = -0.5f;
			shot4Vec.y = 3.5f; shot4Vec.x = 0.25f;
			shot5Vec.y = 3.0f; shot5Vec.x = 0.5f;
		}
	}
	shot1Pos += shot1Vec;
	shot2Pos += shot2Vec;
	shot3Pos += shot3Vec;
	shot4Pos += shot4Vec;
	shot5Pos += shot5Vec;
}

void ShotPatternI::draw()
{
	DrawCircle(shot1Pos.x, shot1Pos.y, kCircleRaddius, GetColor(255, 255, 255), true);
	DrawCircle(shot2Pos.x, shot2Pos.y, kCircleRaddius, GetColor(255, 255, 255), true);
	DrawCircle(shot3Pos.x, shot3Pos.y, kCircleRaddius, GetColor(255, 255, 255), true);
	DrawCircle(shot4Pos.x, shot4Pos.y, kCircleRaddius, GetColor(255, 255, 255), true);
	DrawCircle(shot5Pos.x, shot5Pos.y, kCircleRaddius, GetColor(255, 255, 255), true);
}