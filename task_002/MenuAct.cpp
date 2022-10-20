#include "MenuAct.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	constexpr float kMasagePosX = 550.0f;
	constexpr float kMasagePosY = 500.0f;
}

void MenuAct::init()
{
	m_isEnd = false;
//	m_isReturn = false;
}

void MenuAct::end()
{

}

void MenuAct::update()
{
	if (Pad::isTrigger(PAD_INPUT_1)) m_isEnd = true;
}

void MenuAct::draw()
{
	DrawStringF(kMasagePosX, kMasagePosY, "Not yet implemented", GetColor(255, 255, 255));
}