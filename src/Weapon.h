//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_WEAPON_H
#define LAB4_DATA_DELETE_WEAPON_H

#include <string>
#include "Object.h"

enum Name{
    NO,
    M4,
    AK
};

class Weapon : public Object{
private:
    Name name = NO;
    const int damage = 0;
    const int reload_cost = 0;
    const int shoot_cost = 0;
    int curr_ammo = 0;
    const int max_ammo = 0;
    //const int weight = 0;
public:
    Weapon(Name name, int damage, int reload_cost, int curr_ammo, int max_amm, int weight);
    int getDamage() const;
    void fire();
    bool getResult();
    void reload();
};


#endif //LAB4_DATA_DELETE_WEAPON_H
