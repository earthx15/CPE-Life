#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{

	this->initFont();
	
	this->backToState_btn = new Button(200, 100, 150, 50, &this->font, "Back", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

	this->Background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->Background.setFillColor(sf::Color::Black);

	std::cout << "\nStarting GameState!\n";

}

GameState::~GameState()
{
	delete this->backToState_btn;
}

void GameState::endState()
{
	std::cout << "\nEnding GameState!\n";
}

void GameState::updateButtons()
{
	this->backToState_btn->update(this->mousePosView);

	if (this->backToState_btn->isPressed())
	{
		this->quit = true;
	}
}

void GameState::updateInputs(const float& dt)
{
	this->checkForQuit();
}

void GameState::update(const float& dt)
{
	this->updateMousePos();
	
	this->updateInputs(dt);
	
	this->updateButtons();

}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
		
	target->draw(this->Background);

	this->backToState_btn->render(target);
}