//
// Created by sam on 02.12.2021.
//

#include "Furajir.h"

#include <utility>

Furajir::Furajir(std::string name, int max_health, int curr_points, int max_points, int walk_cost, int accuracy, int view_rad, int curr_weight, int max_weight)
: Creature(std::move(name), max_health, curr_points, max_points, walk_cost, accuracy, view_rad, curr_weight, max_weight) {}

void Furajir::takeItem(Object* item) {
    if (item->getWeight() > (max_weight - curr_weight))
        throw std::logic_error("Your inventory is overloaded");
    switch (item->getType())
    {
        case WEAPON:
            switch (item->getName())
            {
                case M4:
                    throwItem(0);
                    m_inventory[0] = new Weapon(*dynamic_cast<Weapon*>(item));
                    break;
                case AK:
                    throwItem(1);
                    m_inventory[1] = new Weapon(*dynamic_cast<Weapon*>(item));
                    break;
            }
        case AIDKIT:
            throwItem(2);
            m_inventory[2] = new Aidkit(*dynamic_cast<Aidkit*>(item));
            break;
        case AMMO:
            switch (item->getName())
            {
                case M4:
                    throwItem(3);
                    m_inventory[3] = new AmmoContainer(*dynamic_cast<AmmoContainer*>(item));
                    break;
                case AK:
                    throwItem(4);
                    m_inventory[4] = new AmmoContainer(*dynamic_cast<AmmoContainer*>(item));
                    break;
            }
    }
}

void Furajir::throwItem(int n) {
    m_inventory[n] = nullptr;
}
