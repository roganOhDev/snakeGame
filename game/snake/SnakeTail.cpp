//
// Created by Oh DongGeun on 2023/05/19.
//

#include "SnakeTail.h"

SnakeTail::SnakeTail(int x, int y) : Object(x, y) {}

char SnakeTail::draw() {
    attrset(COLOR_PAIR(6));
    return 'o';
}

void SnakeTail::setPosition(int _x, int _y) {
    x = _x;
    y = _y;
}

Type SnakeTail::getType() {
    return SNAKE_TAIL;
}

bool SnakeTail::isWall() {
    return false;
}
