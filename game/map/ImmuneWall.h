//
// Created by Oh DongGeun on 2023/05/20.
//

#ifndef SNAKEGAME_IMMUNEWALL_H
#define SNAKEGAME_IMMUNEWALL_H

#include "../Object.h"

class ImmuneWall : public Object{
public:
    ImmuneWall(int x, int y);
    char draw();

    Type getType();
    bool isWall();
};


#endif //SNAKEGAME_IMMUNEWALL_H
