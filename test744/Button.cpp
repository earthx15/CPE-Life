#include "Button.h"

//button
Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, int textSize,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, sf::Color textColor)
{
	
	
	this->buttonState = BTN_IDLE;
	
	this->buttonShape.setPosition(sf::Vector2f(x, y));
	this->buttonShape.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->buttonText.setFont(*this->font);
	this->buttonText.setString(text);
	this->buttonText.setFillColor(textColor);
	this->buttonText.setCharacterSize(textSize);
	this->buttonText.setPosition(
		this->buttonShape.getPosition().x + (this->buttonShape.getGlobalBounds().width / 2.f) - this->buttonText.getGlobalBounds().width / 2.f,
		this->buttonShape.getPosition().y + (this->buttonShape.getGlobalBounds().height / 3.f) - this->buttonText.getGlobalBounds().height / 2.f
	);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->buttonShape.setFillColor(this->idleColor);
}

//dataText
Button::Button(float x, float y, sf::Font* font, int textSize, std::string text, int data, sf::Color textColor)
{


	this->buttonState = BTN_IDLE;
	this->buttonText.setPosition(sf::Vector2f(x, y));
	

	this->font = font;
	this->buttonText.setFont(*this->font);
	this->buttonText.setString(text + std::to_string(data));
	this->buttonText.setFillColor(textColor);
	this->buttonText.setCharacterSize(textSize);
	

}



Button::~Button()
{
	mode = 0;
}

const bool Button::isPressed() const
{
	if (buttonState == BTN_ACTIVE)
		return true;
	
	return false;
}

//updateButton
void Button::update(const sf::Vector2f mousePos)
{
	
	//IDLE
	this->buttonState = BTN_IDLE;

	//HOVER
	if (this->buttonShape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;

		//ACTIVE
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if(mode == 0)
			this->buttonState = BTN_ACTIVE;
			mode = 1;
		}

		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
			mode = 0;

	}
	else
		mode = 0;

	switch (buttonState)
	{
	case BTN_IDLE:
		this->buttonShape.setFillColor(this->idleColor);
		break;
	
	case BTN_HOVER:
		this->buttonShape.setFillColor(this->hoverColor);
		break;
	
	case BTN_ACTIVE:
		this->buttonShape.setFillColor(this->activeColor);
		break;

	default:
		this->buttonShape.setFillColor(sf::Color::Red);
		break;
	}



}

//render button
void Button::renderButton(sf::RenderTarget* target)
{
	target->draw(this->buttonShape);
	target->draw(this->buttonText);
}

//render text
void Button::renderText(sf::RenderTarget* target)
{
	target->draw(this->buttonText);
}



