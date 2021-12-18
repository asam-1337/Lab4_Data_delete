//
// Created by sam on 21.11.2021.
//

#ifndef LAB4_DATA_DELETE_WILDCREATURE_H
#define LAB4_DATA_DELETE_WILDCREATURE_H

#include <string>
#include <utility>
#include "Creature.h"
#include "Weapon.h"

class WildCreature : public Creature {
public:
    explicit WildCreature(std::string name) :
        Creature(std::move(name), 50,50,
                 2,1,3,0) {}

};


#endif //LAB4_DATA_DELETE_WILDCREATURE_H
