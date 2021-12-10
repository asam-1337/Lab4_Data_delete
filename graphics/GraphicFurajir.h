//
// Created by chicha-man on 10.12.2021.
//

#ifndef LAB4_DATA_DELETE_GRAPHICFURAJIR_H
#define LAB4_DATA_DELETE_GRAPHICFURAJIR_H


#include "GraphicCreature.h"

class GraphicFurajir : public GraphicCreature {
public:
    GraphicFurajir(const sf::Texture & texture, int name, float x, float y, Creature * creature)
        : GraphicCreature(texture,name, x, y, creature) {}
};


#endif //LAB4_DATA_DELETE_GRAPHICFURAJIR_H
