//
// Created by Oh DongGeun on 2023/05/18.
//

#ifndef SNAKEGAME_FRUIT_H
#define SNAKEGAME_FRUIT_H


#include "Eatable.h"

class Fruit : public Eatable {
public:
    Fruit();

    Fruit(int Hx, int Hy, int width, int height);

    char draw();

    Type getType();
};


#endif //SNAKEGAME_FRUIT_H
