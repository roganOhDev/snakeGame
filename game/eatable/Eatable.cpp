//
// Created by Oh DongGeun on 2023/05/18.
//

#include "Eatable.h"
#include<random>

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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1 );

    do {
        x = dist(gen) % width;
        y = dist(gen) % height;
    } while ((x == Hx && y == Hy) || x == width-1 || y == height-1 || x == 0 || y == 0);
}

void Eatable::newPosition(int Hx, int Hy, int width, int height) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist;

    do {
        x = dist(gen) % width;
        y = dist(gen) % height;
    } while ((x == Hx && y == Hy) || x == width-1 || y == height-1 || x == 0 || y == 0);
}