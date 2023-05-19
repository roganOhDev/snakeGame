//
// Created by Oh DongGeun on 2023/05/18.
//

#ifndef SNAKEGAME_POISON_H
#define SNAKEGAME_POISON_H

#include "Eatable.h"

class Poison : public Eatable {

public:
    Poison();

    Poison(int Hx, int Hy, int width, int height, SnakeTail *snakeTails, int nTail);

    char draw();

    Type getType();
};


#endif //SNAKEGAME_POISON_H
