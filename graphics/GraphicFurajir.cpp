//
// Created by chicha-man on 10.12.2021.
//

#include "GraphicFurajir.h"

GraphicFurajir::GraphicFurajir(const sf::Texture & texture, int name, float x, float y, Creature * creature)
        : GraphicCreature(texture,name, x, y, creature, 0.1) {}

void GraphicFurajir::collision(int dir, Map map)
{
    for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)

        for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
        {
            if (map.TileMap[i][j] == 'B') {
                if (dx > 0) {
                    rect.left = j * 32 - rect.width;
                    dx *= -1;
                }

                else if (dx < 0) {
                    rect.left = j * 32 + 32;
                    dx *= -1;
                }
            }
        }
}

void GraphicFurajir::update(float time, Map & map)
{

    rect.left += dx * time;
    collision(0, map);

    currentFrame +=  0.005 * time;
    if (currentFrame > 6) currentFrame -= 6;

    if (dx > 0) {
        skin.setTextureRect(sf::IntRect(40 * int(currentFrame), 244, 40, 50));
    }
    if (dx < 0) {
        skin.setTextureRect(sf::IntRect(40 * int(currentFrame) + 40, 244, -40, 50));
    }
    skin.setPosition(rect.left - map.offsetX, rect.top - map.offsetY);

}