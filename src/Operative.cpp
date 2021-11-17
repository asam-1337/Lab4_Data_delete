//
// Created by chicha-man on 13.11.2021.
//

#include "Operative.h"

Operative::Operative(const sf::Texture& t, float x, float y)
{
    skin.setTexture(t);
    skin.setPosition(x, y);
    skin.setTextureRect(sf::IntRect(0, 244, 40, 50));
}