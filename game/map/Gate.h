//
// Created by Oh DongGeun on 2023/05/25.
//

#ifndef SNAKEGAME_GATE_H
#define SNAKEGAME_GATE_H

#include "../Object.h"
#include "Wall.h"

class Gate : public Object{
public:
    Gate(Wall *walls, int nWall);
    Gate(Gate *gate, Wall *walls, int nWall);

    Type getType();
    char draw();
};


#endif //SNAKEGAME_GATE_H
