#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

#include "Background.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Animetion");

    sf::Texture bgtextture[10];
    sf::Texture bgtextture2[10];
    bgtextture[0].loadFromFile("./image/bgtwo.png");
    bgtextture2[0].loadFromFile("./image/bgtwo.png");
    bgtextture[1].loadFromFile("./image/mountainbg.png");
    bgtextture2[1].loadFromFile("./image/mountainbg.png");
    bgtextture[2].loadFromFile("./image/moist.png");
    bgtextture2[2].loadFromFile("./image/moist.png");
    bgtextture[3].loadFromFile("./image/ground3.png");
    bgtextture2[3].loadFromFile("./image/ground3.png");
    bgtextture[4].loadFromFile("./image/ground2.png");
    bgtextture2[4].loadFromFile("./image/ground2.png");
    bgtextture[5].loadFromFile("./image/ground1.png");
    bgtextture2[5].loadFromFile("./image/ground1.png");
    bgtextture[6].loadFromFile("./image/water-3.png");
    bgtextture2[6].loadFromFile("./image/water-3.png");
    bgtextture[7].loadFromFile("./image/water-2.png");
    bgtextture2[7].loadFromFile("./image/water-2.png");
    bgtextture[8].loadFromFile("./image/water-1.png");
    bgtextture2[8].loadFromFile("./image/water-1.png");
    bgtextture[9].loadFromFile("./image/herb.png");
    bgtextture2[9].loadFromFile("./image/herb.png");

    std::vector<Background> background;
    std::vector<Background> background2;

    background.push_back(Background(&bgtextture[0], 0.f, 0, sf::Vector2f(1080.0f, 720.0f), sf::Vector2f(0.0f, -100.0f)));
    background2.push_back(Background(&bgtextture2[0], 0.f, 0, sf::Vector2f(1080.0f, 720.0f), sf::Vector2f(0.0f, -100.0f)));

    background.push_back(Background(&bgtextture[1], 0.f, 0, sf::Vector2f(1080.0f, 770.0f), sf::Vector2f(0.0f, -30.0f)));
    background2.push_back(Background(&bgtextture2[1], 0.f, 0, sf::Vector2f(1080.0f, 770.0f), sf::Vector2f(0.0f, -30.0f)));

    background.push_back(Background(&bgtextture[2], 0.f, 0, sf::Vector2f(1080.0f, 220.0f), sf::Vector2f(1080.0f, -20.0f)));
    background2.push_back(Background(&bgtextture2[2], 0.f, 0, sf::Vector2f(1080.0f, 220.0f), sf::Vector2f(1080.0f, -20.0f)));

    background.push_back(Background(&bgtextture[3], 0.f, 0, sf::Vector2f(1080.0f, 670.0f), sf::Vector2f(0.0f, 0.0f)));
    background2.push_back(Background(&bgtextture2[3], 0.f, 0, sf::Vector2f(1080.0f, 670.0f), sf::Vector2f(0.0f, 0.0f)));
    background.push_back(Background(&bgtextture[4], 0.f, 0, sf::Vector2f(1080.0f, 670.0f), sf::Vector2f(0.0f, 0.0f)));
    background2.push_back(Background(&bgtextture2[4], 0.f, 0, sf::Vector2f(1080.0f, 670.0f), sf::Vector2f(0.0f, 0.0f)));
    background.push_back(Background(&bgtextture[5], 0.f, 0, sf::Vector2f(1080.0f, 670.0f), sf::Vector2f(0.0f, 0.0f)));
    background2.push_back(Background(&bgtextture2[5], 0.f, 0, sf::Vector2f(1080.0f, 670.0f), sf::Vector2f(0.0f, 0.0f)));

    background.push_back(Background(&bgtextture[6], 130.f, 1, sf::Vector2f(1084.0f, 780.0f), sf::Vector2f(0.f, -0.0f)));
    background2.push_back(Background(&bgtextture2[6], 130.f, 2, sf::Vector2f(1084.0f, 780.0f), sf::Vector2f(1080.0f, 720.0f)));
    background.push_back(Background(&bgtextture[7], -70.f, 1, sf::Vector2f(1084.0f, 740.0f), sf::Vector2f(0.f, -0.0f)));
    background2.push_back(Background(&bgtextture2[7], -70.f, 2, sf::Vector2f(1084.0f, 740.0f), sf::Vector2f(1080.0f, 720.0f)));
    background.push_back(Background(&bgtextture[8], 90.f, 1, sf::Vector2f(1084.0f, 720.0f), sf::Vector2f(0.f, -0.0f)));
    background2.push_back(Background(&bgtextture2[8], 90.f, 2, sf::Vector2f(1084.0f, 720.0f), sf::Vector2f(1080.0f, 720.0f)));

    background.push_back(Background(&bgtextture[9], 20.f, 0, sf::Vector2f(960.0f, 770.0f), sf::Vector2f(0.0f, 0.0f)));
    background2.push_back(Background(&bgtextture2[9], 20.f, 0, sf::Vector2f(960.0f, 770.0f), sf::Vector2f(0.0f, 0.0f)));

    float deltatime = .0f;
    sf::Clock clock;

    while (window.isOpen()) 
    {
        deltatime = clock.restart().asSeconds();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

        if (deltatime > 1.0f / 30.0f)
            deltatime = 1.0f / 30.0f;
        sf::Event ev;
        while (window.pollEvent(ev)) 
        {
            switch (ev.type)
            {
            case sf::Event::Closed :
                window.close();
                break;
            }
        }
        for (int i = 0 ; i < 10 ; i++) 
        { 
            background[i].Update(deltatime);
            background2[i].Update(deltatime);
        }

        window.clear();

        for (int i = 0; i < 10; i++)
        {
            background[i].Draw(window);
            background2[i].Draw(window);
        }
        window.display();
    }
    return 0;
}