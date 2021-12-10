//
// Created by chicha-man on 10.12.2021.
//

#ifndef LAB4_DATA_DELETE_GRAPHICWILD_H
#define LAB4_DATA_DELETE_GRAPHICWILD_H

#include "GraphicCreature.h"

class GraphicWild : public GraphicCreature {
public:
    GraphicWild(sf::Texture texture, int name, float x, float y, Creature * creature)
    :GraphicCreature(texture, name, x, y, creature) {}
};


#endif //LAB4_DATA_DELETE_GRAPHICWILD_H
