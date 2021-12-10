//
// Created by chicha-man on 10.12.2021.
//

#ifndef LAB4_DATA_DELETE_GRAPHICOPERATIVE_H
#define LAB4_DATA_DELETE_GRAPHICOPERATIVE_H


#include "GraphicCreature.h"
#include "../src/Operative.h"

class GraphicOperative : public GraphicCreature {
public:
    GraphicOperative(const sf::Texture & texture, int name, float x, float y, Creature * creature)
            : GraphicCreature(texture, name, x, y, creature) {}

    void fire(Creature * creature);

    void reload();

    void selectWeapon(int n);
};


#endif //LAB4_DATA_DELETE_GRAPHICOPERATIVE_H
