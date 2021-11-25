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
    Weapon(Name name, int damage, int reload_cost, int curr_ammo, int max_amm, int weight);

    [[nodiscard]] int getDamage() const override{ return damage; }

    [[nodiscard]] int getReloadCost() const override { return reload_cost; }

    [[nodiscard]] int getShootCost() const override { return shoot_cost; }

    //[[nodiscard]] int getWeight() const override { return weight; }

    [[nodiscard]] int getAmmo() const override { return curr_ammo; }

    [[nodiscard]] int getMaxAmmo() const override { return max_ammo; }

    bool fire() override;

    void reload(int &ammo) override;
};


#endif //LAB4_DATA_DELETE_WEAPON_H
