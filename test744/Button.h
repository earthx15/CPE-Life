#ifndef BUTTON_H
#define BUTTON_H

#include "Entity.h"

enum button_state { BTN_IDLE, BTN_HOVER, BTN_ACTIVE };

class Button
{

private:
	short unsigned buttonState;

	float x;
	float y;
	float width;
	float height;
	std::string text;
	int textSize;

	sf::RectangleShape buttonShape;
	sf::Font* font;
	sf::Text buttonText;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
	sf::Color textColor;

	bool mode;

public:
	//Button for click
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text, int textSize,
		sf::Color idleColor, sf::Color hoverColor,
		sf::Color activeColor, sf::Color textColor);

	//Text showing
	Button(float x, float y, sf::Font* font, int textSize, std::string text, int data, sf::Color textColor);

	~Button();

	//Acessesors
	const bool isPressed() const;

	//Functions
	void update(const sf::Vector2f mousePos);
	void renderButton(sf::RenderTarget* target);
	void renderText(sf::RenderTarget* target);


};

#endif
