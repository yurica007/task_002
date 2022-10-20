#include "SceneMain.h"
#include "DxLib.h"
#include "Pad.h"

void SceneMain::init()
{
	m_isEnd = false;
	m_playerTurn = true;

	m_turnPlayer.init();
	m_turnEnemy.init();
	
	m_pCheckPlayerStatus = true;
	m_pPlayerStatus.init();

	m_pCheckEnemyStatus = true;
	m_pEnemyStatus.init();
}

void SceneMain::end()
{
	m_turnPlayer.end();
	m_turnEnemy.end();
	m_pPlayerStatus.end();
	m_pEnemyStatus.end();
}

void SceneMain::update()
{
	m_playerTurn = m_turnPlayer.isTurnEnd();

	if (m_playerTurn)
	{
		m_turnPlayer.update();
	}
	else
	{
		m_turnEnemy.update();
	}

	m_pPlayerStatus.update();
	m_pEnemyStatus.update();
}

void SceneMain::draw()
{
	if (m_playerTurn) m_turnPlayer.draw();
	else m_turnEnemy.draw();
	m_pPlayerStatus.draw();
	m_pEnemyStatus.draw();
}