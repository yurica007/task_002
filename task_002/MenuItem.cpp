#include "MenuItem.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	// lŠp‚Ì’†‰›‚ÌˆÊ’u
	constexpr float kCenterPosX = 640.0f;
	constexpr float kCenterPosY = 500.0f;

	// lŠp‚Ìc‰¡‚Ì”¼Œa
	constexpr float kWidthLen = 360.0f;
	constexpr float kHeightLen = 120.0f;
}

void MenuItem::init()
{
	m_isEnd = false;
	m_checkMenu = true;
	m_checkMasage = false;

	m_menu.init();
	m_menu.addItem("‚ ");
	m_menu.addItem("‚¢");
	m_menu.addItem("‚¤");
	m_menu.addItem("‚¦");
	m_menu.addItem("‚¨");

	m_menu.setPos(kCenterPosX - kWidthLen, kCenterPosY - kHeightLen);
	m_menu.setupCursor();
}

void MenuItem::end()
{
	m_menu.end();
}

void MenuItem::update()
{
	if (Pad::isTrigger(PAD_INPUT_1))
	{
		m_checkMenu = false;
		m_checkMasage = true;
	}
	if (Pad::isTrigger(PAD_INPUT_2)) m_isEnd = true;

	if (m_checkMasage) m_menu.displayItem();
	if (m_checkMenu) m_menu.update();
}

void MenuItem::draw()
{
	if (m_checkMenu) m_menu.draw();
}