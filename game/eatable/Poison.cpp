//
// Created by Oh DongGeun on 2023/05/18.
//

#include "Poison.h"

Poison::Poison() : Eatable() {}

Poison::Poison(int Hx, int Hy, int width, int height) : Eatable(Hx, Hy, width, height) {}

char Poison::draw() {
    return 'P';
}

Type Poison::getType() {
    return POISON;
}
