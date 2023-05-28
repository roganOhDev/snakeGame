//
// Created by Oh DongGeun on 2023/05/18.
//

#ifndef SNAKEGAME_POISON_H
#define SNAKEGAME_POISON_H

#include "Eatable.h"

class Poison : public Eatable {

public:
    Poison();

    Poison(int x, int y);

    char draw();
    Type getType();
    bool isWall();
};


#endif //SNAKEGAME_POISON_H
