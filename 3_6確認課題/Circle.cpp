#include "Circle.h"
#include <stdio.h>

void Circle::size()
{
	//�~�̌v�Z
	ans = radius * radius * pai;
}

void Circle::draw()
{
	printf("�~�̖ʐ� : %f\n", ans);
}
