//
// Created by Oh DongGeun on 2023/05/20.
//

#include "ImmuneWall.h"

ImmuneWall::ImmuneWall(int x, int y) : Object(x, y) {}

char ImmuneWall::draw() {
    attrset(COLOR_PAIR(1));
    return '@';
}

Type ImmuneWall::getType() {
    return IMMUNE_WALL;
}

bool ImmuneWall::isWall() {
    return true;
}