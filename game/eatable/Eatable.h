//
// Created by Oh DongGeun on 2023/05/18.
//
#ifndef SNAKEGAME_EATABLE_H
#define SNAKEGAME_EATABLE_H

#include "../Object.h"
#include <iostream>

using namespace std;

class Eatable : public Object{
public:
    void setX(int _x);

    int getX() const;

    void setY(int _x);

    int getY() const;

    Eatable();

    Eatable(int Hx, int Hy, int width, int height);

    void newPosition(int Hx, int Hy, int width, int height);

private:
    int x;
    int y;


};


#endif //SNAKEGAME_EATABLE_H
