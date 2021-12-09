#include <iostream>

#include <SFML/Graphics.hpp>
#include "graphics/GraphicCreature.h"
#include "src/Operative.h"
#include "Map.h"
using namespace sf;

void control(GraphicCreature & player, float & time , Map & map, int & n, int screenWidth, int screenHeight) {
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        player.dx = -0.1;
    }

    if (Keyboard::isKeyPressed(Keyboard::D)) {
        player.dx = 0.1;
        }

    if (Keyboard::isKeyPressed(Keyboard::W)) {
        player.dy = -0.1;
    }

    if (Keyboard::isKeyPressed(Keyboard::S)) {
        player.dy = 0.1;
    }

    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        if (n > 0)
            n--;
    }

    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        if (n < 1)
            n++;
    }

    player.update(time, map);

    if (player.rect.left > 300)
        map.offsetX = player.rect.left - 300;
    if (player.rect.top > 240)
        map.offsetY = player.rect.top - 240;
}

int main()
{
    int screenWidth = 600;
    int screenHeight = 400;
    
    RenderWindow window(VideoMode(screenWidth, screenHeight), "[DATA DELETED]");

    Texture t;
    t.loadFromFile("../fang.png");

    GraphicCreature players[2];
    for (auto & player : players)
        player.load(t, 2, 200, 100, new Operative());

    Map map;
    int n = 0;

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
        for (auto & player : players) {
            player.update(time, map);
            player.skin.setTextureRect(sf::IntRect(0, 190, 40, 50));
        }
        control(players[n], time, map, n, screenWidth, screenHeight);
        
        window.clear(Color::White);
        map.print(window, rectangle);

        for (auto & player : players)
            window.draw(player.skin);

        window.display();
    }

    return 0;
}
