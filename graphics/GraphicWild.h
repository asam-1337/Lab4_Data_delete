//
// Created by chicha-man on 10.12.2021.
//

#ifndef LAB4_DATA_DELETE_GRAPHICWILD_H
#define LAB4_DATA_DELETE_GRAPHICWILD_H

#include "GraphicCreature.h"

class GraphicWild : public GraphicCreature {
public:
    GraphicWild(sf::Texture texture, int name, float x, float y, Creature * creature);

    void collision(int dir, Map map) override;

    void update(float time, Map & map) override;
};


#endif //LAB4_DATA_DELETE_GRAPHICWILD_H
