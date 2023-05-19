//
// Created by Oh DongGeun on 2023/05/19.
//

#include "Wall.h"

Wall::Wall(int x, int y) : Object(x, y) {}

char Wall::draw() {
    return '#';
}

Type Wall::getType() {
    return WALL;
}
