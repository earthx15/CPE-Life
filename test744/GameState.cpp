#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{
	age = 0;

	this->initFont();
	
	//(x, y, width, height, font, "text", idle color, hover color, active color)
	this->backToState_btn = new Button(600, 500, 150, 50, &this->font, "Back", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
	this->aged_btn = new Button(600, 100, 150, 50, &this->font, "aged!", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

	//(x, y, width, height, font, "text", data )
	this->ageShow = new Button(100, 100, 150, 50, &this->font, "age : ", age, sf::Color::White);
	this->dataI = new Button(100, 150, 150, 50, &this->font, "data I : ", age, sf::Color::White);
	this->dataII = new Button(100, 200, 150, 50, &this->font, "data II : ", age, sf::Color::White);
	this->dataIII = new Button(100, 250, 150, 50, &this->font, "data III : ", age, sf::Color::White);
	this->dataIV = new Button(100, 300, 150, 50, &this->font, "data IV : ", age, sf::Color::White);
	this->dataV = new Button(100, 350, 150, 50, &this->font, "data V : ", age, sf::Color::White);
	

	this->Background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->Background.setFillColor(sf::Color::Black);

	std::cout << "\nStarting GameState!\n";

}

GameState::~GameState()
{
	age = 0;

	delete this->backToState_btn;
	delete this->aged_btn;
	
	delete this->ageShow;
	delete this->dataI;
	delete this->dataII;
	delete this->dataIII;
	delete this->dataIV;
	delete this->dataV;
}

void GameState::endState()
{
	std::cout << "\nEnding GameState!\n";
}

void GameState::updateAge()
{
	std::cout << age << " y/o\n\n";
}

void GameState::updateButtons()
{
	this->backToState_btn->update(this->mousePosView);
	this->aged_btn->update(this->mousePosView);

	

	if (this->backToState_btn->isPressed())
	{
		this->quit = true;
	}

	if (this->aged_btn->isPressed())
	{
		age++;
		this->updateAge();
		
	}
}

void GameState::updateInputs(const float& dt)
{
	this->checkForQuit();
}

void GameState::updateText()
{
	delete this->ageShow;
	this->ageShow = new Button(100, 100, 150, 50, &this->font, "age : ", age, sf::Color::White);

	delete this->dataI;
	this->dataI = new Button(100, 150, 150, 50, &this->font, "data I : ", age, sf::Color::White);
	
	delete this->dataII;
	this->dataII = new Button(100, 200, 150, 50, &this->font, "data II : ", age, sf::Color::White);
	
	delete this->dataIII;
	this->dataIII = new Button(100, 250, 150, 50, &this->font, "data III : ", age, sf::Color::White);
	
	delete this->dataIV;
	this->dataIV = new Button(100, 300, 150, 50, &this->font, "data IV : ", age, sf::Color::White);
	
	delete this->dataV;
	this->dataV = new Button(100, 350, 150, 50, &this->font, "data V : ", age, sf::Color::White);
}

void GameState::update(const float& dt)
{
	this->updateMousePos();
	
	this->updateInputs(dt);
	
	this->updateButtons();

	this->updateText();

}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
		
	target->draw(this->Background);

	//render buttons
	this->aged_btn->renderButton(target);
	this->backToState_btn->renderButton(target);
	
	//render text
	
	this->ageShow->renderText(target);
	this->dataI->renderText(target);
	this->dataII->renderText(target);
	this->dataIII->renderText(target);
	this->dataIV->renderText(target);
	this->dataV->renderText(target);

}