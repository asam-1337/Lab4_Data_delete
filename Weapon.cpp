//
// Created by chicha-man on 13.11.2021.
//

#include "Weapon.h"

#include <utility>

Weapon::Weapon(std::string name, int damage, int reload_cost, int curr_ammo, int max_ammo, int weight)
: name(std::move(name)), damage(damage), reload_cost(reload_cost), curr_ammo(curr_ammo), max_ammo(max_ammo), weight(weight)
{}

int Weapon::getDamage() const {return damage;}

void Weapon::reload()
{
    this->curr_ammo = this->max_ammo;

}