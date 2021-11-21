//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_OPERATIVE_H
#define LAB4_DATA_DELETE_OPERATIVE_H

#include <string>
#include <SFML/Graphics.hpp>

#include "Weapon.h"
#include "Inventory.h"
#include "Creature.h"

class Operative : public Creature, public Inventory {
private:
    std::string name;
public:
    sf::Sprite skin;
    Operative(const sf::Texture& t, std::string &name, float x = 0, float y = 0);
    int getWeight() const;
    void selectWeapon();
    void takeItem();
    void getDamage();
    void walk();
};


#endif //LAB4_DATA_DELETE_OPERATIVE_H
