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
    Inventory<Object*> inventory;
public:
    Furajir(std::string name, int max_health, int curr_points, int max_points, int walk_cost, int accuracy, int view_rad, int curr_weight, int max_weight);
    [[nodiscard]] int getWeight() const;

    void takeItem(Object *item);

    void throwItem();

    void getHit(int damage);

    void walk();
};


#endif //LAB4_DATA_DELETE_FURAJIR_H
