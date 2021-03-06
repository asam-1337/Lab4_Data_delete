//
// Created by sam on 02.12.2021.
//

#ifndef LAB4_DATA_DELETE_FURAJIR_H
#define LAB4_DATA_DELETE_FURAJIR_H

#include <string>
#include "Object.h"
#include "Weapon.h"
#include "AmmoContainer.h"
#include "Aidkit.h"
#include "MyVector.h"
#include "Creature.h"

class Furajir : public Creature {
protected:
    MyVector<int, Object*> m_inventory;
public:
    Furajir(std::string name);

    Furajir(std::string name, int max_health, int max_points, int walk_cost, int accuracy, int view_rad, int max_weight);

    void takeItem(Object *item);

    void throwItem(int indx);
};


#endif //LAB4_DATA_DELETE_FURAJIR_H
