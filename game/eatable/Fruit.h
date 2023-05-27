//
// Created by Oh DongGeun on 2023/05/18.
//

#ifndef SNAKEGAME_FRUIT_H
#define SNAKEGAME_FRUIT_H


#include "Eatable.h"
#include "../snake/SnakeTail.h"

class Fruit : public Eatable {
public:
    Fruit();

    Fruit(int Hx, int Hy, int width, int height, SnakeTail *snakeTail, int nTail);

    char draw();

    Type getType();
    bool isWall();
};


#endif //SNAKEGAME_FRUIT_H
