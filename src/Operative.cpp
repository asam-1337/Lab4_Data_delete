//
// Created by chicha-man on 13.11.2021.
//

#include "Operative.h"

Operative::Operative(std::string name)
    : Furajir(std::move(name),100,100,2,5,5,50) {}

void Operative::selectWeapon(int n) {
    //if (m_inventory[n].second->getType() != NOT)
    i_selectedWeapon = n;
}

void Operative::reload() {
    auto weapon = dynamic_cast<Weapon *>(m_inventory[0].second);
    auto ammo = dynamic_cast<AmmoContainer *>(m_inventory[2].second);
    weapon->reload(ammo->getAmmo());
}

bool Operative::fire(Creature * creature) {
    if (accuracy <= rand() % 10 + 1) {
        creature->getHit(getDamage());
        return true;
    }
    return false;
}

int Operative::getDamage() const {
    return dynamic_cast<Weapon *>(m_inventory[i_selectedWeapon].second)->getDamage();
}
