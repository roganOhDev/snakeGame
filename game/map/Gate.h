//
// Created by Oh DongGeun on 2023/05/25.
//

#ifndef SNAKEGAME_GATE_H
#define SNAKEGAME_GATE_H

#include "Wall.h"

class Gate : public Object {
public:
    Gate(int x, int y);

    Gate();

    Type getType();

    char draw();

    bool isWall();

    static Gate findOtherGate(Gate *gates, Object *gate);
};


#endif //SNAKEGAME_GATE_H
