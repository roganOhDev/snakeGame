//
// Created by Oh DongGeun on 2023/05/19.
//

#ifndef SNAKEGAME_SNAKEHEAD_H
#define SNAKEGAME_SNAKEHEAD_H

#include "../Object.h"
#include "../Direction.h"

class SnakeHead : public Object{
public:
    SnakeHead();
    SnakeHead(int x, int y);
    char draw();
    int getX();
    int getY();

    void moveLeft(int &hx);
    void moveRight(int &hx);
    void moveUp(int &hy);
    void moveDown(int &hy);

    Type getType();
};


#endif //SNAKEGAME_SNAKEHEAD_H
