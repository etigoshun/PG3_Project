#pragma once

class Enemy
{
public:
	static bool enemyAliveFlag;

	Enemy() { enemyAliveFlag = true; };
	~Enemy() { enemyAliveFlag = false; }
};