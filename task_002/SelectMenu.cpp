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

void SelectMenu::Item::draw(int x, int y, int color)
{
	DrawString(x, y, m_text, color);
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
// SelectMenu
// =====================================
SelectMenu::SelectMenu()
{
	m_pos.x = 0.0f;
	m_pos.y = 0.0f;
	m_selectIndex = 0;
	m_itemNum = 0;
	m_repeatLeft = 0;
	m_repeatRight = 0;
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

void SelectMenu::draw()
{
	int color = 0;
	for (int i = 0; i < m_pItem.size(); i++)
	{
		if (i == m_selectIndex)
		{
			color = GetColor(255, 0, 0);
		}
		else
		{
			color = GetColor(255, 130, 0);
		}
		m_pItem[i]->draw(m_pos.x + i * kMenuItemInterval, m_pos.y, color);
	}
}

void SelectMenu::setupCursor()
{
	setMenuPos(m_pos);
	setItemNum(m_pItem.size());
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