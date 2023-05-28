//
// Created by Oh DongGeun on 2023/05/18.
//

#include "Fruit.h"

Fruit::Fruit() : Eatable() {}

Fruit::Fruit(int Hx, int Hy, int width, int height, SnakeTail *snakeTails, int nTail) : Eatable(Hx, Hy, width, height,
                                                                                                snakeTails, nTail) {}

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
