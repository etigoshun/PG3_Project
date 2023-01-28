#pragma once
class Enemy
{
public:
	static bool enemyFlag;

	Enemy() { enemyFlag = true; };
	~Enemy() { enemyFlag = false; }
};

