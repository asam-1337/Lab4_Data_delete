#include <vector>
#include <SFML/Graphics.hpp>
#include "graphics/GraphicCreature.h"
#include "graphics/GraphicOperative.h"
#include "graphics/GraphicFurajir.h"
#include "graphics/GraphicWild.h"
#include "Map.h"
#include <sstream>
#include <typeinfo>
//#include "src/MyVector.h"

using namespace sf;

void openInvent(RenderWindow & window, GraphicCreature * player, Map & map)
{
    sf::Font font;
    font.loadFromFile("../CyrilicOld.ttf");
    sf::Text text("",font,20);
    text.setColor(sf::Color::Red);
    text.setPosition(5*32,13*32);
    if (Keyboard::isKeyPressed(Keyboard::Tab)) {
        player->looting(window, map);


        /*std::ostringstream ss;
        ss << map.cells[0].items[0].second->getType();
        text.setString("Item: " + ss.str() + "\n");
        window.draw(text);*/
    }
}

void control(RenderWindow & window, GraphicCreature * player, float & time , Map & map, int & n, int screenWidth, int screenHeight) {
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

    if (player->rect.left > screenWidth/2)
        map.offsetX = player->rect.left - screenWidth/2;
    if (player->rect.top > screenHeight/2)
        map.offsetY = player->rect.top - screenHeight/2;


}

int main()
{
    int screenWidth = 1280;
    int screenHeight = 768;
    
    RenderWindow window(VideoMode(screenWidth, screenHeight), "[DATA DELETED]");
/*
    Font font;
    font.loadFromFile("../CyrilicOld.ttf");
    Text text("",font,20);
    text.setColor(Color::Green);
    text.setPosition(10,13*32);

    sf::Text text2("",font,20);
    text2.setColor(sf::Color::Red);
    text2.setPosition(10*32,13*32);
*/


    Texture t;
    t.loadFromFile("../fang.png");

    std::vector<GraphicCreature*> players;
    players.push_back(new GraphicOperative(t, 1, 3 * 32, 2 * 32, new Operative("1")));
    players.push_back(new GraphicOperative(t, 2, 7 * 32, 5 * 32, new Operative("2")));

    std::vector<GraphicCreature*> enemies;
    enemies.push_back(new GraphicFurajir(t, 1, 5*32, 5*32, new Furajir("1")));
    enemies.push_back(new GraphicFurajir(t, 1, 6*32, 6*32, new Furajir("2")));

    Map map;
    //map.cells.push_back(cell(new Weapon(AK, 10, 10, 30, 30, 30), 3*32, 2*32));

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

        for (auto player : players) {
            player->update(time, map);
            player->skin.setTextureRect(sf::IntRect(0, 190, 40, 50));
        }

        for (auto enemy : enemies) {
            enemy->update(time, map);
        }

        control(window, players[n], time, map, n, screenWidth, screenHeight);

        window.clear(Color::White);
        map.print(window, rectangle);
/*
        std::ostringstream ss;
        ss << n;
        text.setString("Player name: " + ss.str());
        window.draw(text);

        std::ostringstream ss2;
        ss2 << "AK";
        text2.setString("Item: " + ss2.str());
        window.draw(text2);
*/
        openInvent(window, players[n], map);
        for (auto player : players)
            window.draw(player->skin);

        for (auto enemy: enemies)
            window.draw(enemy->skin);

        window.display();
    }

    return 0;
}
