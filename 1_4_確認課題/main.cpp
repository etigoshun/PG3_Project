#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <random>
#include <time.h>
#include <functional>

typedef void (*PFunc)(int, bool, bool);

//コールバック関数
void DispResult(int result, bool resultFlag, bool ansFlag)
{
	if (ansFlag == resultFlag)
	{
		printf("\n大正解！！\n");
	}
	else if (ansFlag != resultFlag)
	{
		printf("\n不正解！！\n");
	}

	if (resultFlag == false)
	{
		printf("%d\n", result);
		printf("半です！！\n");
	}
	if (resultFlag == true)
	{
		printf("%d\n", result);
		printf("丁です！！\n");
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
		printf("ハゲタコ\n");
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

	printf("半(奇数)なら1、丁(偶数)なら2を入力してください\n");

	ansFlag = AnswerKey(ansFlag);
	resultFlag = Result(result(resultRand), resultFlag);

	PFunc p;
	p = DispResult;
	SetTimeOut(p, 3, result(resultRand), resultFlag, ansFlag);

	return 0;
}