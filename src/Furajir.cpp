//
// Created by sam on 02.12.2021.
//

#include "Furajir.h"

#include <utility>

Furajir::Furajir(std::string name, int max_health, int curr_points, int max_points, int walk_cost, int accuracy, int view_rad, int curr_weight, int max_weight)
: Creature(std::move(name), max_health, curr_points, max_points, walk_cost, accuracy, view_rad, curr_weight, max_weight) {}

void Furajir::takeItem(Object* item)
{
    if (item->getWeight() > (max_weight - curr_weight))
        throw std::logic_error("Your inventory is overloaded");

    switch (item->getType())
    {
        case WEAPON:
            switch (item->getName())
            {
                case M4:
                    m_inventory[item] = new Weapon(*dynamic_cast<Weapon*>(item));
                    break;
                case AK:
                    m_inventory[item] = new Weapon(*dynamic_cast<Weapon*>(item));
                    break;
            }
        case AIDKIT:
            m_inventory[item] = new Aidkit(*dynamic_cast<Aidkit*>(item));
            break;
        case AMMO:
            switch (item->getName())
            {
                case M4:
                    m_inventory[item] = new AmmoContainer(*dynamic_cast<AmmoContainer*>(item));
                    break;
                case AK:
                    m_inventory[item] = new AmmoContainer(*dynamic_cast<AmmoContainer*>(item));
                    break;
            }
    }
}

void Furajir::throwItem(Object * item)
{
    m_inventory.erase(item);
}
