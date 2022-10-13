#include "SceneTitle.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	constexpr int kTitlePosX = 600;
	constexpr int kTitlePosY = 360;

	constexpr int kTextPosX = 610;
	constexpr int kTextPosY = 390;
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
	if (Pad::isTrigger(PAD_INPUT_1))
	{
		m_isEnd = true;
	}
}

void SceneTitle::draw()
{
	DrawString(kTitlePosX, kTitlePosY, "タイトル表示確認", GetColor(255, 255, 255));
	DrawString(kTextPosX, kTextPosY, "Plese Pless Z", GetColor(255, 255, 255));
}