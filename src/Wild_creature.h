//
// Created by sam on 21.11.2021.
//

#ifndef LAB4_DATA_DELETE_WILD_CREATURE_H
#define LAB4_DATA_DELETE_WILD_CREATURE_H

#include <string>
#include <utility>
#include "Creature.h"
#include "Weapon.h"

class Wild_creature : public Creature {
private:
    Weapon *weapon = nullptr;
public:
    explicit Wild_creature(std::string & name) :
        Creature(50,50,50,
                 2,1,3,0,0){}
};


#endif //LAB4_DATA_DELETE_WILD_CREATURE_H
