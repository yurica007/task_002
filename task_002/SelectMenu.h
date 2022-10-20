#pragma once

#include <vector>
#include "Vec2.h"

class SelectMenu
{
public:
	SelectMenu();
	virtual ~SelectMenu();

	// 初期化、終了処理
	void init();
	void end();

	// 更新
	void update();
	// 描画
	void draw();

	// カーソルの初期化
	void setupCursor();

	// 表示位置の設定
	void setPos(float x, float y);
	void setPos(Vec2 pos);
	// メニュー項目の追加
	void addItem(const char* text);

	void setMenuPos(Vec2 pos) { m_menuPos = pos; }
	void setSize(Vec2 size) { m_size = size; }
	void setItemNum(int num) { m_itemNum = num; }

	int getItemIndex() { return m_selectIndex; }

private:
	class Item
	{
	public:
		Item();
		virtual ~Item();

		// メニュー項目の表示
		void draw(int x, int y, int color);

		// 表示する文字列を設定
		void setText(const char* text);
		// 文字列の幅取得
		int getText();

	private:
		// 表示する文字列
		const char* m_text;
	};

private:
	// 表示位置
	Vec2 m_pos;
	// メニューの選択項目
	std::vector<Item*> m_pItem;
	// メニューの表示位置
	Vec2 m_menuPos;
	// カーソルのサイズ
	Vec2 m_size;
	// メニューの項目数
	int m_itemNum;

	// リピート入力カウンタ
	int m_repeatLeft;
	int m_repeatRight;

	// 選択している項目の番号
	int m_selectIndex;
};