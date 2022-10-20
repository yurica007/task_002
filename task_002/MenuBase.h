#pragma once

class MenuBase
{
public:
	MenuBase() {}
	virtual ~MenuBase() {}

	virtual void init() {}
	virtual void end() {}
	virtual void update() {}
	virtual void draw() {}

	virtual bool isEnd() { return false; }
};