#include <iostream>

#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(200, 200), "{[DATA DELETED]}");

    Texture t;
    t.loadFromFile("../mario.png");

    Sprite s;
    s.setTexture(t);
    s.setPosition(50,100);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            s.move(-0.1,0);
        }
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            s.move(0.1,0);
        }
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            s.move(0,-0.1);
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            s.move(0,0.1);
        }
        window.clear();
        window.draw(s);
        window.display();
    }

    return 0;
}
