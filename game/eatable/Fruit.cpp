//
// Created by Oh DongGeun on 2023/05/18.
//

#include "Fruit.h"

Fruit::Fruit() : Eatable() {}

Fruit::Fruit(int x, int y) : Eatable(x, y) {}

char Fruit::draw() {
    attrset(COLOR_PAIR(3));
    return 'F';
}

Type Fruit::getType() {
    return FRUIT;
}

bool Fruit::isWall() {
    return false;
}
