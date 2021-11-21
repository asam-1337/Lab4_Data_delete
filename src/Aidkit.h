//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_AIDKIT_H
#define LAB4_DATA_DELETE_AIDKIT_H

#include <string>
#include "Object.h"

class Aidkit : public Object {
    //const std::string name;
    int health;
    const int cost;
    //const int weight;
    explicit Aidkit() : Object(AIDKIT, 10), health(50), cost(10) {}
};


#endif //LAB4_DATA_DELETE_AIDKIT_H
