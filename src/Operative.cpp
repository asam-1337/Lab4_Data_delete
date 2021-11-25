//
// Created by chicha-man on 13.11.2021.
//

#include "Operative.h"

Operative::Operative(const sf::Texture& t, std::string &name, float x, float y)
    : Creature(100, 100, 100,
               2, 5, 10, 0,50)
{
    skin.setTexture(t);
    skin.setPosition(x, y);
    skin.setTextureRect(sf::IntRect(0, 244, 40, 50));
}

int Operative::getWeight() const {
    return curr_weight;
}

void Operative::selectWeapon(int n) {
    if (inventory.getItem(n)->getName() != NO)
        i_selectedWeapon = n;
}

void Operative::takeItem(Object* item) {
    if (item->getWeight() > (max_weight - curr_weight))
        throw std::logic_error("Your inventory is overloaded");
    inventory.addItem(item);
}

void Operative::getHit(int damage) {
    if (curr_health - damage <= 0)
        throw std::logic_error("You are die");
    curr_health -= damage;
}

void Operative::walk() {
     curr_points -= walk_cost;
}

void Operative::reload() {
    Object *weapon = inventory.getItem(i_selectedWeapon);
    Object *ammo = inventory.getItem(i_selectedWeapon + 2);
    weapon->reload(ammo->getAmmo());
}

bool Operative::fire() {
    if (accuracy <= rand() % 10 + 1)
        return true;
    return false;
}
