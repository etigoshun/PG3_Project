#pragma once

class Enemy
{
public:
	//コンストラクタ、デストラクタ
	Enemy();
	~Enemy();

	//行動
	void Approach();
	void Shoot();
	void GetAway();

	//更新
	void Update();

	//描画
	void Draw();

private:
	//関数ポインタテーブル
	static void(Enemy::* pFuncTable[])();

	//行動フェーズ
	int phase_;
};

