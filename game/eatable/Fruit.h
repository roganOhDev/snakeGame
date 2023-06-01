//
// Created by Oh DongGeun on 2023/05/18.
//

#ifndef SNAKEGAME_FRUIT_H
#define SNAKEGAME_FRUIT_H


#include "Eatable.h"

class Fruit : public Eatable {
public:
    Fruit();

    Fruit(int x, int y);

    char draw();

    Type getType();
    bool isWall();
};


#endif //SNAKEGAME_FRUIT_H
