#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{
	this->initFont();
	this->initbg();

	//(x, y, width, height, font, "text", text size , idle color, hover color, active color, text color)
	this->gamestate_btn = new Button(465, 350, 150, 50, &this->font, "NEW GAME", 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
	this->acheivment_btn = new Button(465, 450, 150, 50, &this->font, "How to play", 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
	this->exit_btn = new Button(465, 550, 150, 50, &this->font, "EXIT", 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

	this->backToState_btn = new Button(10, 660, 150, 50, &this->font, "Back", 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

	backgroundTexture.loadFromFile("bgMainmanu.jpg");

	this->Background.setSize(sf::Vector2f(1080, 720));

	this->Background.setTexture(&backgroundTexture);

	HTPTexture.loadFromFile("How To Play.png");

	this->HTP.setSize(sf::Vector2f(800, 700));

	this->HTP.setTexture(&HTPTexture);

	this->HTP.setPosition(140, 10);

	std::cout << "\nStarting MainMenuState!\n";

	htpCheck = false;
}

MainMenuState::~MainMenuState()
{

	delete this->gamestate_btn;
	delete this->acheivment_btn;
	delete this->exit_btn;
}

void MainMenuState::endState()
{
	std::cout << "\nEnding MainMenuState!\n";
}

void MainMenuState::updateButtons()
{

	if (htpCheck == false)
	{
		this->gamestate_btn->update(this->mousePosView);
		this->acheivment_btn->update(this->mousePosView);
		this->exit_btn->update(this->mousePosView);
	}


	this->backToState_btn->update(this->mousePosView);

	if (this->gamestate_btn->isPressed())
	{

		this->states->push(new GameState(this->window, this->states));
	}

	if (this->acheivment_btn->isPressed())
	{
		htpCheck = true;
	}


	if (this->exit_btn->isPressed())
	{
		std::cout << "\nexit btn is clicked!\n";
		this->quit = true;
	}

	if (this->backToState_btn->isPressed() && htpCheck == true)
	{
		htpCheck = false;
	}

}

void MainMenuState::updateInputs(const float& dt)
{
	this->checkForQuit();
}



void MainMenuState::update(const float& dt)
{
	for (int i = 0; i < 11; i++)
	{
		background[i].Update(dt);
		background2[i].Update(dt);
	}
	this->updateMousePos();

	this->updateButtons();
	this->updateInputs(dt);



	//system("cls");
	//std::cout << mousePos.x << " " << mousePos.y << "\n";


}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = window;

	target->draw(this->Background);
	for (int i = 0; i < 11; i++)
	{
		background[i].Draw(*window);
		background2[i].Draw(*window);
	}

	this->gamestate_btn->renderButton(target);
	this->acheivment_btn->renderButton(target);
	this->exit_btn->renderButton(target);

	if (htpCheck)
	{
		target->draw(this->HTP);
		this->backToState_btn->renderButton(target);
	}
}