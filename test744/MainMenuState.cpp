#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{
	this->initFont();

	//(x, y, width, height, font, "text", text size , idle color, hover color, active color, text color)
	this->gamestate_btn = new Button(100, 100, 150, 50, &this->font, "NEW GAME", 25, sf::Color(70,70,70,200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
	this->acheivment_btn = new Button(100, 200, 150, 50, &this->font, "ACHEIVMENT", 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
	this->exit_btn = new Button(100, 300, 150, 50, &this->font, "EXIT", 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

	backgroundTexture.loadFromFile("bgMainmanu.jpg");


	this->Background.setSize(sf::Vector2f(1080, 720));
	
	this->Background.setTexture(&backgroundTexture);

	std::cout << "\nStarting MainMenuState!\n";

	
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
	this->gamestate_btn->update(this->mousePosView);
	this->acheivment_btn->update(this->mousePosView);
	this->exit_btn->update(this->mousePosView);

	if (this->gamestate_btn->isPressed())
	{
		
		this->states->push(new GameState(this->window, this->states));
	}

	if (this->acheivment_btn->isPressed())
	{
		std::cout << "COMING SOON\n";
	}

	
	if (this->exit_btn->isPressed())
	{
		std::cout << "\nexit btn is clicked!\n";
		this->quit = true;
	}


}

void MainMenuState::updateInputs(const float& dt)
{
	this->checkForQuit();
}



void MainMenuState::update(const float& dt)
{
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

	this->gamestate_btn->renderButton(target);
	this->acheivment_btn->renderButton(target);
	this->exit_btn->renderButton(target);
	
}