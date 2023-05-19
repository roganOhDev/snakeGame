//
// Created by Oh DongGeun on 2023/05/18.
//
#ifndef SNAKEGAME_EATABLE_H
#define SNAKEGAME_EATABLE_H

#include "../snake/SnakeTail.h"
#include "../Object.h"

class Eatable : public Object{
public:
    void setX(int _x);

    int getX() const;

    void setY(int _x);

    int getY() const;

    Eatable();

    Eatable(int Hx, int Hy, int width, int height, SnakeTail *snakeTails,int nTail);

    void newPosition(int Hx, int Hy, int width, int height, SnakeTail *snakeTails,int nTail);

private:
    int x;
    int y;
};


#endif //SNAKEGAME_EATABLE_H
