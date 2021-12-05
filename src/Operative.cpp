//
// Created by chicha-man on 13.11.2021.
//

#include "Operative.h"

Operative::Operative(const sf::Texture& t, int name, float x, float y)
    : Furajir("1",100, 100, 100,
               2, 5, 10, 0,50)
{
    skin.setTexture(t);
    skin.setPosition(x, y);
    skin.setTextureRect(sf::IntRect(0, 244, 40, 50));
}

void Operative::selectWeapon(int n) {
    if (inventory[n]->getType() != NOT)
        i_selectedWeapon = n;
}
/*
void Operative::takeItem(Object* item) {
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

void Operative::getHit(int damage) {
    if (curr_health - damage <= 0)
        throw std::logic_error("You are die");
    curr_health -= damage;
}

void Operative::walk() {
     curr_points -= walk_cost;
}
*/
void Operative::reload() {
    auto *weapon = dynamic_cast<Weapon *>(inventory[i_selectedWeapon]);
    auto *ammo = dynamic_cast<Ammo_container *>(inventory[i_selectedWeapon + 2]);
    weapon->reload(ammo->getAmmo());
}

bool Operative::fire() {
    if (accuracy <= rand() % 10 + 1)
        return true;
    return false;
}

void Operative::throwItem() {

}
