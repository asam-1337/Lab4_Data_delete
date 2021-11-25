//
// Created by chicha-man on 13.11.2021.
//

#include "Inventory.h"

Object* Inventory::getItem(int num) const {
    if (table[num]->getType() == NOT)
        throw std::logic_error("You don't have such item");
    return table[num];
}

void Inventory::addItem(Object* item) {
    switch (item->getType()) {
        case WEAPON:
            switch (item->getName()) {
                case M4:
                    table[0] = new Weapon(M4, 10, 5, 0, 30, 10);
                    break;
                case AK:
                    table[1] = new Weapon(AK, 10, 5, 0, 30, 10);
                    break;
            }
        case AIDKIT:
            table[2] = new Aidkit();
            break;
        case AMMO:
            switch (item->getName()) {
                case M4:
                    table[3] = new Ammo_container(M4, 90);
                    break;
                case AK:
                    table[4] = new Ammo_container(AK, 60);
            }
    }
}