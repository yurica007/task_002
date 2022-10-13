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

MenuItem::MenuItem()
{
	m_isEnd = false;
}

MenuItem::~MenuItem()
{

}

void MenuItem::init()
{
	m_isEnd = false;

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
	m_menu.update();
}

void MenuItem::draw()
{
	m_menu.draw();
}