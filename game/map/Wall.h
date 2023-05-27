//
// Created by Oh DongGeun on 2023/05/19.
//

#ifndef SNAKEGAME_MAP_H
#define SNAKEGAME_MAP_H

#include "../Object.h"

class Wall : public Object{
public:
    Wall();

    Wall(int x, int y);
    char draw();

    Type getType();
    bool isWall();
};


#endif //SNAKEGAME_MAP_H
