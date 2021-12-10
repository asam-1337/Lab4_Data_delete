//
// Created by sam on 09.12.2021.
//

#include "GraphicCreature.h"

GraphicCreature::GraphicCreature(const sf::Texture& t, int name, float x, float y, Creature * creature) : m_creature(creature){
    skin.setTexture(t);
    rect = sf::FloatRect(x, y, 40, 50);
    dx = dy = 0;
    currentFrame = 0;
}

void GraphicCreature::load(const sf::Texture& t, int name, float x, float y, Creature * creature) {
    m_creature = creature;
    skin.setTexture(t);
    rect = sf::FloatRect(x, y, 40, 50);
    dx = dy = 0;
    currentFrame = 0;
}

void GraphicCreature::collision(int dir, Map map) {
    for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
        for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++) {
            if (map.TileMap[i][j] == 'B') {
                if (dx > 0 && dir == 0) rect.left = j * 32 - rect.width;
                if (dx < 0 && dir == 0) rect.left = j * 32 + 32;

                if (dy > 0 && dir == 1) rect.top = i * 32 - rect.height;
                if (dx < 0 && dir == 1) rect.top = i * 32 + 32;
            }
        }
}

void GraphicCreature::update(float time, Map & map) {
    rect.left += dx * time;
    collision(0, map);

    rect.top += dy * time;
    collision(1, map);

    currentFrame +=  0.005 * time;
    if (currentFrame > 6) currentFrame -= 6;

    if (dx > 0)
        skin.setTextureRect(sf::IntRect(40 * int(currentFrame), 244, 40, 50));
    if (dx < 0)
        skin.setTextureRect(sf::IntRect(40 * int(currentFrame) + 40, 244, -40, 50));

    skin.setPosition(rect.left - map.offsetX, rect.top - map.offsetY);

    dx = 0;
    dy = 0;
}

void GraphicCreature::getBlood() {

}
