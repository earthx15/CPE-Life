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

	if (!this->font2.loadFromFile("font/upcjl.ttf"))
	{
		throw("Error : Could not load ThaiFont\n");
	}

}

void State::updateMousePos()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void State::initbg()
{
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
	bgtextture[10].loadFromFile("./image/cloud01.png");
	bgtextture2[10].loadFromFile("./image/cloud01.png");



	background.push_back(Backgrounds(&bgtextture[0], 0.f, 0, sf::Vector2f(1080.0f, 720.0f), sf::Vector2f(0.0f, -100.0f)));
	background2.push_back(Backgrounds(&bgtextture2[0], 0.f, 0, sf::Vector2f(1080.0f, 720.0f), sf::Vector2f(0.0f, -100.0f)));

	background.push_back(Backgrounds(&bgtextture[1], 0.f, 0, sf::Vector2f(1080.0f, 770.0f), sf::Vector2f(0.0f, -30.0f)));
	background2.push_back(Backgrounds(&bgtextture2[1], 0.f, 0, sf::Vector2f(1080.0f, 770.0f), sf::Vector2f(0.0f, -30.0f)));

	background.push_back(Backgrounds(&bgtextture[2], 0.f, 0, sf::Vector2f(1080.0f, 220.0f), sf::Vector2f(1080.0f, -20.0f)));
	background2.push_back(Backgrounds(&bgtextture2[2], 0.f, 0, sf::Vector2f(1080.0f, 220.0f), sf::Vector2f(1080.0f, -20.0f)));

	background.push_back(Backgrounds(&bgtextture[3], 0.f, 0, sf::Vector2f(1080.0f, 670.0f), sf::Vector2f(0.0f, 0.0f)));
	background2.push_back(Backgrounds(&bgtextture2[3], 0.f, 0, sf::Vector2f(1080.0f, 670.0f), sf::Vector2f(0.0f, 0.0f)));
	background.push_back(Backgrounds(&bgtextture[4], 0.f, 0, sf::Vector2f(1080.0f, 670.0f), sf::Vector2f(0.0f, 0.0f)));
	background2.push_back(Backgrounds(&bgtextture2[4], 0.f, 0, sf::Vector2f(1080.0f, 670.0f), sf::Vector2f(0.0f, 0.0f)));
	background.push_back(Backgrounds(&bgtextture[5], 0.f, 0, sf::Vector2f(1080.0f, 670.0f), sf::Vector2f(0.0f, 0.0f)));
	background2.push_back(Backgrounds(&bgtextture2[5], 0.f, 0, sf::Vector2f(1080.0f, 670.0f), sf::Vector2f(0.0f, 0.0f)));

	background.push_back(Backgrounds(&bgtextture[6], 130.f, 1, sf::Vector2f(1084.0f, 780.0f), sf::Vector2f(0.f, -0.0f)));
	background2.push_back(Backgrounds(&bgtextture2[6], 130.f, 2, sf::Vector2f(1084.0f, 780.0f), sf::Vector2f(1080.0f, 720.0f)));
	background.push_back(Backgrounds(&bgtextture[7], -70.f, 1, sf::Vector2f(1084.0f, 740.0f), sf::Vector2f(0.f, -0.0f)));
	background2.push_back(Backgrounds(&bgtextture2[7], -70.f, 2, sf::Vector2f(1084.0f, 740.0f), sf::Vector2f(1080.0f, 720.0f)));
	background.push_back(Backgrounds(&bgtextture[8], 90.f, 1, sf::Vector2f(1084.0f, 720.0f), sf::Vector2f(0.f, -0.0f)));
	background2.push_back(Backgrounds(&bgtextture2[8], 90.f, 2, sf::Vector2f(1084.0f, 720.0f), sf::Vector2f(1080.0f, 720.0f)));

	background.push_back(Backgrounds(&bgtextture[9], 20.f, 0, sf::Vector2f(960.0f, 770.0f), sf::Vector2f(0.0f, 0.0f)));
	background2.push_back(Backgrounds(&bgtextture2[9], 20.f, 0, sf::Vector2f(960.0f, 770.0f), sf::Vector2f(0.0f, 0.0f)));

	background.push_back(Backgrounds(&bgtextture[10], 45.f, 0, sf::Vector2f(1080.0f, 720.0f), sf::Vector2f(0.0f, 0.0f)));
	background2.push_back(Backgrounds(&bgtextture2[10], 45.f, 0, sf::Vector2f(1080.0f, 720.0f), sf::Vector2f(0.0f, 0.0f)));
}