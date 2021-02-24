#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML works!",sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    player.setFillColor(sf::Color::Red);
    player.setOrigin(50.0f, 50.0f);
    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                printf("New window width: %i New window height: %i\n", evnt.size.width, evnt.size.height);
                break;
            case sf::Event::TextEntered:
                if (evnt.text.unicode<128)
                {
                    printf("%c", evnt.text.unicode);
                }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            player.move(-0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            player.move(0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            player.move(0.0f, -0.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            player.move(0.0f, 0.1f);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousepos = sf::Mouse::getPosition(window);
            player.setPosition((float)mousepos.x,(float)mousepos.y);
        }
        window.clear();
        window.draw(player);
        window.display();
    }
    return 0;
}