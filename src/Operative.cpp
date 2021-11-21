//
// Created by chicha-man on 13.11.2021.
//

#include "Operative.h"

Operative::Operative(const sf::Texture& t, std::string &name, float x, float y)
    : Creature(100, 100, 100,
               2, 5, 10, 0,50), name(name)
{
    skin.setTexture(t);
    skin.setPosition(x, y);
    skin.setTextureRect(sf::IntRect(0, 244, 40, 50));
}

int Operative::getWeight() const {
    return max_weight;
}
