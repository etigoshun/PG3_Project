#include "DxLib.h"
#include "Enemy.h"
#include "Collision.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "xx2x_xx_�i�}�G: �^�C�g��";

// �E�B���h�E����
const int WIN_WIDTH = 600;

// �E�B���h�E�c��
const int WIN_HEIGHT = 400;

bool Enemy::enemyAliveFlag;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���


	// �Q�[�����[�v�Ŏg���ϐ��̐錾
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

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

	// �Q�[�����[�v
	while (true) {
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; i++)
		{
			oldkeys[i] = keys[i];
		}
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����

		//�ړ�
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

		//���ƓG�̓����蔻��
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

		//�e������
		if (playerBulletFlag == false)
		{
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
			{
				playerBulletFlag = true;
			}
		}

		//�e�̈ړ�����
		if (playerBulletFlag == true)
		{
			playerBulletX += 2;
		}
		else
		{
			playerBulletX = playerPosX;
			playerBulletY = playerPosY;
		}


		// �`�揈��

		//�v���C���[�̕`��
		DrawBox(playerPosX - playerRadius, playerPosY - playerRadius, playerPosX + playerRadius, playerPosY + playerRadius, GetColor(255, 255, 255), true);
		//�e�̕`��
		DrawCircle(playerBulletX, playerBulletY, playerBulletRadius, GetColor(255, 0, 255), true);

		//�G�̕`��
		for (int i = 0; i < 5; i++)
		{
			if (enemy[i]->enemyAliveFlag == true)
			{
				DrawBox(enemyPosX[i] - enemyRadius, enemyPosY[i] - enemyRadius, enemyPosX[i] + enemyRadius, enemyPosY[i] + enemyRadius, GetColor(255, 0, 0), true);
			}
		}

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	//�G�̃f���[�g
	for (int i = 0; i < 5; i++)
	{
		delete enemy[i];
	}

	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}