#ifndef BG
#define BG

#include <SFML/Graphics.hpp>
#include <iostream>


class Background
{
public :
	Background(sf::Texture* texture, float speed, int number ,sf::Vector2f sizes, sf::Vector2f positions);

	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
private:
	sf::RectangleShape body[2];
	sf::Vector2f position;
	sf::Vector2f size;

	float speed;
	int number;
};

#endif