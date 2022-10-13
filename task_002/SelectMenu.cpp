#include "SelectMenu.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	// メニュー項目の間隔
	constexpr int kMenuItemInterval = 200;
}

// =====================================
// SelectMenu::Item
// =====================================
SelectMenu::Item::Item()
{
	m_text = nullptr;
}

SelectMenu::Item::~Item()
{

}

void SelectMenu::Item::draw(int x, int y)
{
	DrawString(x, y, m_text, GetColor(255, 130, 0));
}

void SelectMenu::Item::setText(const char* text)
{
	m_text = text;
}

int SelectMenu::Item::getText()
{
	return GetDrawStringWidth(m_text, strlen(m_text));
}
// =====================================
// SelectMenu::Cursor
// =====================================
SelectMenu::Cursor::Cursor()
{
	m_selectIndex = 0;
	m_itemNum = 0;
	m_repeatLeft = 0;
	m_repeatRight = 0;
}

SelectMenu::Cursor::~Cursor()
{

}

void SelectMenu::Cursor::update()
{
	if (Pad::isPress(PAD_INPUT_LEFT))
	{
		if (m_repeatLeft <= 0)
		{
			m_selectIndex--;
			m_repeatLeft = 8;
			// 左右ループ
			if (m_selectIndex < 0)
			{
				if (Pad::isPress(PAD_INPUT_LEFT))
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
			m_repeatLeft--;
		}
	}
	else
	{
		m_repeatLeft = 0;
	}

	if (Pad::isPress(PAD_INPUT_RIGHT))
	{
		if (m_repeatRight <= 0)
		{
			m_selectIndex++;
			m_repeatRight = 8;
			if (m_selectIndex > m_itemNum - 1)
			{
				if (Pad::isPress(PAD_INPUT_RIGHT))
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
			m_repeatRight--;
		}
	}
	else
	{
		m_repeatRight = 0;
	}
}

void SelectMenu::Cursor::draw()
{
	int posX = m_menuPos.x + kMenuItemInterval * m_selectIndex;
	int posY = m_menuPos.y;

	DrawBox(posX, posY, posX + m_size.x, posY + m_size.y, GetColor(255, 0, 0), false);
}

// =====================================
// SelectMenu
// =====================================
SelectMenu::SelectMenu()
{
	m_pos.x = 0.0f;
	m_pos.y = 0.0f;
	m_checkFight = false;
}

SelectMenu::~SelectMenu()
{

}

void SelectMenu::init()
{

}
void SelectMenu::end()
{
	for (auto& pItem : m_pItem)
	{
		delete pItem;
	}
	m_pItem.clear();

}

void SelectMenu::update()
{
	m_cursor.update();
}

void SelectMenu::draw()
{
	int width = getWindowWidth();
	int height = getWindowHeight();

	for (int i = 0; i < m_pItem.size(); i++)
	{
		m_pItem[i]->draw(m_pos.x + i * kMenuItemInterval, m_pos.y);
	}
	m_cursor.draw();
}

void SelectMenu::setupCursor()
{
	m_cursor.setMenuPos(m_pos);
	m_cursor.setSize(Vec2(getWindowWidth(), getWindowHeight()));
	m_cursor.setItemNum(m_pItem.size());
}

void SelectMenu::setPos(float x, float y)
{
	setPos(Vec2(x, y));
}

void SelectMenu::setPos(Vec2 pos)
{
	m_pos = pos;
}

void SelectMenu::addItem(const char* text)
{
	Item* pItem = new Item;
	pItem->setText(text);
	m_pItem.push_back(pItem);

}

int SelectMenu::getWindowWidth()
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
int SelectMenu::getWindowHeight()
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
	return height / 2;
}