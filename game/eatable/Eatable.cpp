//
// Created by Oh DongGeun on 2023/05/18.
//

#include "Eatable.h"

void Eatable::setX(int _x) {
    x = _x;
}

int Eatable::getX() const {
    return x;
}

void Eatable::setY(int _y) {
    y = _y;
}

int Eatable::getY() const {
    return y;
}

Eatable::Eatable() {

}

Eatable::Eatable(int Hx, int Hy, int width, int height) {
    do {
        x = rand() % width;
        y = rand() % height;
    } while (x == Hx && y == Hy);
}

void Eatable::newPosition(int Hx, int Hy, int width, int height) {
    do {
        x = rand() % width;
        y = rand() % height;
    } while (x == Hx && y == Hy);
}