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
    explicit Aidkit() : Object(AIDKIT,NO,10) {}
};


#endif //LAB4_DATA_DELETE_AIDKIT_H
