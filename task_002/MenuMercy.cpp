#include "MenuMercy.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	constexpr float kMasagePosX = 550.0f;
	constexpr float kMasagePosY = 500.0f;
}

void MenuMercy::init()
{
	m_isEnd = false;
//	m_isReturn = false;
}

void MenuMercy::end()
{

}

void MenuMercy::update()
{
	if (Pad::isTrigger(PAD_INPUT_1)) m_isEnd = true;
}

void MenuMercy::draw()
{
	DrawStringF(kMasagePosX, kMasagePosY, "Not yet implemented", GetColor(125, 125, 125));
}