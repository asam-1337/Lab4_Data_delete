//
// Created by chicha-man on 14.11.2021.
//

#ifndef LAB4_DATA_DELETE_MAP_H
#define LAB4_DATA_DELETE_MAP_H

#include <string>
#include <SFML/Graphics.hpp>

class Map {
private:
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
    void print(sf::RenderWindow & window, sf::RectangleShape & rectangle);
};


#endif //LAB4_DATA_DELETE_MAP_H
