//
// Created by Oh DongGeun on 2023/05/25.
//

#include<random>
#include "Gate.h"

char Gate::draw() {
    return 'G';
}

Type Gate::getType() {
    return GATE;
}


Gate::Gate(Wall *walls, int nWall) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, nWall - 1);

    int wallNum = dist(gen);

    this->x = walls[wallNum].getX();
    this->y = walls[wallNum].getY();
}

Gate::Gate(Gate *gate, Wall *walls, int nWall) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, nWall - 1);

    do {
        int wallNum = dist(gen);

        this->x = walls[wallNum].getX();
        this->y = walls[wallNum].getY();
    } while (gate->getX() == walls[dist(gen)].getX() && gate->getY() == walls[dist(gen)].getY());
}
