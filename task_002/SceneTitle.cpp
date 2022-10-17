#include "SceneTitle.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	constexpr int kTitlePosX = 500;
	constexpr int kTitlePosY = 360;

	constexpr int kTextPosX = 580;
	constexpr int kTextPosY = 500;
}

void SceneTitle::init()
{
	m_isEnd = false;
}

void SceneTitle::end()
{

}

void SceneTitle::update()
{
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		m_isEnd = true;
	}
}

void SceneTitle::draw()
{
	SetFontSize(32);
	DrawString(kTitlePosX, kTitlePosY, "�^�C�g���\���m�F", GetColor(255, 255, 255));
	SetFontSize(16);
}