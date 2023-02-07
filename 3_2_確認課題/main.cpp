#include "DxLib.h"
#include "Enemy.h"
#include "Collision.h"

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "xx2x_xx_ナマエ: タイトル";

// ウィンドウ横幅
const int WIN_WIDTH = 600;

// ウィンドウ縦幅
const int WIN_HEIGHT = 400;

bool Enemy::enemyAliveFlag;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み


	// ゲームループで使う変数の宣言
	Enemy* enemy[5];

	for (int i = 0; i < 5; i++)
	{
		enemy[i] = new Enemy;
	}

	int enemyPosX[5] = { 300,300,300,300,300 };
	int enemyPosY[5] = { 50 ,90,130,170,210 };
	int enemyRadius = 8;
	int enemySpeed = 5;
	bool enemyFlag = false;
	bool enemyDeathFlag[5] = { false };

	int playerPosX = 100;
	int playerPosY = 100;
	int playerRadius = 16;
	int playerSpeed = 3;

	int playerBulletX = 0;
	int playerBulletY = 0;
	int playerBulletRadius = 8;
	bool playerBulletFlag = false;

	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; i++)
		{
			oldkeys[i] = keys[i];
		}
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理

		//移動
		if (keys[KEY_INPUT_W] == 1)
		{
			playerPosY -= playerSpeed;
		}
		if (keys[KEY_INPUT_S] == 1)
		{
			playerPosY += playerSpeed;
		}
		if (keys[KEY_INPUT_D] == 1)
		{
			playerPosX += playerSpeed;
		}
		if (keys[KEY_INPUT_A] == 1)
		{
			playerPosX -= playerSpeed;
		}

		//球と敵の当たり判定
		if (playerBulletFlag == true)
		{
			for (int i = 0; i < 5; i++)
			{
				if (BoxCircle(enemyPosX[i] - enemyRadius, enemyPosY[i] - enemyRadius, enemyPosX[i] + enemyRadius, enemyPosY[i] + enemyRadius,
					playerBulletX, playerBulletY, playerBulletRadius) == true)
				{
					enemy[i]->enemyAliveFlag = false;
				}
			}

		}

		//弾を撃つ
		if (playerBulletFlag == false)
		{
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
			{
				playerBulletFlag = true;
			}
		}

		//弾の移動処理
		if (playerBulletFlag == true)
		{
			playerBulletX += 2;
		}
		else
		{
			playerBulletX = playerPosX;
			playerBulletY = playerPosY;
		}


		// 描画処理

		//プレイヤーの描画
		DrawBox(playerPosX - playerRadius, playerPosY - playerRadius, playerPosX + playerRadius, playerPosY + playerRadius, GetColor(255, 255, 255), true);
		//弾の描画
		DrawCircle(playerBulletX, playerBulletY, playerBulletRadius, GetColor(255, 0, 255), true);

		//敵の描画
		for (int i = 0; i < 5; i++)
		{
			if (enemy[i]->enemyAliveFlag == true)
			{
				DrawBox(enemyPosX[i] - enemyRadius, enemyPosY[i] - enemyRadius, enemyPosX[i] + enemyRadius, enemyPosY[i] + enemyRadius, GetColor(255, 0, 0), true);
			}
		}

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	//敵のデリート
	for (int i = 0; i < 5; i++)
	{
		delete enemy[i];
	}

	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}