//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_INVENTORY_H
#define LAB4_DATA_DELETE_INVENTORY_H

#include <map>
#include <vector>
#include "Object.h"
#include "Weapon.h"
#include "Aidkit.h"
#include "Ammo_container.h"


class Inventory {
protected:
    static const int size = 5;
    std::vector<Object*> table{size};
public:
    [[nodiscard]] Object* getItem(int num) const;

    void addItem(Object* object);
};

#endif //LAB4_DATA_DELETE_INVENTORY_H
