#include "SceneBase.h"
#include "TurnPlayer.h"
#include "TurnEnemy.h"
#include "MenuPlayerStatus.h"

class SceneMain : public SceneBase
{
public:
	SceneMain() {
		m_isEnd = false;
		m_playerTurn = false;
		m_pCheckPlayerStatus = false;
		m_pCheckEnemyStatus = false;
	}
	virtual ~SceneMain() {}

	virtual void init();
	virtual void end();
	virtual void update();
	virtual void draw();
	virtual bool isEnd() { return m_isEnd; }

private:
	bool m_isEnd;
	bool m_playerTurn;

	TurnPlayer m_turnPlayer;
	TurnEnemy m_turnEnemy;

	MenuPlayerStatus m_pPlayerStatus;
	bool m_pCheckPlayerStatus;

	MenuEnemyStatus m_pEnemyStatus;
	bool m_pCheckEnemyStatus;
};