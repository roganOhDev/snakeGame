//
// Created by Oh DongGeun on 2023/05/18.
//
#ifndef SNAKEGAME_EATABLE_H
#define SNAKEGAME_EATABLE_H

#include "../snake/SnakeTail.h"
#include "../Object.h"

class Eatable : public Object{
public:
    int getX() const;

    int getY() const;

    Eatable();

    Eatable(int x, int y);

    void newPosition(int Hx, int Hy, int width, int height, SnakeTail *snakeTails,int nTail);

};


#endif //SNAKEGAME_EATABLE_H
