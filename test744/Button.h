#ifndef BUTTON_H
#define BUTTON_H

#include "Entity.h"

enum button_state{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button
{

private:
	short unsigned buttonState;

	sf::RectangleShape buttonShape;
	sf::Font* font;
	sf::Text buttonText;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
	sf::Color textColor;

	bool mode;

public:
	Button(float x, float y, float width, float height,
		sf::Font * font, std::string text, 
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, sf::Color textColor);
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text, int data, sf::Color textColor);
	~Button();

	//Acessesors
	const bool isPressed() const;

	//Functions
	void update(const sf::Vector2f mousePos);
	void renderButton(sf::RenderTarget * target);
	void renderText(sf::RenderTarget* target);


};

#endif

