//
// Created by chicha-man on 10.12.2021.
//

#include "GraphicOperative.h"

void GraphicOperative::fire(Creature * creature) {
    dynamic_cast<Operative *>(_creature)->fire(creature);
}

void GraphicOperative::reload() {
    dynamic_cast<Operative *>(_creature)->reload();
}

void GraphicOperative::selectWeapon(int n) {
dynamic_cast<Operative*>(_creature)->selectWeapon(n);
}

void GraphicOperative::collision(int dir, Map map) {
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

void GraphicOperative::update(float time, Map & map) {
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
