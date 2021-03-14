#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{
	age = 0;
	eventCheck = 0;
	srand(time(0));

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

void GameState::creatButtons(int buttonCount, std::string string1, std::string string2, std::string string3 = NULL, std::string string4 = NULL)
{
	//(x, y, width, height, font, "text", text size , idle color, hover color, active color, text color)
	//(x, y, กว้าง, ยาว, ฟ้อนต์, ข้อความ, ขนาดข้อความ , สีปุ่มตอนปกติ, สีปุ่มตอนปกติ, สีปุ่มตอนปกติ, สีข้อความ)
	if (buttonCount == 2) {
		this->eventSelectButton1 = new Button(600, 100, 150, 50, &this->font, string1, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
		this->eventSelectButton2 = new Button(600, 200, 150, 50, &this->font, string2, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
		
	}
	else if (buttonCount == 3) {
		this->eventSelectButton1 = new Button(600, 100, 150, 50, &this->font, string1, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
		this->eventSelectButton2 = new Button(600, 200, 150, 50, &this->font, string2, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
		this->eventSelectButton3 = new Button(600, 300, 150, 50, &this->font, string3, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
		
	}
	else if (buttonCount == 4) {
		this->eventSelectButton1 = new Button(600, 100, 150, 50, &this->font, string1, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
		this->eventSelectButton2 = new Button(600, 200, 150, 50, &this->font, string2, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
		this->eventSelectButton3 = new Button(600, 300, 150, 50, &this->font, string3, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
		this->eventSelectButton4 = new Button(600, 400, 150, 50, &this->font, string4, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

	}
}

void GameState::deleteButtons(int buttonCountn)
{
	if (buttonCount == 2) {
		delete this->eventSelectButton1;
		delete this->eventSelectButton2;
	}
	else if (buttonCount == 3) {
		delete this->eventSelectButton1;
		delete this->eventSelectButton2;
		delete this->eventSelectButton3;

	}
	else if (buttonCount == 4) {
		delete this->eventSelectButton1;
		delete this->eventSelectButton2;
		delete this->eventSelectButton3;
		delete this->eventSelectButton4;
	}
}



void GameState::endState()
{
	std::cout << "\nEnding GameState!\n";
}

void GameState::updateAge()
{
	std::cout << age << " y/o\n\n";
}

void GameState::renderButtons(int buttonCount)
{
}

void GameState::Ev(int age)
{
	std::cout << "Ev\n";
		
		randtype = random(101);
		eventCheck = 0;

		Evnow = 0;
			return;

		//เหตุการณ์ปกติ 
		if (randtype >= 10 && randtype <= 100) {
			Evnow = random(20);
			return;
		}

		//ตายเพราะแม่ทำแท้ง
		else if (randtype == 0 && age == 0) {

			std::cout << "you death" << std::endl;
			return;
		}

		//เหตุการณ์พิเศษ
		else {

			Evnow = random(10,20);
			return;
		}
	
}

void GameState::creatEvent(int Evnow)
{
	if (age >= 0 && age <= 5) { // baby
		switch (Evnow) {
		case 0: //Tooth_decay

			std::cout << "event1\n";
			eventCheck = 1;

			//ข้อความเหตุการณ์
			eventText = "Go to a doctor to treat your Tooth";

			//ข้อความตัวเลือก
			eventSelectText1 = "aaa";
			eventSelectText2 = "bbb";
			
			buttonCount = 2;

			this->creatButtons(buttonCount, eventSelectText1, eventSelectText2);

			std::cout << "Go to a doctor to treat your Tooth" << std::endl;

			//Health -= random(6) + 5;

		case 1: //injec_vaccine
			eventCheck = 1;

			//ข้อความเหตุการณ์
			eventText = "Go to a doctor to treat your Tooth";

			//ข้อความตัวเลือก
			eventSelectText1 = "sss";
			eventSelectText2 = "ddd";

			

		}

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
		age++;
		this->updateAge();
		this->updateEvent();
		//eventSelectText1 = "aaa";
	}

	if (this->eventSelectButton1->isPressed())
	{
		answer = 1;
	}

	if (this->eventSelectButton2->isPressed())
	{
		answer = 2;
	}

	if (this->eventSelectButton3->isPressed())
	{
		answer = 3;
	}

	if (this->eventSelectButton4->isPressed())
	{
		answer = 4;
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

void GameState::updateEvent()
{
	
	
	this->Ev(age);
	this->creatEvent(Evnow);

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

	
	if (eventCheck)
	{
		this->eventSelectButton1->renderButton(target);
		this->eventSelectButton2->renderButton(target);
	}
	
	
	
	

}