#include "Enemy.h"
#include <stdio.h>

//�����o�֐��|�C���^�e�[�u���̗p��
void (Enemy::* Enemy::pFuncTable[])() =
{
	&Enemy::Approach,	// [0]
	&Enemy::Shoot,		// [1]
	&Enemy::GetAway		// [2]
};

Enemy::Enemy()
{
	phase_ = 0;
}

Enemy::~Enemy()
{}

void Enemy::Approach()
{
	printf("�߂Â�\n");
}

void Enemy::Shoot()
{
	printf("�ߐ�\n");
}

void Enemy::GetAway()
{
	printf("���E\n");
}

//�X�V
void Enemy::Update()
{
	//�f�o�b�O�p
	printf("phase_ : %d\n", phase_);

	//���݂̍s���t�F�[�Y�����s����
	(this->*pFuncTable[phase_])();

	//���̍s���t�F�[�Y�Ɉڍs����
	phase_++;
	if (phase_ == 3)
	{
		phase_ = 0;
	}
}

//�`��
void Enemy::Draw()
{
	printf("(enemy draw)\n");
}
