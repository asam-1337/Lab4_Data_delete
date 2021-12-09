//
// Created by chicha-man on 14.11.2021.
//

#include "Map.h"

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