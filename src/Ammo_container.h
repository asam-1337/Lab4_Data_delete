//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_AMMO_CONTAINER_H
#define LAB4_DATA_DELETE_AMMO_CONTAINER_H

#include <string>
#include "Object.h"

enum Name
{
    NO,
    M4,
    AK
};
class Ammo_container : public Object{
private:
    //std::string name;
    Name name = NO;
    int curr = 0;
    const int max = 0;
    //int weight = 0;
public:
    explicit Ammo_container(Name name): Object(AMMO, 20), name(name) {}
};


#endif //LAB4_DATA_DELETE_AMMO_CONTAINER_H
