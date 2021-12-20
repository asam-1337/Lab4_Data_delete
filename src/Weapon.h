//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_WEAPON_H
#define LAB4_DATA_DELETE_WEAPON_H

#include <string>
#include "Object.h"


class Weapon : public Object{
private:
    const int damage = 0;
    const int reload_cost = 0;
    const int shoot_cost = 0;
    int curr_ammo = 0;
    const int max_ammo = 0;

public:
    Weapon(std::string name, int damage, int reload_cost, int curr_ammo, int max_amm, int weight);

    [[nodiscard]] int getDamage() const { return damage; }

    [[nodiscard]] int getReloadCost() const { return reload_cost; }

    [[nodiscard]] int getShootCost() const { return shoot_cost; }

    [[nodiscard]] int getAmmo() const { return curr_ammo; }

    [[nodiscard]] int getMaxAmmo() const { return max_ammo; }

    [[nodiscard]] Type getType() const override {return WEAPON;}

    bool fire();

    void reload(int &ammo);
};


#endif //LAB4_DATA_DELETE_WEAPON_H
