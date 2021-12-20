//
// Created by chicha-man on 14.11.2021.
//

#ifndef LAB4_DATA_DELETE_MAP_H
#define LAB4_DATA_DELETE_MAP_H

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "src/Object.h"
#include "src/MyVector.h"
#include "src/Weapon.h"
#include "src/Aidkit.h"
#include "src/AmmoContainer.h"
//#include "graphics/GraphicCreature.h"


struct cell {
    float x = 0;
    float y = 0;
    MyVector<int, Object*> items;

    cell(Object * item, float x, float y) : x(x), y(y)
    {
        items.push_back(0, item);
    }
};

class Map {
public:
    std::vector<cell> cells; // клетки на которых есть предметы

    float offsetX = 0, offsetY = 0;
    static const int height = 12;
    const int width = 40;
    sf::String TileMap[height] = {
            "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
            "B                                B     B",
            "B                                B     B",
            "B                                B     B",
            "B                                B     B",
            "B         0000                BBBB     B",
            "B                                B     B",
            "BBB                              B     B",
            "B              BB                BB    B",
            "B              BB                      B",
            "B    B         BB         BB           B",
            "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
    };
public:
    Map();

    void print(sf::RenderWindow & window, sf::RectangleShape & rectangle);
};


#endif //LAB4_DATA_DELETE_MAP_H
