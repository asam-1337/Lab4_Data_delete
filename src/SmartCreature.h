//
// Created by chicha-man on 07.12.2021.
//

#ifndef LAB4_DATA_DELETE_SMARTCREATURE_H
#define LAB4_DATA_DELETE_SMARTCREATURE_H

#include "Creature.h"
#include "Weapon.h"

class SmartCreature : public Creature {
private:
    Weapon *m_weapon = nullptr;
public:
    explicit SmartCreature(std::string name) :
    Creature(std::move(name), 50,50,50,
    2,1,3,0,0){}
    void takeWeapon(Weapon *weapon);
};


#endif //LAB4_DATA_DELETE_SMARTCREATURE_H
