#include <iostream>

#include <SFML/Graphics.hpp>

#include "src/Operative.h"
#include "Map.h"
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1000, 100), "[DATA DELETED]");

    const int height = 12;
    const int width = 40;
    std::string TileMap[height] = {
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

    Texture t;
    t.loadFromFile("../fang.png");

    float currentFrame = 0;

    Operative pl1(t,50,100);
    Map map;
    Clock clock;

    RectangleShape rectangle(Vector2f(32,32));

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMilliseconds();
        clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        pl1.skin.setTextureRect(sf::IntRect(0, 190, 40, 50));
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            pl1.skin.move(-0.1 * time, 0);
            currentFrame += 0.005 * time;
            if (currentFrame >= 6) currentFrame -= 6;
            pl1.skin.setTextureRect(sf::IntRect(40 * int(currentFrame) + 40, 244, -40, 50));
        }
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            pl1.skin.move(0.1 * time, 0);
            currentFrame += 0.005 * time;
            if (currentFrame >= 6) currentFrame -= 6;
            pl1.skin.setTextureRect(sf::IntRect(40 * int(currentFrame), 244, 40, 50));
        }
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            pl1.skin.move(0, -0.1 * time);
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            pl1.skin.move(0, 0.1 * time);
        }
        window.clear(Color::White);
        map.print(window, rectangle);
        window.draw(pl1.skin);
        window.display();
    }

    return 0;
}
