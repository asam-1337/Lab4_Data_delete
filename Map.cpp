//
// Created by chicha-man on 14.11.2021.
//

#include "Map.h"

Map::Map()
{
    cells.push_back(cell(new Weapon("M4", 10, 5, 30, 30, 10), 3*32, 2*32));
}

void Map::print(sf::RenderWindow & window, sf::RectangleShape & rectangle)
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            if (TileMap[i][j] == 'B') rectangle.setFillColor(sf::Color::Black);

            if (TileMap[i][j] == '0') rectangle.setFillColor(sf::Color::Yellow);

            if (TileMap[i][j] == ' ') continue;

            rectangle.setPosition(j*32 - offsetX, i*32 - offsetY);
            window.draw(rectangle);
        }
}

