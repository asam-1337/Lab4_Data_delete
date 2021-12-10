//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_OPERATIVE_H
#define LAB4_DATA_DELETE_OPERATIVE_H

#include <string>
#include "Object.h"
#include "Weapon.h"
#include "AmmoContainer.h"
#include "Aidkit.h"
#include "MyVector.h"
#include "Furajir.h"

class Operative : public Furajir {
private:
    int i_selectedWeapon = 0;
public:

    Operative();

    int getDamage() const;

    void selectWeapon(int n);

    void reload();

    bool fire(Creature * creature);
};


#endif //LAB4_DATA_DELETE_OPERATIVE_H
