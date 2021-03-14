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
	this->eventSelectButton3 = new Button(600, 300, 150, 50, &this->font, eventSelectText3, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
	this->eventSelectButton4 = new Button(600, 400, 150, 50, &this->font, eventSelectText4, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

	this->eventTextButton = new Button(900, 0, 150, 50, &this->font, eventText, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


	
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

int GameState::eventRandom()
{
	randtype = random(5,10);
	if (randtype >= 10 && randtype <= 100) {;
	Evnow = random(babyEvent);
	}
	else if (randtype == 0 && age == 0) {
		std::cout << "you death" << std::endl;
	}
	else {
		Evnow = random(specialEvent);
	}

	return Evnow;
}

void GameState::creatEvent(int Evnow)
{

	//baby event
	if (age >= 0 && age <= 5)
	{
		switch (Evnow)
		{
		case 0:
			
			eventSelectText1 = "aaa";
			eventSelectText2 = "bbb";

			eventText = "ddd";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(600, 100, 150, 50, &this->font, eventSelectText1, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(600, 200, 150, 50, &this->font, eventSelectText2, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;
			
			std::cout << "case 0\n";
			break;
		case 1:

			std::cout << "case 1\n";
			break;
		case 2:

			std::cout << "case 2\n";
			break;
		case 3:

			std::cout << "case 3\n";
			break;
		case 4:

			std::cout << "case 4\n";
			break;
		}
	}


}

void GameState::updateAge()
{
	std::cout << age << " y/o\n\n";
}

void GameState::updateAnswer()
{
	switch (Evnow)
	{
	case 0:
		switch (answer)
		{
		case 1:
			Happiness++;
			answer = 0;
			break;
		case 2:
			Health++;
			answer = 0;
			break;
		}
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	}
}



void GameState::updateButtons()
{
	this->backToState_btn->update(this->mousePosView);
	this->aged_btn->update(this->mousePosView);

	this->eventSelectButton1->update(this->mousePosView);
	this->eventSelectButton2->update(this->mousePosView);
	this->eventSelectButton3->update(this->mousePosView);
	this->eventSelectButton4->update(this->mousePosView);

	if (this->backToState_btn->isPressed())
	{
		this->quit = true;
	}

	if (this->aged_btn->isPressed())
	{
		answer = 0;
		eventCheck = false;
		age++;
		this->updateAge();

		this->creatEvent(eventRandom());

	}

	if (this->eventSelectButton1->isPressed())
	{
		
		answer = 1;
		
		eventCheck = false;
		
	}

	if (this->eventSelectButton2->isPressed())
	{
		answer = 2;
		
		eventCheck = false;
	}

	if (this->eventSelectButton3->isPressed())
	{
		answer = 3;
		Happiness--;
		eventCheck = false;
	}

	if (this->eventSelectButton4->isPressed())
	{
		answer = 4;
		Health--;
		eventCheck = false;
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

	delete this->eventTextButton;
	this->eventTextButton = new Button(900, 0, 150, 50, &this->font, eventText, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

}






//update
void GameState::update(const float& dt)
{
	this->updateMousePos();
	
	this->updateInputs(dt);
	
	this->updateButtons();

	this->updateText();

	this->updateAnswer();

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
		
		switch (buttonCount)
		{
		case 2:
			this->eventTextButton->renderButton(target);
			
			this->eventSelectButton1->renderButton(target);
			this->eventSelectButton2->renderButton(target);
			break;
		case 3:
			this->eventTextButton->renderButton(target);
			
			this->eventSelectButton1->renderButton(target);
			this->eventSelectButton2->renderButton(target);
			this->eventSelectButton3->renderButton(target);
			break;
		case 4:
			this->eventTextButton->renderButton(target);
			
			this->eventSelectButton1->renderButton(target);
			this->eventSelectButton2->renderButton(target);
			this->eventSelectButton3->renderButton(target);
			this->eventSelectButton4->renderButton(target);
			break;
		}
		

}