//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_AMMO_CONTAINER_H
#define LAB4_DATA_DELETE_AMMO_CONTAINER_H

#include <string>
#include "Object.h"

class Ammo_container : public Object{
private:
    int ammo = 0;
    const int max_ammo = 100;
public:
    explicit Ammo_container(Name name, int ammo): Object(AMMO, name,20), ammo(ammo) {}

    [[nodiscard]] int& getAmmo() { return ammo; }

    [[nodiscard]] int getMaxAmmo() const { return max_ammo; }
};


#endif //LAB4_DATA_DELETE_AMMO_CONTAINER_H
