#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{

	srand(time(0));
	eventCheck = false;
	selectSize = 20;

	this->initFont();

	//(x, y, width, height, font, "text", text size , idle color, hover color, active color, text color)
	this->backToState_btn = new Button(10, 660, 150, 50, &this->font, "Back", 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
	this->aged_btn = new Button(415, 420, 250, 100, &this->font, "aged!", 60, sf::Color(70, 70, 70, 250), sf::Color(150, 150, 150, 250), sf::Color(20, 20, 20, 250), sf::Color::White);

	//(x, y, font, text size, "text", data, text color)
	this->ageShow = new Button(100, 100, &this->font, 25, "age : ", age, sf::Color::White);
	this->dataI = new Button(250, 600, &this->font, 25, "Happiness : ", Happiness, sf::Color::White);
	this->dataII = new Button(400, 600, &this->font, 25, "Health : ", Health, sf::Color::White);
	this->dataIII = new Button(550, 600, &this->font, 25, "Smart : ", Smart, sf::Color::White);
	this->dataIV = new Button(700, 600, &this->font, 25, "Look : ", Look, sf::Color::White);
	this->dataV = new Button(850, 600, &this->font, 25, "Moral : ", Moral, sf::Color::White);

	this->Background.setSize(sf::Vector2f(1080, 720));
	this->Background.setFillColor(sf::Color::Black);

	this->BackgroundLog.setSize(sf::Vector2f(540, 540));
	this->BackgroundLog.setFillColor(sf::Color::Blue);
	this->BackgroundLog.setPosition(0, 0);

	this->BackgroundSituation.setSize(sf::Vector2f(540, 540));
	this->BackgroundSituation.setFillColor(sf::Color::Green);
	this->BackgroundSituation.setPosition(540, 0);

	this->BackgroundName.setSize(sf::Vector2f(200, 100));
	this->BackgroundName.setFillColor(sf::Color::Red);
	this->BackgroundName.setPosition(0, 0);

	this->BackgroundStatus.setSize(sf::Vector2f(1080, 180));
	this->BackgroundStatus.setFillColor(sf::Color::Black);
	this->BackgroundStatus.setPosition(0, 540);

	this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
	this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
	this->eventSelectButton3 = new Button(570, 340, 225, 50, &this->font, eventSelectText3, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
	this->eventSelectButton4 = new Button(820, 340, 225, 50, &this->font, eventSelectText4, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

	this->eventTextButton = new Button(610, 60, 400, 200, &this->font2, eventText, 35, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



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
	return rand() % n + x;
}

void GameState::endState()
{
	std::cout << "\nEnding GameState!\n";
}


//event
int GameState::eventRandom()
{



	randtype = random(101);
	if (randtype >= 20 && randtype <= 100) {
		if (age >= 0 && age <= 5)
			Evnow = random(babyEvent);
		if (age >= 6 && age <= 14)
			Evnow = random(childEvent);
		if (age >= 15 && age <= 18)
			Evnow = random(seccondaryEvent);
		if (age >= 19 && age <= 22)
			Evnow = random(bachelorEvent);
		if (age >= 23 && age <= 40)
			Evnow = random(primaryAdultEvent);
		if (age >= 41 && age <= 60)
			Evnow = random(secondaryAdultEvent);
		if (age >= 61)
			Evnow = random(elderlyEvent);
	}
	else if (randtype == 0 && age == 0) {
		Evnow = -1;

		std::cout << "you death" << std::endl;
	}
	else {
		Evnow = random(specialEvent);
	}

	return Evnow;
}

void GameState::creatEvent(int Evnow)
{

	if (Evnow == -1)
	{
		eventText = "You are dead. xd"; \

			eventSelectText1 = "Back to main menu.";

		delete this->eventSelectButton1;
		this->eventSelectButton1 = new Button(695, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

		buttonCount = 1;
		eventCheck = 1;

		return;
	}

	//baby event
	if (age >= 0 && age <= 5)
	{
		switch (Evnow)
		{
			//baby
		case 0:

			eventSelectText1 = "Tell dad the truth. ";
			eventSelectText2 = "Nope";

			eventText = "Ouch! I have a toothache so badly. \nI shouldn't have eaten those candies \nUncle Tom give us.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 0\n";
			break;
		case 1:

			eventSelectText1 = "Go to see the doctor with dad.";
			eventSelectText2 = "nope";

			eventText = "Go to hospital to inject a vaccine";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 1\n";
			break;
		case 2:
			eventSelectText1 = "Go to see the doctor with dad.";
			eventSelectText2 = "nope";

			eventText = "you injured from toys. \nDad wants to take you to the doctor.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;
			std::cout << "case 2\n";
			break;
		case 3:
			eventSelectText1 = "ok";

			eventText = "congratulation you have a young brother.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 1;
			eventCheck = 1;
			std::cout << "case 3\n";
			break;
		case 4:

			eventSelectText1 = "Go to see the doctor.";
			eventSelectText2 = "Nothing.";

			eventText = "You was bitten by that dog.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 4\n";
			break;


		case 5:
			eventSelectText1 = "Go.";
			eventSelectText2 = "don't go.";

			eventText = "Your parent take you to travel with them.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 5\n";
			break;
		case 6:
			eventSelectText1 = "Admit that I broke it.";
			eventSelectText2 = "It wasn't me.";

			eventText = "You broke your father dish while you were playing.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 6\n";
			break;
		case 7:
			eventSelectText1 = "Play.";
			eventSelectText2 = "Don't play.";

			eventText = "You father persuade you to play football";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 7\n";
			break;
		case 8:
			eventSelectText1 = "Choose father.";
			eventSelectText2 = "Choose mother.";

			eventText = "Your parent broke up";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 8\n";
			break;
		case 9:
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "Share toys with friends.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 9\n";
			break;
		case 10:
			eventSelectText1 = "Accept.";
			eventSelectText2 = "Not accept";

			eventText = "Parents gave you a gift.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 10\n";
			break;



		}

	}

	//primary
	if (age >= 6 && age <= 14)
	{
		switch (Evnow)
		{
		case 0:

			eventSelectText1 = "Talk a teacher.";
			eventSelectText2 = "Argut.";
			eventSelectText3 = "Bully Someone.";
			eventSelectText4 = "Notthing.";

			eventText = "You are bullied.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton3;
			this->eventSelectButton3 = new Button(570, 340, 225, 50, &this->font, eventSelectText3, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton4;
			this->eventSelectButton4 = new Button(820, 340, 225, 50, &this->font, eventSelectText4, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 4;
			eventCheck = 1;

			std::cout << "case 0\n";
			break;
		case 1:
			eventSelectText1 = "Accept.";
			eventSelectText2 = "Reject.";

			eventText = "Some one confess about lovenses to you.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 1\n";
			break;
		case 2:
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";
			eventSelectText3 = "No and blame friends.";

			eventText = "Your friends persuade you to skipping class.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton3;
			this->eventSelectButton3 = new Button(820, 340, 225, 50, &this->font, eventSelectText3, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 3;
			eventCheck = 1;

			std::cout << "case 2\n";
			break;
		case 3:
			eventSelectText1 = "Help.";
			eventSelectText2 = "Follow the teacher.";
			eventSelectText3 = "Don't care.";


			eventText = "you find true friend.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 3;
			eventCheck = 1;

			std::cout << "case 3\n";
			break;
		case 4:
			eventSelectText1 = "Repair.";
			eventSelectText2 = "Notthing.";

			eventText = "You find dad's old camera.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 4\n";
			break;
		case 5:
			eventSelectText1 = "Go to see the doctor.";
			eventSelectText2 = "Notthing.";

			eventText = "Eye exam.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 5\n";
			break;
		case 6:
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "You were invited to a club.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 6\n";
			break;
		case 7:
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "You were offered to attend school activities.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 7\n";
			break;
		case 8:
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "You Win the school ball match.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 8\n";
			break;
		case 9:
			eventSelectText1 = "Happy.";
			eventSelectText2 = "Notthing.";

			eventText = "You Win the school ball match.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 9\n";
			break;
		case 10:
			eventSelectText1 = "ํYes.";
			eventSelectText2 = "Notthing.";

			eventText = "House cleaning.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 10\n";
			break;
		}
	}

	//secondary
	if (age >= 15 && age <= 18)
	{
		switch (Evnow)
		{
		case 0:
			eventSelectText1 = "Agree.";
			eventSelectText2 = "Reject.";

			eventText = "A friend invited me to smoke.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 0\n";
			break;
		case 1:
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";
			eventSelectText3 = "No and blame friends.";

			eventText = "Your friends persuade you to skipping class.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton3;
			this->eventSelectButton3 = new Button(570, 340, 225, 50, &this->font, eventSelectText3, 25, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 3;
			eventCheck = 1;

			std::cout << "case 1\n";
			break;
		}
	}

	//bachelor
	if (age >= 19 && age <= 22)
	{
		switch (Evnow)
		{
		case 0:
			eventSelectText1 = "Agree.";
			eventSelectText2 = "No.";
			eventSelectText3 = "Tell the teacher.";

			eventText = "A friend asked to copy the exam.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton3;
			this->eventSelectButton3 = new Button(570, 340, 225, 50, &this->font, eventSelectText3, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 3;
			eventCheck = 1;

			std::cout << "case 0\n";
			break;
		case 1:
			eventSelectText1 = "Ok.";

			eventText = "Parents bought a car for.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 1;
			eventCheck = 1;

			std::cout << "case 0\n";
			break;
		case 2:
			eventSelectText1 = "Go.";
			eventSelectText2 = "No.";
			eventSelectText3 = "Cursingsenior.";

			eventText = "Enter the activity.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton3;
			this->eventSelectButton3 = new Button(570, 340, 225, 50, &this->font, eventSelectText3, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 3;
			eventCheck = 1;

			std::cout << "case 2\n";
			break;
		}
	}

	//primaryAdult
	if (age >= 23 && age <= 40)
	{
		switch (Evnow)
		{
		case 0:
			eventSelectText1 = "Go.";
			eventSelectText2 = "No.";


			eventText = "The party.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 0\n";
			break;
		case 1:
			eventSelectText1 = "Sorry.";
			eventSelectText2 = "Retaliate.";


			eventText = "Being cursed by the boss.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 1\n";
			break;
		case 2:
			eventSelectText1 = "Join.";
			eventSelectText2 = "Tellboss.";


			eventText = "A friend who works to defraud company money.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 2\n";
			break;
		}
	}

	//secondaryAdult
	if (age >= 41 && age <= 60)
	{
		switch (Evnow)
		{
		case 0:
			eventSelectText1 = "Sorry.";
			eventSelectText2 = "Retaliate.";


			eventText = "Being cursed by the boss.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 0\n";
			break;
		case 1:
			eventSelectText1 = "Ok.";

			eventText = "You Promote.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 1;
			eventCheck = 1;

			std::cout << "case 1\n";
			break;
		}
	}

	//eldery
	if (age >= 61)
	{
		switch (Evnow)
		{
		case 0:
			break;
		}
	}
}


//update
void GameState::updateAge()
{
	std::cout << age << " y/o\n\n";
}

void GameState::updateAnswer()
{

	if (Evnow == -1)
	{
		if (answer == 1)
		{
			this->quit = true;
		}
	}

	if (age >= 0 && age <= 5)
	{
		switch (Evnow)
		{

		case 0:
			switch (answer)
			{
			case 1:
				Happiness += random(6) + 5;
				answer = 0;
				break;
			case 2:
				answer = 0;
				break;
			}
			break;
		case 1:
			switch (answer)
			{
			case 1:
				Health += random(6) + 10;
				answer = 0;
				break;
			case 2:
				answer = 0;
				break;
			}
			break;
		case 2:
			switch (answer)
			{
			case 1:
				Health += 10;
				answer = 0;
				break;
			case 2:
				Health -= 10;
				answer = 0;
				break;
			}
			break;
		case 3:
			switch (answer)
			{
			case 1:
				Happiness += 20;
				answer = 0;
				break;
			}
			break;
		case 4:
			switch (answer)
			{
			case 1:
				Health -= 2;
				answer = 0;
				break;
			case 2:
				Health -= 10;
				answer = 0;
				break;
			}
			break;
		case 5:
			switch (answer)
			{
			case 1:
				Happiness += 10;
				answer = 0;
				break;
			case 2:
				Happiness -= 8;
				answer = 0;
				break;
			}
			break;
		case 6:
			switch (answer)
			{
			case 1:
				Happiness += 2;
				answer = 0;
				break;
			case 2:
				Happiness -= 8;
				answer = 0;
				break;
			}
			break;
		case 7:
			switch (answer)
			{
			case 1:
				Happiness += 5;
				Health += 5;
				answer = 0;
				break;
			case 2:
				Happiness -= 3;
				answer = 0;
				break;
			}
			break;
		case 8:
			switch (answer)
			{
			case 1:
				Happiness -= 30;
				answer = 0;
				break;
			case 2:
				Happiness -= 30;
				answer = 0;
				break;
			}
			break;
		case 9:
			switch (answer)
			{
			case 1:
				Happiness += 5;
				answer = 0;
				break;
			case 2:
				Happiness -= 5;
				answer = 0;
				break;
			}
			break;
		case 10:
			switch (answer)
			{
			case 1:
				Happiness += 7;
				answer = 0;
				break;
			case 2:
				Happiness -= 7;
				answer = 0;
				break;
			}
			break;
		}
	}

	if (age >= 6 && age <= 14)
	{
		switch (Evnow)
		{
		case 0:
			switch (answer)
			{
			case 1:
				if (Moral >= 50)
				{
					if (random(3) > 0)
					{
						Health += 10;
					}
					else
					{
						Health -= 10; Look -= 10;
					}
				}
				else
				{
					Health -= 10; Look -= 10;
				}
				answer = 0;
				break;
			case 2:
				Health -= 20; Look -= 20;
				answer = 0;
				break;
			case 3:
				Happiness += 10; Moral -= 20;
				answer = 0;
				break;
			case 4:
				Health -= 5; Look -= 5;
				answer = 0;
				break;
			}
			break;
		case 1:
			switch (answer)
			{
			case 1:
				Happiness += 30;
				answer = 0;
				break;
			case 2:
				answer = 0;
				break;
			}
			break;
		case 2:
			switch (answer)
			{
			case 1:
				Happiness += 20;
				Look -= 20;
				Smart -= 30;
				answer = 0;
				break;
			case 2:
				Look += 5;
				Smart += 15;
				answer = 0;
				break;
			case 3:
				if (random(101) <= 40)
				{
					Happiness -= 15;
				}
				else
				{
					Look += 5;
					Smart += 15;
				}
				answer = 0;
				break;
			}
			break;
		case 3:
			switch (answer)
			{
			case 1:
				Happiness += 5;
				answer = 0;
				break;
			case 2:
				Happiness += 10;
				answer = 0;
				break;
			case 3:
				Happiness -= 10;
				answer = 0;
				break;
			}
			break;
		case 4:
			switch (answer)
			{
			case 1:
				Happiness += 5;
				answer = 0;
				break;
			case 2:
				answer = 0;
				break;
			}
			break;
		case 5:
			switch (answer)
			{
			case 1:
				Health += 10;
				answer = 0;
				break;
			case 2:
				Health -= 10;
				answer = 0;
				break;
			}
			break;
		case 6:
			switch (answer)
			{
			case 1:
				Health += 5;
				answer = 0;
				break;
			case 2:
				Health -= 15;
				answer = 0;
				break;
			}
			break;
		case 7:
			switch (answer)
			{
			case 1:
				Happiness += 8;
				answer = 0;
				break;
			case 2:
				Happiness -= 3;
				answer = 0;
				break;
			}
			break;
		case 8:
			switch (answer)
			{
			case 1:
				Happiness += 8;
				answer = 0;
				break;
			case 2:
				Happiness -= 3;
				answer = 0;
				break;
			}
			break;
		case 9:
			switch (answer)
			{
			case 1:
				Happiness += 10;
				answer = 0;
				break;
			case 2:
				answer = 0;
				break;
			}
			break;
		case 10:
			switch (answer)
			{
			case 1:
				Happiness += 8;
				Health += 5;
				answer = 0;
				break;
			case 2:
				Happiness -= 6;
				answer = 0;
				break;
			}
			break;

		}
	}

	if (age >= 15 && age <= 18)
	{
		switch (Evnow)
		{
		case 0:
			switch (answer)
			{
			case 1:
				Moral -= 20;
				Happiness += 10;
				answer = 0;
				break;
			case 2:
				Look += 10;
				answer = 0;
				break;
			}
			break;
		case 1:
			switch (answer)
			{
			case 1:
				Happiness += 20;
				Look -= 20;
				Smart -= 30;
				answer = 0;
				break;
			case 2:
				Look += 5;
				Smart += 15;
				answer = 0;
				break;
			case 3:
				if (random(101) <= 40)
				{
					Happiness -= 15;
				}
				else
				{
					Look += 5;
					Smart += 15;
				}
				answer = 0;
				break;
			}
			break;
		}
	}

	if (age >= 19 && age <= 22)
	{
		switch (Evnow)
		{
		case 0:
			switch (answer)
			{
			case 1:
				Moral -= 10;
				Happiness += 10;
				answer = 0;
				break;
			case 2:
				answer = 0;
				break;
			case 3:
				Look -= 20;
				answer = 0;
				break;
			}
			break;
		case 1:
			switch (answer)
			{
			case 1:
				Happiness += 15;
				answer = 0;
				break;
			}
			break;
		case 2:
			switch (answer)
			{
			case 1:
				Look += 10;
				answer = 0;
				break;
			case 2:
				Happiness += 5;
				answer = 0;
				break;
			case 3:
				Look -= 20;
				Happiness += 10;
				answer = 0;
				break;
			}
			break;
		}
	}

	if (age >= 23 && age <= 40)
	{
		switch (Evnow)
		{
		case 0:
			switch (answer)
			{
			case 1:
				Look += 5;
				answer = 0;
				break;
			case 2:
				Look -= 10;
				answer = 0;
				break;
			}
			break;
		case 1:
			switch (answer)
			{
			case 1:
				Happiness += 10;
				Look -= 5;
				answer = 0;
				break;
			case 2:
				Happiness += 10;
				Look -= 20;
				answer = 0;
				break;
			}
			break;
		case 2:
			switch (answer)
			{
			case 1:
				Happiness += 10;
				Look -= 20;
				answer = 0;
				break;
			case 2:
				Happiness -= 10;
				Look += 10;
				Moral += 10;
				answer = 0;
				break;
			}
			break;
		}
	}

	if (age >= 41 && age <= 60)
	{
		switch (Evnow)
		{
		case 0:
			switch (answer)
			{
			case 1:
				Happiness += 10;
				Look -= 5;
				answer = 0;
				break;
			case 2:
				Happiness += 10;
				Look -= 20;
				answer = 0;
				break;
			}
			break;
		case 1:
			switch (answer)
			{
			case 1:
				Happiness += 10;
				Look += 10;
				answer = 0;
				break;
			}
			break;
		}
	}

	if (age >= 61)
	{
		switch (Evnow)
		{
		case 0:
			break;
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
		if (!eventCheck)
		{
			answer = 0;
			eventCheck = false;
			age++;
			this->updateAge();

			this->creatEvent(eventRandom());
		}


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

		eventCheck = false;
	}

	if (this->eventSelectButton4->isPressed())
	{
		answer = 4;

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
	this->eventTextButton = new Button(610, 60, 400, 200, &this->font2, eventText, 35, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

}

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
		case 1:
			this->eventTextButton->renderButton(target);

			this->eventSelectButton1->renderButton(target);
			break;
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