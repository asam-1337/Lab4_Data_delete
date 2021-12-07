//
// Created by chicha-man on 07.12.2021.
//

#include "SmartCreature.h"

void SmartCreature::takeWeapon(Weapon *weapon) {
    if (!m_weapon)
        delete m_weapon;
    m_weapon = new Weapon(*weapon);
}