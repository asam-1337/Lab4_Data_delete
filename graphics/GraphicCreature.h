//
// Created by sam on 09.12.2021.
//

#ifndef LAB4_DATA_DELETE_GRAPHICCREATURE_H
#define LAB4_DATA_DELETE_GRAPHICCREATURE_H

#include <SFML/Graphics.hpp>
#include "../src/Creature.h"
#include "../Map.h"


class GraphicCreature {

public:
    Creature * m_creature = nullptr;

    float dx = 0, dy = 0;
    float currentFrame = 0;
    sf::FloatRect rect;
    sf::Sprite skin;

    GraphicCreature() = default;

    GraphicCreature(const sf::Texture& t, int name, float x, float y, Creature * creature);

    void load(const sf::Texture& t, int name, float x, float y, Creature * creature);

    virtual void collision(int dir, Map map);

    virtual void update(float time, Map & map);

    virtual void getBlood();
};


#endif //LAB4_DATA_DELETE_GRAPHICCREATURE_H
