#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window)
	:State(window)
{
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::endState()
{
}

void MainMenuState::updateKeybinds(const float& dt)
{
	this->checkForQuit();
}

void MainMenuState::update(const float& dt)
{
	this->updateKeybinds(dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		std::cout << "S\n";
}

void MainMenuState::render(sf::RenderTarget* target)
{
}
