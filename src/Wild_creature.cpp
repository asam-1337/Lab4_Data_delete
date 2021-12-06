//
// Created by sam on 21.11.2021.
//

#include "Wild_creature.h"
#include "Weapon.h"

void Wild_creature::takeWeapon(Weapon *weapon) {
    if (!m_weapon)
        delete m_weapon;
    m_weapon = new Weapon(*weapon);
}