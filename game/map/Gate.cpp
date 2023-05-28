//
// Created by Oh DongGeun on 2023/05/25.
//

#include<random>
#include "Gate.h"

char Gate::draw() {
    attrset(COLOR_PAIR(4));
    return 'G';
}

Type Gate::getType() {
    return GATE;
}

bool Gate::isWall() {
    return false;
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

Gate Gate::findOtherGate(Gate *gates, Object *gate) {
    for (int i = 0; i < 2; i++) {
        if (gates[i].getX() != gate->getX() || gates[i].getY() != gate->getY()) {
            return gates[i];
        }
    }
}
