//
// Created by chicha-man on 13.11.2021.
//

#include "Weapon.h"

#include <utility>

Weapon::Weapon(Name name, int damage, int reload_cost, int curr_ammo, int max_ammo, int weight)
    : Object(WEAPON, name, weight),
    damage(damage), reload_cost(reload_cost),
    curr_ammo(curr_ammo), max_ammo(max_ammo) {}

bool Weapon::fire() {
    if (curr_ammo == 0)
        return false;
    curr_ammo--;
    return true;
}

void Weapon::reload(int &ammo) {
    if (max_ammo - curr_ammo < ammo) {
        curr_ammo = max_ammo;
        ammo -= max_ammo - curr_ammo;
    }
    else {
        curr_ammo += ammo;
        ammo = 0;
    }
}