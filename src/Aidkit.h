//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_AIDKIT_H
#define LAB4_DATA_DELETE_AIDKIT_H

#include <string>
#include "Object.h"

class Aidkit : public Object {
private:
    int health = 50;
    const int cost = 10;
public:
    Aidkit() : Object(10) {}

    [[nodiscard]] Type getType() const override { return AIDKIT; }
};


#endif //LAB4_DATA_DELETE_AIDKIT_H
