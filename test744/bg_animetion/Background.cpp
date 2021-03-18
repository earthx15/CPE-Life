#include "Background.h"

Background::Background(sf::Texture* texture, float speed, int number, sf::Vector2f sizes, sf::Vector2f positions)
{
	this->number = number;
	this->speed = speed;
	this->size = sizes;
	this->position = positions;
	
	body[0].setPosition(positions);
	body[1].setPosition(positions);
	body[0].setSize(size);
	body[1].setSize(size);
	body[0].setTexture(texture);
	body[1].setTexture(texture);

	if (speed < 0)
		body[1].setPosition(size.x - 2.f,positions.y);
	else body[1].setPosition(-size.x + 2.f, positions.y);
}

void Background::Update(float deltatime)
{
	
	if (number != 0) // water
	{
		for (int i = 0; i < 2; i++) 
		{
			position = body[i].getPosition();
			body[i].move(speed * deltatime , 0);
		
			//std::cout << "size = " << -size.x << " position1 = " << position.x << std::endl;
			//std::cout << "size = " << -size.x << " position2 = " << position.x << std::endl;
			
			if (position.x <= -1078.f && speed < 0)
			{
				if (number == 1) body[i].setPosition(1080.f + 0.f, position.y);
				else body[i].setPosition(1080.f - 0.f, position.y);
			}
			if (position.x >= 1065.f && speed > 0) 
			{
				if (number == 1) body[i].setPosition(-1080.f + 0.f, position.y);
				else body[i].setPosition(-1080.f -0.f, position.y);
			}
			
		}
	}
	else if (number == 0)
	{
		for (int i = 0; i < 2; i++)
		{
			position = body[i].getPosition();
			body[i].move(speed * deltatime, 0);

			std::cout << "size = " << -size.x << " position1 = " << position.x << std::endl;
			std::cout << "size = " << -size.x << " position2 = " << position.x << std::endl;

			if (position.x <= -size.x && speed < 0)
			{
				body[i].setPosition(size.x - 4.f, position.y);
			}
			if (position.x >= size.x && speed > 0)
			{
				body[i].setPosition(-size.x + 4.f, position.y);
			}

		}
	}

}

void Background::Draw(sf::RenderWindow& window)
{
	window.draw(body[0]);
	window.draw(body[1]);
}
