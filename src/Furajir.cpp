//
// Created by sam on 02.12.2021.
//


#include "Furajir.h"

Furajir::Furajir(std::string name) : Creature(std::move(name),100,100,2,5,5,50) {}

Furajir::Furajir(std::string name, int max_health, int max_points, int walk_cost, int accuracy, int view_rad, int max_weight)
    : Creature(std::move(name), max_health, max_points, walk_cost, accuracy, view_rad, max_weight) {}

void Furajir::takeItem(Object* item)
{
    if (item->getWeight() > (max_weight - curr_weight))
        throw std::logic_error("Your inventory is overloaded");

    switch (item->getType()) {
        case WEAPON:
            m_inventory.push_back(0, new Weapon(*dynamic_cast<Weapon *>(item)));
            break;
        case AIDKIT:
            m_inventory.push_back(1, new Aidkit(*dynamic_cast<Aidkit *>(item)));
            break;
        case AMMO:
            m_inventory.push_back(2, new AmmoContainer(*dynamic_cast<AmmoContainer *>(item)));
            break;
    }
}

void Furajir::throwItem(int ind)
{
    m_inventory.erase(ind);
}
