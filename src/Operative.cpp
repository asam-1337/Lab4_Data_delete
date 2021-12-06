//
// Created by chicha-man on 13.11.2021.
//

#include "Operative.h"

Operative::Operative(const sf::Texture& t, int name, float x, float y)
    : Furajir("1",100, 100, 100,
               2, 5, 10, 0,50)
{
    skin.setTexture(t);
    skin.setPosition(x, y);
    skin.setTextureRect(sf::IntRect(0, 244, 40, 50));
}

void Operative::selectWeapon(int n) {
    if (m_inventory[n]->getType() != NOT)
        i_selectedWeapon = n;
}

void Operative::reload() {
    auto *weapon = dynamic_cast<Weapon *>(m_inventory[i_selectedWeapon]);
    auto *ammo = dynamic_cast<Ammo_container *>(m_inventory[i_selectedWeapon + 2]);
    weapon->reload(ammo->getAmmo());
}

bool Operative::fire() {
    if (accuracy <= rand() % 10 + 1)
        return true;
    return false;
}
