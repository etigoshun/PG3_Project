#include "Rectangle.h"
#include <stdio.h>

void Rectangle::size()
{
	//��`�̌v�Z
	ans = x * y;
}

void Rectangle::draw()
{
	printf("��`�̖ʐ� : %d", ans);
}