//
// Created by Oh DongGeun on 2023/05/25.
//

#include "Wall.h"
#include "Gate.h"

char Gate::draw() {
    attrset(COLOR_PAIR(4));
    return 'G';
}

Type Gate::getType() {
    return GATE;
}

bool Gate::isWall() {
    return true;
}

Gate Gate::findOtherGate(Gate *gates, Object *gate) {
    for (int i = 0; i < 2; i++) {
        if (gates[i].getX() != gate->getX() || gates[i].getY() != gate->getY()) {
            return gates[i];
        }
    }
}

Gate::Gate(int x, int y) : Object(x, y) {}

Gate::Gate() {

}
