//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_OPERATIVE_H
#define LAB4_DATA_DELETE_OPERATIVE_H

#include <string>
#include <SFML/Graphics.hpp>

#include "Weapon.h"
#include "Inventory.h"
#include "Specifications.h"

class Operative {
private:
    std::string name;

public:
    sf::Sprite skin;
    explicit Operative(const sf::Texture& t, float x = 0, float y = 0);
};


#endif //LAB4_DATA_DELETE_OPERATIVE_H
