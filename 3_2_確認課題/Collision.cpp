#include <stdio.h>
#include "Collision.h"

//‹éŒ`‚Æ‰~‚Ì“–‚½‚è”»’è
int BoxCircle(int leftTopBoxX, int leftTopBoxY, int rightBottomBoxX, int rightBottomBoxY, int circleX, int circleY, int r)
{
    if ((circleX > leftTopBoxX - r)
        && (circleX < rightBottomBoxX + r)
        && (circleY > leftTopBoxY - r)
        && (circleY < rightBottomBoxY + r)) {
        return 1;
    }
    else {
        return 0;
    }
}