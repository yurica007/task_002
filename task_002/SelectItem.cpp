#include "SelectItem.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	constexpr float kSetPosX = 450.0f;
	constexpr float kSetPosY = 420.0f;

	constexpr float kCircleRadius = 5.0f;
}

// =====================================
// SelectMenu::Item
// =====================================
SelectItem::Item::Item()
{
	m_text = nullptr;
}

SelectItem::Item::~Item()
{

}

void SelectItem::Item::draw(int x, int y)
{
	DrawString(x, y, m_text, GetColor(255, 255, 255));
}

void SelectItem::Item::setText(const char* text)
{
	m_text = text;
}

int SelectItem::Item::getText()
{
	return GetDrawStringWidth(m_text, strlen(m_text));
}

// =====================================
// SelectMenu::Cursor
// =====================================
SelectItem::Cursor::Cursor()
{
	m_selectIndex = 0;
	m_itemNum = 0;
	m_repeatUp = 0;
	m_repeatDown = 0;
}

SelectItem::Cursor::~Cursor()
{

}

void SelectItem::Cursor::update()
{
	if (Pad::isPress(PAD_INPUT_UP))
	{
		if (m_repeatUp <= 0)
		{
			m_selectIndex--;
			m_repeatUp = 8;
			// 上下ループ
			if (m_selectIndex < 0)
			{
				if (Pad::isPress(PAD_INPUT_UP))
				{
					m_selectIndex = m_itemNum - 1;
				}
				else
				{
					m_selectIndex = 0;
				}
			}
		}
		else
		{
			m_repeatUp--;
		}
	}
	else
	{
		m_repeatUp = 0;
	}

	if (Pad::isPress(PAD_INPUT_DOWN))
	{
		if (m_repeatDown <= 0)
		{
			m_selectIndex++;
			m_repeatDown = 8;
			if (m_selectIndex > m_itemNum - 1)
			{
				if (Pad::isPress(PAD_INPUT_DOWN))
				{
					m_selectIndex = 0;
				}
				else
				{
					m_selectIndex = m_itemNum - 1;
				}
			}
		}
		else
		{
			m_repeatDown--;
		}
	}
	else
	{
		m_repeatDown = 0;
	}
}

void SelectItem::Cursor::draw()
{
	int posX = m_menuPos.x - 20;
	int posY = m_menuPos.y + 30 * m_selectIndex + 5;

	DrawCircle(posX, posY, kCircleRadius, GetColor(255, 255, 255), true);
}

// =====================================
// SelectMenu
// =====================================
SelectItem::SelectItem()
{
	m_pos.x = kSetPosX;
	m_pos.y = kSetPosY;
}

SelectItem::~SelectItem()
{

}

void SelectItem::init()
{

}
void SelectItem::end()
{
	for (auto& pItem : m_pItem)
	{
		delete pItem;
	}
	m_pItem.clear();
}

void SelectItem::update()
{
	m_cursor.update();
}

void SelectItem::draw()
{
	for (int i = 0; i < m_pItem.size(); i++)
	{
		m_pItem[i]->draw(m_pos.x, m_pos.y + i * 30);
	}
	m_cursor.draw();
}

void SelectItem::setupCursor()
{
	m_cursor.setMenuPos(m_pos);
	m_cursor.setSize(Vec2(getWindowWidth(), getWindowHeight()));
	m_cursor.setItemNum(m_pItem.size());
}

void SelectItem::setPos(float x, float y)
{
	setPos(Vec2(x, y));
}

void SelectItem::setPos(Vec2 pos)
{
	pos.x = kSetPosX;
	pos.y = kSetPosY;

	m_pos = pos;
}

void SelectItem::addItem(const char* text)
{
	Item* pItem = new Item;
	pItem->setText(text);
	m_pItem.push_back(pItem);
}

int SelectItem::getWindowWidth()
{
	int width = 0;
	// 一番広いメニュー項目の幅をウィンドウサイズにする
	for (auto& pItem : m_pItem)
	{
		if (width < pItem->getText())
		{
			width = pItem->getText();
		}
	}
	return width;
}
int SelectItem::getWindowHeight()
{
	int height = 0;
	// 一番広いメニュー項目の幅をウィンドウサイズにする
	for (auto& pItem : m_pItem)
	{
		if (height < pItem->getText())
		{
			height = pItem->getText();
		}
	}
	return height;
}

void SelectItem::displayItem()
{
	switch (m_cursor.getSelectIndex())
	{
	case 0:DrawStringF(kSetPosX, kSetPosY, "あ", GetColor(255, 255, 255)); break;
	case 1:DrawStringF(kSetPosX, kSetPosY, "い", GetColor(255, 255, 255)); break;
	case 2:DrawStringF(kSetPosX, kSetPosY, "う", GetColor(255, 255, 255)); break;
	case 3:DrawStringF(kSetPosX, kSetPosY, "え", GetColor(255, 255, 255)); break;
	case 4:DrawStringF(kSetPosX, kSetPosY, "お", GetColor(255, 255, 255)); break;
	default: break;
	}
}