#pragma once

#include "SceneTitle.h"
#include "SceneMain.h"
#include "TurnPlayer.h"
#include "TurnEnemy.h"
#include "MenuFight.h"
#include "MenuAct.h"
#include "MenuItem.h"
#include "MenuMercy.h"
#include "MenuPlayerStatus.h"
#include "SelectMenu.h"

class SceneManager
{
public:
	// ƒV[ƒ“‚Ìí—Ş’è‹`
	typedef enum SceneKind
	{
		kSceneKindTitle,
		kSceneKindMain,

		kSceneKindNum
	}SceneKind;

	typedef enum MenuKind
	{
		kMenuKindFight,
		kMenuKindAct,
		kMenuKindItem,
		kMenuKindMercy,

		kMenuKindNum
	}MenuKind;

public:
	SceneManager();
	virtual ~SceneManager();

	void init();
	void end();

	void update();

	void draw();


private:
	SceneKind	m_Scenekind;
	MenuKind	m_Menukind;

	SceneTitle	m_title;
	SceneMain m_main;
	TurnPlayer	m_turnPlayer;
	TurnEnemy m_turnEnemy;

	MenuFight m_fight;
	MenuAct m_act;
	MenuItem m_item;
	MenuMercy m_mercy;

	SelectMenu m_selectMenu;

	bool isEnd;
	bool isReturn;
};