//
// Created by Oh DongGeun on 2023/05/19.
//

#include "SnakeTail.h"

SnakeTail::SnakeTail(int x, int y) : Object(x, y) {}

char SnakeTail::draw() {
    return 'o';
}

int SnakeTail::getX() {
    return x;
}

int SnakeTail::getY() {
    return y;
}

void SnakeTail::setPosition(int _x, int _y) {
    x = _x;
    y = _y;
}

Type SnakeTail::getType() {
    return SNAKE_TAIL;
}
