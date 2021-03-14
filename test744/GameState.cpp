#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{
	
	srand(time(0));
	eventCheck = false;

	this->initFont();

	//(x, y, width, height, font, "text", text size , idle color, hover color, active color, text color)
	this->backToState_btn = new Button(600, 500, 150, 50, &this->font, "Back", 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
	this->aged_btn = new Button(415, 380, 250, 100, &this->font, "aged!", 60, sf::Color(70, 70, 70, 250), sf::Color(150, 150, 150, 250), sf::Color(20, 20, 20, 250), sf::Color::White);

	//(x, y, font, text size, "text", data, text color)
	this->ageShow = new Button(100, 100, &this->font, 25, "age : ", age, sf::Color::White);
	this->dataI = new Button(250, 600, &this->font, 25, "Happiness : ", Happiness, sf::Color::White);
	this->dataII = new Button(400, 600, &this->font, 25, "Health : ", Health, sf::Color::White);
	this->dataIII = new Button(550, 600, &this->font, 25, "Smart : ", Smart, sf::Color::White);
	this->dataIV = new Button(700, 600, &this->font, 25, "Look : ", Look, sf::Color::White);
	this->dataV = new Button(850, 600, &this->font, 25, "Moral : ", Moral, sf::Color::White);

	this->Background.setSize(sf::Vector2f(1080,720));
	this->Background.setFillColor(sf::Color::Black);
	
	this->BackgroundLog.setSize(sf::Vector2f(540 , 540));
	this->BackgroundLog.setFillColor(sf::Color::Blue);
	this->BackgroundLog.setPosition(0 , 0);
	
	this->BackgroundSituation.setSize(sf::Vector2f(540, 540));
	this->BackgroundSituation.setFillColor(sf::Color::Green);
	this->BackgroundSituation.setPosition(540, 0);
	
	this->BackgroundName.setSize(sf::Vector2f(200,100));
	this->BackgroundName.setFillColor(sf::Color::Red);
	this->BackgroundName.setPosition(0, 0);
	
	this->BackgroundStatus.setSize(sf::Vector2f(1080, 180));
	this->BackgroundStatus.setFillColor(sf::Color::Yellow);
	this->BackgroundStatus.setPosition(0, 540);

	this->eventSelectButton1 = new Button(600, 100, 150, 50, &this->font, eventSelectText1, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
	this->eventSelectButton2 = new Button(600, 200, 150, 50, &this->font, eventSelectText2, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

	
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


int GameState::random(int n, int x)
{
	return rand()%n+x;
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

	this->eventSelectButton1->update(this->mousePosView);

	if (this->backToState_btn->isPressed())
	{
		this->quit = true;
	}

	if (this->aged_btn->isPressed())
	{
		eventCheck = false;
		age++;
		this->updateAge();

		int x = rand() % 5;
		if (x == 2)
			eventCheck = true;


		
	}

	if (this->eventSelectButton1->isPressed())
	{
		Happiness++;
		
	}


}

void GameState::updateInputs(const float& dt)
{
	this->checkForQuit();
}

void GameState::updateText()
{
	delete this->ageShow;
	this->ageShow = new Button(100, 100, &this->font, 25, "age : ", age, sf::Color::White);

	delete this->dataI;
	this->dataI = new Button(250, 600, &this->font, 25, "Happiness : ", Happiness, sf::Color::White);
	
	delete this->dataII;
	this->dataII = new Button(400, 600, &this->font, 25, "Health : ", Health, sf::Color::White);
	
	delete this->dataIII;
	this->dataIII = new Button(550, 600, &this->font, 25, "Smart : ", Smart, sf::Color::White);
	
	delete this->dataIV;
	this->dataIV = new Button(700, 600, &this->font, 25, "Look : ", Look, sf::Color::White);
	
	delete this->dataV;
	this->dataV = new Button(850, 600, &this->font, 25, "Moral : ", Moral, sf::Color::White);

	

}






//update
void GameState::update(const float& dt)
{
	this->updateMousePos();
	
	this->updateInputs(dt);
	
	this->updateButtons();

	this->updateText();

	

}

//render
void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
		
	target->draw(this->Background);
	target->draw(this->BackgroundLog);
	target->draw(this->BackgroundName);
	target->draw(this->BackgroundStatus);
	target->draw(this->BackgroundSituation);

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

	
	if (eventCheck == true)
		this->eventSelectButton1->renderButton(target);

}