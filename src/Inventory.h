//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_INVENTORY_H
#define LAB4_DATA_DELETE_INVENTORY_H

#include <map>
#include "Object.h"
#include "Weapon.h"
#include "Aidkit.h"
#include "Ammo_container.h"



struct Item {
    Weapon weapon;
    Aidkit aidkit;
    Ammo_container ammo;
    int i_weapon;
    int i_aidkit;
    int i_ammo;
};

class Inventory {
protected:
    Object *obj[2];
    std::map<int, Item> table;
    int getSize() const;
    Item getItem(int num) const;
    void addItem();


};

#endif //LAB4_DATA_DELETE_INVENTORY_H
