//
// Created by sam on 02.12.2021.
//

#include "Furajir.h"

#include <utility>

/*Furajir::Furajir(const sf::Texture& t, std::string &name, float x, float y)
        : Creature(100, 100, 100,
                   2, 5, 10, 0,50)
{
    skin.setTexture(t);
    skin.setPosition(x, y);
    skin.setTextureRect(sf::IntRect(0, 244, 40, 50));
}*/
Furajir::Furajir(std::string name, int max_health, int curr_points, int max_points, int walk_cost, int accuracy, int view_rad, int curr_weight, int max_weight)
: Creature(std::move(name), max_health, curr_points, max_points, walk_cost, accuracy, view_rad, curr_weight, max_weight) {

}
int Furajir::getWeight() const {
    return curr_weight;
}

void Furajir::takeItem(Object* item) {
    if (item->getWeight() > (max_weight - curr_weight))
        throw std::logic_error("Your inventory is overloaded");
    switch (item->getType())
    {
        case WEAPON:
            switch (item->getName())
            {
                case M4:
                    inventory[0] = new Weapon(M4, 10, 5, 0, 30, 10);
                    break;
                case AK:
                    inventory[1] = new Weapon(AK, 10, 5, 0, 30, 10);
                    break;
            }
        case AIDKIT:
            inventory[2] = new Aidkit();
            break;
        case AMMO:
            switch (item->getName())
            {
                case M4:
                    inventory[3] = new Ammo_container(M4, 90);
                    break;
                case AK:
                    inventory[4] = new Ammo_container(AK, 60);
            }
    }
}

void Furajir::getHit(int damage) {
    if (curr_health - damage <= 0)
        throw std::logic_error("You are die");
    curr_health -= damage;
}

void Furajir::throwItem() {

}

void Furajir::walk() {
    curr_points -= walk_cost;
}
