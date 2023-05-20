//
// Created by Oh DongGeun on 2023/05/20.
//

#include "ImmuneWall.h"

ImmuneWall::ImmuneWall(int x, int y) : Object(x, y) {}

char ImmuneWall::draw() {
    return '@';
}

Type ImmuneWall::getType() {
    return IMMUNEWALL;
}