#include "PlayerCursor.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	constexpr float kCenterPosX = 640.0f;
	constexpr float kCenterPosY = 500.0f;
	constexpr float kSquareRaddius = 120.0f;

	constexpr float kCircleRaddius = 7.0f;

	constexpr float kCursorVecX = 2.0f;
	constexpr float kCursorVecY = 2.0f;
}

void PlayerCursor::init()
{
	playerPos.x = kCenterPosX;
	playerPos.y = kCenterPosY;
	playerVec.x = 0.0f;
	playerVec.y = 0.0f;
}

void PlayerCursor::end()
{

}

void PlayerCursor::update()
{
	int checkVec = 0;

	if (Pad::isPress(PAD_INPUT_LEFT))
	{
		checkVec = 1;
	}
	if (Pad::isPress(PAD_INPUT_RIGHT))
	{
		checkVec = 2;
	}
	if (Pad::isPress(PAD_INPUT_UP))
	{
		checkVec = 3;
	}
	if (Pad::isPress(PAD_INPUT_DOWN))
	{
		checkVec = 4;
	}

	switch (checkVec)
	{
	case 0:
		playerVec.x = 0.0f;
		playerVec.y = 0.0f;
		break;
	case 1:
		playerVec.x = -kCursorVecX;
		playerVec.y = 0.0f;
		break;
	case 2:
		playerVec.x = kCursorVecX;
		playerVec.y = 0.0f;
		break;
	case 3:
		playerVec.x = 0.0f;
		playerVec.y = -kCursorVecX;
		break;
	case 4:
		playerVec.x = 0.0f;
		playerVec.y = kCursorVecX;
		break;
	default:
		break;
	}
	playerPos += playerVec;
}

void PlayerCursor::draw()
{
	DrawCircle(playerPos.x, playerPos.y, kCircleRaddius, GetColor(255, 0, 0), true);
}