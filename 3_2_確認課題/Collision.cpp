#include <stdio.h>
#include "Collision.h"

//‹éŒ`‚Æ‰~‚Ì“–‚½‚è”»’è
bool BoxCircle(int leftTopBoxX, int leftTopBoxY, int rightBottomBoxX, int rightBottomBoxY, int circleX, int circleY, int r)
{
    if ((circleX > leftTopBoxX - r)
        && (circleX < rightBottomBoxX + r)
        && (circleY > leftTopBoxY - r)
        && (circleY < rightBottomBoxY + r)) {
        return true;
    }
    else {
        return false;
    }
}