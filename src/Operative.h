//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_OPERATIVE_H
#define LAB4_DATA_DELETE_OPERATIVE_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Weapon.h"
#include "Ammo_container.h"
#include "Aidkit.h"
#include "Inventory.h"
#include "Furajir.h"

class Operative : public Furajir {
private:
    //Inventory<Object*> m_inventory;
    int i_selectedWeapon = 0;
public:
    sf::Sprite skin;

    Operative(const sf::Texture& t, int name, float x = 0, float y = 0);

    void selectWeapon(int n);

    void reload();

    bool fire();
};


#endif //LAB4_DATA_DELETE_OPERATIVE_H
