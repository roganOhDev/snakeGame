//
// Created by Oh DongGeun on 2023/05/18.
//

#include "Eatable.h"
#include<random>

int Eatable::getX() const {
    return x;
}

int Eatable::getY() const {
    return y;
}

Eatable::Eatable() {}

Eatable::Eatable(int x, int y) : Object(x, y) {}

void Eatable::newPosition(int Hx, int Hy, SnakeTail *snakeTails, int nTail, Object *blanks,
                          int nBlank) {
    bool onTail;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, nBlank - 1);

    do {
        onTail = false;
        int randIndex = dist(gen);
        x = blanks[randIndex].getX();
        y = blanks[randIndex].getY();

        for (int i = 0; i < nTail; i++) {
            if (snakeTails[i].getX() == x && snakeTails[i].getY() == y) {
                onTail = true;
                break;
            }

            if (nTail == 0) {
                break;
            }
        }
    } while ((x == Hx && y == Hy) || onTail);
}
