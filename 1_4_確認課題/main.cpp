#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <random>
#include <time.h>
#include <functional>

typedef void (*PFunc)(int, bool, bool);

//�R�[���o�b�N�֐�
void DispResult(int result, bool resultFlag, bool ansFlag)
{
	if (ansFlag == resultFlag)
	{
		printf("\n�吳���I�I\n");
	}
	else if (ansFlag != resultFlag)
	{
		printf("\n�s�����I�I\n");
	}

	if (resultFlag == false)
	{
		printf("%d\n", result);
		printf("���ł��I�I\n");
	}
	if (resultFlag == true)
	{
		printf("%d\n", result);
		printf("���ł��I�I\n");
	}
}

void SetTimeOut(PFunc p, int second, int result, bool resultFlag, bool ansFlag)
{

	Sleep(second * 1000);

	p(result, resultFlag, ansFlag);
}

bool AnswerKey(bool ansFlag)
{
	int ans;
	scanf_s("%d", &ans);

	if (ans == 1)
	{
		ansFlag = false;
	}
	else if (ans == 2)
	{
		ansFlag = true;
	}
	else
	{
		printf("�n�Q�^�R\n");
	}

	return ansFlag;

}

bool Result(int result, bool resultFlag)
{
	if (result % 2 == 0)
	{
		resultFlag = true;
	}
	else
	{
		resultFlag = false;
	}

	return resultFlag;
}

int main()
{
	srand(time(nullptr));
	int resultRand = rand() % 12 + 1;
	bool resultFlag = false;
	bool ansFlag = false;

	std::function<int(int)> result = [](int result) {return result; };

	printf("��(�)�Ȃ�1�A��(����)�Ȃ�2����͂��Ă�������\n");

	ansFlag = AnswerKey(ansFlag);
	resultFlag = Result(result(resultRand), resultFlag);

	PFunc p;
	p = DispResult;
	SetTimeOut(p, 3, result(resultRand), resultFlag, ansFlag);

	return 0;
}