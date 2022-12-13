#include "SceneManager.h"
#include "DxLib.h"

SceneManager* SceneManager::GetInstance()
{
	//関数内static変数として宣言する
	static SceneManager instance;

	return &instance;
}

void SceneManager::ChangeScene(int sceneNo)
{
	switch (sceneNo)
	{
		case 0:
			//背景の色を変える
			SetBackgroundColor(255, 0, 0);
			
			//シーン情報などを表示
			DrawFormatString(100, 180, GetColor(255, 255, 255), "SceneNo:%d", sceneNo, true);
			DrawFormatString(100, 200, GetColor(255, 255, 255), "Press Space to Scene Change", true);
			break;

		case 1:
			//背景の色を変える
			SetBackgroundColor(0, 255, 0);

			//シーン情報などを表示
			DrawFormatString(100, 180, GetColor(255, 255, 255), "SceneNo:%d", sceneNo, true);
			DrawFormatString(100, 200, GetColor(255, 255, 255), "Press Space to Scene Change", true);
			break;

		case 2:
			//背景の色を変える
			SetBackgroundColor(0, 0, 255);

			//シーン情報などを表示
			DrawFormatString(100, 180, GetColor(255, 255, 255), "SceneNo:%d", sceneNo, true);
			DrawFormatString(100, 200, GetColor(255, 255, 255), "Press Space to Scene Change", true);
			break;

		case 3:
			//背景の色を変える
			SetBackgroundColor(0, 0, 0);

			//シーン情報などを表示
			DrawFormatString(100, 180, GetColor(255, 255, 255), "SceneNo:%d", sceneNo, true);
			DrawFormatString(100, 200, GetColor(255, 255, 255), "Press Space to Scene Change", true);
			break;
	}
}
