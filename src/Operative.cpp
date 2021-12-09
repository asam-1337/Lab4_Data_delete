//
// Created by chicha-man on 13.11.2021.
//

#include "Operative.h"

Operative::Operative()
    : Furajir("1",100, 100, 100,
               2, 5, 10, 0,50) {}

void Operative::selectWeapon(int n) {
    if (m_inventory[n]->getType() != NOT)
        i_selectedWeapon = n;
}

void Operative::reload() {
    auto *weapon = dynamic_cast<Weapon *>(m_inventory[i_selectedWeapon]);
    auto *ammo = dynamic_cast<AmmoContainer *>(m_inventory[i_selectedWeapon + 2]);
    weapon->reload(ammo->getAmmo());
}

bool Operative::fire() {
    if (accuracy <= rand() % 10 + 1)
        return true;
    return false;
}
