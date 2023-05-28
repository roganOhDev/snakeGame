//
// Created by Oh DongGeun on 2023/05/18.
//

#include "Poison.h"

Poison::Poison() : Eatable() {}

Poison::Poison(int x, int y) : Eatable(x, y) {}

char Poison::draw() {
    attrset(COLOR_PAIR(2));
    return 'P';
}

Type Poison::getType() {
    return POISON;
}

bool Poison::isWall() {
    return false;
}
