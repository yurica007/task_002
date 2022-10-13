#pragma once

#include "MenuBase.h"
#include "Vec2.h"
#include "SelectMenu.h"

class MenuFight : public MenuBase
{
public:
	MenuFight();
	virtual ~MenuFight();

	virtual void init();
	virtual void end();
	virtual void update();
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }

private:
	// �U���J�[�\���̉��̍��W���
	float m_damageCursorCenterX;
	// �U���J�[�\���̍��W���
	Vec2 m_damageCursorPos;
	// �U���J�[�\���̈ړ����x
	float m_damageCursorVec;

	// �U����
	int ATK;
	// �^����_���[�W��
	float m_dealtDamage;

	bool m_isEnd;
};