#include "SelectItem.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	// ���j���[���ڂ̊Ԋu
	constexpr int kMenuItemInterval = 200;
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
	DrawString(x, y, m_text, GetColor(255, 130, 0));
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
	m_repeatLeft = 0;
	m_repeatRight = 0;
}

SelectItem::Cursor::~Cursor()
{

}

void SelectItem::Cursor::update()
{
	if (Pad::isPress(PAD_INPUT_LEFT))
	{
		if (m_repeatLeft <= 0)
		{
			m_selectIndex--;
			m_repeatLeft = 8;
			// ���E���[�v
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

void SelectItem::Cursor::draw()
{
	int posX = m_menuPos.x + kMenuItemInterval * m_selectIndex;
	int posY = m_menuPos.y;

	DrawBox(posX, posY, posX + m_size.x, posY + m_size.y, GetColor(255, 0, 0), false);
}

// =====================================
// SelectMenu
// =====================================
SelectItem::SelectItem()
{
	m_pos.x = 0.0f;
	m_pos.y = 0.0f;
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
	int width = getWindowWidth();
	int height = getWindowHeight();

	for (int i = 0; i < m_pItem.size(); i++)
	{
		m_pItem[i]->draw(m_pos.x + i * kMenuItemInterval, m_pos.y);
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
	// ��ԍL�����j���[���ڂ̕����E�B���h�E�T�C�Y�ɂ���
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
	// ��ԍL�����j���[���ڂ̕����E�B���h�E�T�C�Y�ɂ���
	for (auto& pItem : m_pItem)
	{
		if (height < pItem->getText())
		{
			height = pItem->getText();
		}
	}
	return height / 2;
}