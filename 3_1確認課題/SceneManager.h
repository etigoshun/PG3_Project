#pragma once
class SceneManager final
{
private:

public:
	//インスタンスの取得
	static SceneManager* GetInstance();

	//シーン切り替え
	void ChangeScene(int sceneNo);
};

