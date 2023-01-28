#include "Enemy.h"
#include <stdio.h>

int main()
{
	Enemy* enemy = new Enemy();
	int input;

	while (true)
	{
		//‘±‚¯‚é‚©‚Ç‚¤‚©“ü—Í‚³‚¹‚é
		printf("0:exit 1:continue ==> ");
		scanf_s("%d", &input);
		if (input == 0) break;

		//s“®
		enemy->Update();
		enemy->Draw();
	}
	delete enemy;

	return 0;
}