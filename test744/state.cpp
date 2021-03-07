#include "state.h"

State::State(sf::RenderWindow* window, std::stack<State*>* states)
{
	this->window = window;
	this->states = states;
	this->quit = false;
}

State::~State()
{
}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}

void State::initFont()
{
	if (!this->font.loadFromFile("font/BebasNeue-Regular.ttf"))
	{
		throw("Error : Could not load Font\n");
	}
}

void State::updateMousePos()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}


