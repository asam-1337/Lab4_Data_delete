//
// Created by sam on 02.12.2021.
//

#ifndef LAB4_DATA_DELETE_FURAJIR_H
#define LAB4_DATA_DELETE_FURAJIR_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Weapon.h"
#include "Ammo_container.h"
#include "Aidkit.h"
#include "Inventory.h"
#include "Creature.h"

class Furajir : public Creature {
protected:
    std::string name;
    Inventory<Object*> inventory;

public:

    [[nodiscard]] int getWeight() const;

    void takeItem(Object *item);

    void throwItem();

    void getHit(int damage);

    void walk();
};


#endif //LAB4_DATA_DELETE_FURAJIR_H
