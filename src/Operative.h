//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_OPERATIVE_H
#define LAB4_DATA_DELETE_OPERATIVE_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Weapon.h"
#include "Inventory.h"
#include "Creature.h"

class Operative : public Creature {
private:
    std::string name;
    Inventory inventory;
    int i_selectedWeapon = 0;
public:
    sf::Sprite skin;

    Operative(const sf::Texture& t, std::string &name, float x = 0, float y = 0);

    int getWeight() const;

    void selectWeapon(int n);

    void takeItem(Object *item);

    void throwItem();

    void getHit(int damage);

    void walk();

    void reload();

    bool fire();
};


#endif //LAB4_DATA_DELETE_OPERATIVE_H
