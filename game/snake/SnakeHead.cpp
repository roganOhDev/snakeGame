//
// Created by Oh DongGeun on 2023/05/19.
//

#include "SnakeHead.h"

SnakeHead::SnakeHead(int x, int y) : Object(x, y) {}

char SnakeHead::draw() {
    attrset(COLOR_PAIR(5));
    return 'O';
}

int SnakeHead::getY() {
    return y;
}

int SnakeHead::getX() {
    return x;
}

void SnakeHead::moveLeft(int &hx){
    hx = --x;
}
void SnakeHead::moveRight(int &hx){
    hx = ++x;
}
void SnakeHead::moveUp(int &hy){
    hy = --y;
}
void SnakeHead::moveDown(int &hy){
    hy = ++y;
}
void SnakeHead::moveToGate(Gate gate, int &hx, int &hy){
    hx = x = gate.getX();
    hy = y = gate.getY();
}

Type SnakeHead::getType() {
    return SNAKE_HEAD;
}

bool SnakeHead::isWall() {
    return false;
}
