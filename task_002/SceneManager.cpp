#include "SceneManager.h"
#include <cassert>
#include "Pad.h"

SceneManager::SceneManager()
{
	m_Scenekind = kSceneKindTitle;
	m_Menukind = kMenuKindNum;
	isEnd = false;
	isReturn = false;
}
SceneManager::~SceneManager()
{

}

void SceneManager::init()
{
	SceneKind sceneKind = kSceneKindTitle;
	m_Scenekind = sceneKind;

	switch (m_Scenekind)
	{
	case SceneManager::kSceneKindTitle:
		m_title.init();
		break;
	case SceneManager::kSceneKindMain:
		m_main.init();
		break;
	default:
		assert(false);
		break;
	}
}

void SceneManager::end()
{
	switch (m_Scenekind)
	{
	case SceneManager::kSceneKindTitle:
		m_title.end();
		break;
	case SceneManager::kSceneKindMain:
		m_main.end();
		break;
	default:
		assert(false);
		break;
	}
}

void SceneManager::update()
{
	Pad::update();

	switch (m_Scenekind)
	{
	case SceneManager::kSceneKindTitle:
		m_title.update();
		isEnd = m_title.isEnd();
		break;
	case SceneManager::kSceneKindMain:
		m_main.update();
		isEnd = m_main.isEnd();
		break;
	default:
		assert(false);
		break;
	}
	
	if (isEnd)
	{
		switch (m_Scenekind)
		{
		case SceneManager::kSceneKindTitle:
			m_title.end();
			m_main.init();
			m_Scenekind = kSceneKindMain;
			break;
		case SceneManager::kSceneKindMain:
			m_main.end();
			m_title.init();
			m_Scenekind = kSceneKindTitle;
			break;
		default:
			assert(false);
			break;
		}
	}
}

void SceneManager::draw()
{
	switch (m_Scenekind)
	{
	case SceneManager::kSceneKindTitle:
		m_title.draw();
		break;
	case SceneManager::kSceneKindMain:
		m_main.draw();
		break;
	default:
		assert(false);
		break;
	}
}