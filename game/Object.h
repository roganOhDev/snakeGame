//
// Created by Oh DongGeun on 2023/05/19.
//

#ifndef SNAKEGAME_OBJECT_H
#define SNAKEGAME_OBJECT_H

#include "Type.h"

class Object {
public:
    Object();
    Object(int x, int y);
    virtual char draw();
    virtual Type getType();
    int getX();
    int getY();

protected:
    int y;
    int x;
};


#endif //SNAKEGAME_OBJECT_H
