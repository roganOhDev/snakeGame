//
// Created by Oh DongGeun on 2023/05/19.
//

#include "Object.h"

Object::Object() {}

Object::Object(int x, int y) {
    this->x = x;
    this->y = y;
}

char Object::draw() {
    attrset(COLOR_PAIR(0));
    return ' ';
}

Type Object::getType() {
    return OBJECT;
}

int Object::getX() {
    return x;
}

int Object::getY() {
    return y;
}

bool Object::isWall() {
    return false;
}
