//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_AMMOCONTAINER_H
#define LAB4_DATA_DELETE_AMMOCONTAINER_H

#include <string>
#include <utility>
#include "Object.h"

class AmmoContainer : public Object{
private:
    int ammo = 100;
    const int max_ammo = 100;
public:
    AmmoContainer(std::string name): Object(std::move(name),20) {}

    [[nodiscard]] int& getAmmo() { return ammo; }

    [[nodiscard]] int getMaxAmmo() const { return max_ammo; }

    [[nodiscard]] Type getType() const override { return AMMO; }
};


#endif //LAB4_DATA_DELETE_AMMOCONTAINER_H
