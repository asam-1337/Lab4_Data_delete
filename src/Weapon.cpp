//
// Created by chicha-man on 13.11.2021.
//

#include "Weapon.h"

#include <utility>

Weapon::Weapon(Name name, int damage, int reload_cost, int curr_ammo, int max_ammo, int weight)
    : Object(WEAPON, weight), damage(damage), reload_cost(reload_cost), curr_ammo(curr_ammo), max_ammo(max_ammo)
{}

int Weapon::getDamage() const {return damage;}

void Weapon::reload()
{
    this->curr_ammo = this->max_ammo;

}