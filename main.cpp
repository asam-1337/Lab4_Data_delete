 #include <iostream>

#include <SFML/Graphics.hpp>
#include "graphics/GraphicCreature.h"
#include "graphics/GraphicOperative.h"
#include "graphics/GraphicFurajir.h"
#include "graphics/GraphicWild.h"
#include "src/MyVector.h"

#include "Map.h"
using namespace sf;

void control(GraphicCreature * player, float & time , Map & map, int & n, int screenWidth, int screenHeight) {
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        player->dx = -0.1;
    }

    if (Keyboard::isKeyPressed(Keyboard::D)) {
        player->dx = 0.1;
        }

    if (Keyboard::isKeyPressed(Keyboard::W)) {
        player->dy = -0.1;
    }

    if (Keyboard::isKeyPressed(Keyboard::S)) {
        player->dy = 0.1;
    }

    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        if (n > 0)
            n--;
    }

    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        if (n < 1)
            n++;
    }

    player->update(time, map);

    if (player->rect.left > 300)
        map.offsetX = player->rect.left - 300;
    if (player->rect.top > 240)
        map.offsetY = player->rect.top - 240;
}

int main()
{
    int screenWidth = 600;
    int screenHeight = 400;
    
    RenderWindow window(VideoMode(screenWidth, screenHeight), "[DATA DELETED]");

    Texture t;
    t.loadFromFile("../fang.png");

    MyVector<GraphicCreature*> units;

    units.push_back(new GraphicOperative(t, 1, 3*32, 2*32, new Operative()));
    units.push_back(new GraphicOperative(t, 2, 3*32, 2*32, new Operative()));

    GraphicCreature* player;
    player = new GraphicOperative(t, 1, 3*32, 2*32, new Operative());
    auto it = units.begin();
    auto it2 = units.end();
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

        for (int i = 0; i < 2; i++) {
            units[i]->update(time, map);
            units[i]->skin.setTextureRect(sf::IntRect(0, 190, 40, 50));
        }/*
        for (; it != it2; ++it) {
            (*it)->update(time, map);
            (*it)->skin.setTextureRect(sf::IntRect(0, 190, 40, 50));
        }*/
        /*
        for (auto unit : units) {
            unit->update(time, map);
            unit->skin.setTextureRect(sf::IntRect(0, 190, 40, 50));
        }*/

        control(units[n], time, map, n, screenWidth, screenHeight);
        
        window.clear(Color::White);
        map.print(window, rectangle);
        //window.draw(player->skin);
        for (int i = 0; i < 2; i++) {
            window.draw(units[i]->skin);
        }
        /*
        for (auto unit : units)
            window.draw(unit->skin);
        window.draw(enemies[0].skin);*/
        window.display();
    }

    return 0;
}
