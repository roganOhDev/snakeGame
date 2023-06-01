//
// Created by Oh DongGeun on 2023/05/18.
//

#include "Eatable.h"

int Eatable::getX() const {
    return x;
}

int Eatable::getY() const {
    return y;
}

Eatable::Eatable() {}

Eatable::Eatable(int x, int y) : Object(x, y) {}

void Eatable::newPosition(int x, int y) {
    this->x = x;
    this->y = y;
}
