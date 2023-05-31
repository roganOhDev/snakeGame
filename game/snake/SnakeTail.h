//
// Created by Oh DongGeun on 2023/05/19.
//

#ifndef SNAKEGAME_SNAKETAIL_H
#define SNAKEGAME_SNAKETAIL_H

#include "../Object.h"

class SnakeTail : public Object{
public:
    SnakeTail();
    SnakeTail(int x, int y);
    char draw();
    void setPosition(int _x, int _y);
    Type getType();
    bool isWall();
};


#endif //SNAKEGAME_SNAKETAIL_H
