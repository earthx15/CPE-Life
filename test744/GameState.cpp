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
	this->aged_btn = new Button(415, 420, 250, 100, &this->font, "Age++", 60, sf::Color(70, 70, 70, 250), sf::Color(150, 150, 150, 250), sf::Color(20, 20, 20, 250), sf::Color::White);

	//(x, y, font, text size, "text", data, text color)
	this->ageShow = new Button(100, 100, &this->font, 25, "age : ", age, sf::Color::White);
	this->dataI = new Button(250, 600, &this->font, 25, "Happiness : ", Happiness, sf::Color::White);
	this->dataII = new Button(400, 600, &this->font, 25, "Health : ", Health, sf::Color::White);
	this->dataIII = new Button(550, 600, &this->font, 25, "Smart : ", Smart, sf::Color::White);
	this->dataIV = new Button(700, 600, &this->font, 25, "Look : ", Look, sf::Color::White);
	this->dataV = new Button(850, 600, &this->font, 25, "Moral : ", Moral, sf::Color::White);

	this->bgTexture.loadFromFile("bg game.png");

	this->Background.setSize(sf::Vector2f(1080, 720));
	this->Background.setTexture(&bgTexture);
	

	

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
int GameState::cheak(int base, int sub) {
	if (base + sub > 100)
	{
		return 100;
	}
	else if (base + sub < 0)
	{
		return 0;
	}
	else
	{
		return base += sub;
	}
}
void GameState::endState()
{
	std::cout << "\nEnding GameState!\n";
}


//event
int GameState::eventRandom()
{
	if (age >= 25)
	{
		if (random(101) <= ((pow(age, 2) / 100 + 10) * (1 - Health / 200 * pow(0.99, age / 10))) / 8)
		{
			std::cout << (pow(age, 2) / 100 + 10) * (1 - Health / 200 * pow(0.99, age / 10)) << std::endl;
			Evnow = -1;
			return Evnow;
		}
	}

	if (age == 6 || age == 19 || age == 23 || age == 60)
	{
		return Evnow = 100;
	}
	if (age == 13)
	{
		return Evnow = 101;
	}


	randtype = random(101);
	if (randtype >= 20 && randtype <= 80) {
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

		std::cout << "you death \nyou mother Abortion " << std::endl;
	}
	else {
		Evnow = -2 - random(specialEvent);
	}

	return Evnow;
}

void GameState::creatEvent(int Evnow)
{

	if (Evnow == -1)
	{
		if (age == 0)
		{
			eventText = "You mother Abortion\nYou are dead. xd";
		}
		eventText = "You are dead. xd";

		eventSelectText1 = "Back to main menu.";

		delete this->eventSelectButton1;
		this->eventSelectButton1 = new Button(695, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

		buttonCount = 1;
		eventCheck = 1;

		return;
	}
	if (Evnow == -2)
	{
		eventText = "Win the lottery.";

		eventSelectText1 = "Ok.";

		delete this->eventSelectButton1;
		this->eventSelectButton1 = new Button(695, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

		buttonCount = 1;
		eventCheck = 1;

		return;
	}
	if (Evnow == -3)
	{
		if (age > 6)
		{
			eventText = "Hit by a car.\ngo to another world.";

			eventSelectText1 = "Ok.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(695, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 1;
			eventCheck = 1;
		}
		return;
	}
	if (Evnow == -4)
	{
		if (age >= 13)
		{
			eventSelectText1 = "All in.";
			eventSelectText2 = "Half.";
			eventSelectText3 = "Bet.";

			eventText = "Go to play casino.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton3;
			this->eventSelectButton3 = new Button(570, 340, 225, 50, &this->font, eventSelectText3, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 3;
			eventCheck = 1;
		}
		return;
	}
	if (Evnow == -5)
	{
		if (age >= 6)
		{
			eventSelectText1 = "Do.";
			eventSelectText2 = "Not.";

			eventText = "Wake up to make merit\n to monks in the morning.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;
		}
		return;
	}
	if (Evnow == -6)
	{
		if (age >= 6)
		{
			eventSelectText1 = "Return.";
			eventSelectText2 = "Not return.";

			eventText = "Found a purse.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;
		}
		return;
	}
	if (Evnow == -7)
	{
		if (age >= 6)
		{
			eventSelectText1 = "Agree.";
			eventSelectText2 = "Reject.";

			eventText = "Invite you to smoke.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;
		}
		return;
	}
	if (Evnow == -8)
	{
		if (Happiness <= 50)
		{
			eventSelectText1 = "Agree.";

			eventText = "stressed out.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 1;
			eventCheck = 1;
		}
		return;
	}
	if (Evnow == -9)
	{
		if (age <= 60 && age >= 23)
		{
			eventSelectText1 = "steal.";
			eventSelectText2 = "intimidate.";
			eventSelectText3 = "Nothing";
			eventText = "You find boss \nsecret lover.";
			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton3;
			this->eventSelectButton3 = new Button(570, 340, 225, 50, &this->font, eventSelectText3, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 3;
			eventCheck = 1;
		}
		return;
	}
	if (Evnow == -10)
	{
		if (age >= 6)
		{
			eventSelectText1 = "Ok.";

			eventText = "Car accident.";
			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 1;
			eventCheck = 1;
		}
		return;
	}
	if (Evnow == -11)
	{
		eventSelectText1 = "Go.";
		eventSelectText2 = "Reject.";

		eventText = "You donate blood.";
		delete this->eventSelectButton1;
		this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
		delete this->eventSelectButton2;
		this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

		buttonCount = 2;
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
		case 11:

			eventSelectText1 = "Punch.";
			eventSelectText2 = "Kick.";
			eventSelectText3 = "Headbutt.";
			eventSelectText4 = "Guard.";

			eventText = "Fight with your friend.";

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

			std::cout << "case 11\n";
			break;
		case 12:
			eventSelectText1 = "Go.";
			eventSelectText2 = "Don't Go";

			eventText = "Parents take you to make merit.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 12\n";
			break;
		case 13:
			eventSelectText1 = "Eat.";
			eventSelectText2 = "Don't Eat";

			eventText = "Parents make mashed banana for you.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 13\n";
			break;
		case 14:
			eventSelectText1 = "Tell teacher.";
			eventSelectText2 = "Do notthing.";

			eventText = "You shit your pants.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 14\n";
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
			this->eventSelectButton3 = new Button(570, 340, 225, 50, &this->font, eventSelectText3, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


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
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton3;
			this->eventSelectButton3 = new Button(570, 340, 225, 50, &this->font, eventSelectText3, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



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
			eventSelectText1 = "Yes.";
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
		case 11:
			eventSelectText1 = "Punch.";
			eventSelectText2 = "Kick.";
			eventSelectText3 = "Headbutt.";
			eventSelectText4 = "Guard.";

			eventText = "Fight with your friend.";

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

			std::cout << "case 11\n";
			break;
		case 12:
			eventSelectText1 = "Watch.";
			eventSelectText2 = "Don't watch .";

			eventText = "Your friend persuade you to watch pornhub.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 12\n";
			break;
		case 13:
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "Songkarn Festival.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 13\n";
			break;
		case 14:
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "still money your mother.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 14\n";
			break;
		case 100:
			eventSelectText1 = "Ok.";

			eventText = "Attend primary school.";

			this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 1;
			eventCheck = 1;

			std::cout << "case 100\n";
			break;
		case 101:
			eventSelectText1 = "Ok.";

			eventText = "Attend secondary school.";

			this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 1;
			eventCheck = 1;

			std::cout << "case 101\n";
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
			this->eventSelectButton3 = new Button(570, 340, 225, 50, &this->font, eventSelectText3, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 3;
			eventCheck = 1;

			std::cout << "case 2\n";
			break;
		case 3:
			eventSelectText1 = "Help.";
			eventSelectText2 = "Follow the teacher.";
			eventSelectText3 = "Don't care.";


			eventText = "you find true friend \nbeing teased.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton3;
			this->eventSelectButton3 = new Button(570, 340, 225, 50, &this->font, eventSelectText3, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



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
			eventSelectText1 = "Yes.";
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
		case 11:
			eventSelectText1 = "Punch.";
			eventSelectText2 = "Kick.";
			eventSelectText3 = "Headbutt.";
			eventSelectText4 = "Guard.";

			eventText = "Fight with your friend.";

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

			std::cout << "case 11\n";
			break;
		case 12:
			eventSelectText1 = "Watch.";
			eventSelectText2 = "Don't watch .";

			eventText = "Your friend persuade you to watch pornhub.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 12\n";
			break;
		case 13:
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "Songkarn Festival.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 13\n";
			break;
		case 14:
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "You still money your mother.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 14\n";
			break;
		case 15:// done
			eventSelectText1 = "Tongue kiss.";
			eventSelectText2 = "Kiss.";
			eventSelectText3 = "Notthing.";

			eventText = "First kiss.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton3;
			this->eventSelectButton3 = new Button(570, 340, 225, 50, &this->font, eventSelectText3, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 3;
			eventCheck = 1;

			std::cout << "case 15\n";
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

			std::cout << "case 1\n";
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
		case 3:
			eventSelectText1 = "Help.";
			eventSelectText2 = "Follow the teacher.";
			eventSelectText3 = "Don't care.";


			eventText = "you find true friend.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton3;
			this->eventSelectButton3 = new Button(570, 340, 225, 50, &this->font, eventSelectText3, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



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
			eventSelectText1 = "Yes.";
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
		case 11:
			eventSelectText1 = "Punch.";
			eventSelectText2 = "Kick.";
			eventSelectText3 = "Headbutt.";
			eventSelectText4 = "Guard.";

			eventText = "Fight with your friend.";

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

			std::cout << "case 11\n";
			break;
		case 12:
			eventSelectText1 = "Watch.";
			eventSelectText2 = "Don't watch .";

			eventText = "Your friend persuade you to watch pornhub.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 12\n";
			break;
		case 13:
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "Songkarn Festival.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 13\n";
			break;
		case 14:
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "still money your mother.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 14\n";
			break;
		case 15: // done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "Friend asked to copy the exam.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 15\n";
			break;
		case 16://done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "Make a driving license.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 16\n";
			break;
		case 17://done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "Read books before the exam.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 17\n";
			break;
		case 18://done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "Join a sports club.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 18\n";
			break;
		case 19://done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "Join the welcome activities.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 19\n";
			break;
		case 20://done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "Parents bought a car for.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 20\n";
			break;
		case 21://done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "A friend invited me to read a book..";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);



			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 21\n";
			break;
		case 100:
			eventSelectText1 = "Ok.";

			eventText = "Attend university.";

			this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);


			buttonCount = 1;
			eventCheck = 1;

			std::cout << "case 100\n";
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


			eventText = "Friend who works to defraud company money.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 2\n";
			break;
		case 3: //done
			eventSelectText1 = "Exhort.";
			eventSelectText2 = "Attack.";


			eventText = "Colleague bad habits.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 3\n";
			break;
		case 4: //done
			eventSelectText1 = "Exhort.";
			eventSelectText2 = "Attack.";


			eventText = "Colleague bad habits.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 4\n";
			break;
		case 5: //done
			eventSelectText1 = "Late.";
			eventSelectText2 = "Leave work.";


			eventText = "Wake up late.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 5\n";
			break;
		case 6: //done
			eventSelectText1 = "No.";
			eventSelectText2 = "Yes.";


			eventText = "Make time for yourself.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 6\n";
			break;
		case 7: //done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Share knowledge with colleagues.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 7\n";
			break;
		case 8: //done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Helping a colleague.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 8\n";
			break;
		case 9: //done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Find someone to sweetheart.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 9\n";
			break;
		case 10: //done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Go to party.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 10\n";
			break;
		case 11: //done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Educate yourself.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 11\n";
			break;
		case 12: //done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Take care of parents.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 12\n";
			break;
		case 13: //done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Take care of yourself.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 13\n";
			break;
		case 14: //done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Exercise.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 14\n";
			break;
		case 100:
			if (Smart > 50)
			{
				eventSelectText1 = "Teacher.";
				eventSelectText2 = "Doctor.";
				eventSelectText3 = "Engineering.";
				eventSelectText4 = "Scientist.";
			}
			else
			{
				eventSelectText1 = "Painter.";
				eventSelectText2 = "Soldier.";
				eventSelectText3 = "Boxer.";
				eventSelectText4 = "Youtuber.";
			}


			eventText = "You start working at.";

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

			std::cout << "case 100\n";
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
		case 2:
			eventSelectText1 = "Ok.";
			eventSelectText2 = "No.";

			eventText = "Take your children on a trip.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 2\n";
			break;
		case 3:
			eventSelectText1 = "Go to see the doctor.";
			eventSelectText2 = "Take medicine and sleep.";

			eventText = "sick.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 3\n";
			break;
		case 4:
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "Friends invited to travel.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 4\n";
			break;
		case 5:
			eventSelectText1 = "Improve oneself.";
			eventSelectText2 = "Notthing.";

			eventText = "Being cursed by the boss.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 5\n";
			break;
		case 6:
			eventSelectText1 = "Work.";
			eventSelectText2 = "Leave work.";

			eventText = "Drinking alcohol until unable to work.";

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

			eventText = "Think the world is boring.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 7\n";
			break;
		case 8:
			eventSelectText1 = "íYes.";
			eventSelectText2 = "No.";

			eventText = "Golfing with friends.";

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

			eventText = "Your friend invite to prostitute.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 9\n";
			break;
		case 10:
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "Play casino.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 10\n";
			break;
		case 11:
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";

			eventText = "Go to Reunion.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 11\n";
			break;
		case 12:
			eventSelectText1 = "Self repair.";
			eventSelectText2 = "Call a technician.";
			eventSelectText3 = "Notthing.";


			eventText = "The house fire is broken..";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton3;
			this->eventSelectButton3 = new Button(570, 340, 225, 50, &this->font, eventSelectText3, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 3;
			eventCheck = 1;

			std::cout << "case 12\n";
			break;
		case 13:
			eventSelectText1 = "Catch the thief yourself.";
			eventSelectText2 = "Call the police.";
			eventSelectText3 = "Notthing.";

			eventText = "The thief is going to the house.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton3;
			this->eventSelectButton3 = new Button(570, 340, 225, 50, &this->font, eventSelectText3, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 3;
			eventCheck = 1;

			std::cout << "case 13\n";
			break;
		case 14:
			eventSelectText1 = "Believe.";
			eventSelectText2 = "Don't Believe.";
			eventSelectText3 = "Call the police.";


			eventText = "Being fooled by fraudsters to sell things.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton3;
			this->eventSelectButton3 = new Button(570, 340, 225, 50, &this->font, eventSelectText3, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 14\n";
			break;
		case 100:
			eventSelectText1 = "Ok.";

			eventText = "Retire.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 1;
			eventCheck = 1;

			std::cout << "case 100\n";
			break;
		}
	}

	//eldery
	if (age >= 61)
	{
		switch (Evnow)
		{
		case 0:
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Take a massage.";

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


			eventText = "Friend invites you to eat betel nut..";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 1\n";
			break;
		case 2:
			eventSelectText1 = "Ok.";
			eventSelectText2 = "No.";

			eventText = "Take your children on a trip.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 2\n";
			break;
		case 3: // done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Play with grandchildren.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 3\n";
			break;
		case 4: // done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Play extreme sports.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 4\n";
			break;
		case 5: // done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Do you want to water the plants?.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 5\n";
			break;
		case 6: // done
			eventSelectText1 = "Comedy.";
			eventSelectText2 = "documentary.";
			eventSelectText3 = "Horror.";
			eventSelectText4 = "Anime.";


			eventText = "Watch TV.";

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

			std::cout << "case 6\n";
			break;
		case 7: // done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Offering alms to monks in the morning.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 7\n";
			break;
		case 8: // done
			eventSelectText1 = "Eat later.";
			eventSelectText2 = "Don't take medicine.";


			eventText = "Forgot to take medicine.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 8\n";
			break;
		case 9: // done
			eventSelectText1 = "Write about a good day.";
			eventSelectText2 = "Write down your emotions.";


			eventText = "Write a diary.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 9\n";
			break;
		case 10: // done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Drink alcohol.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 10\n";
			break;
		case 11: // done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Knee pain surgery.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 11\n";
			break;
		case 12: // done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Grandchild invites to make dessert.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 12\n";
			break;
		case 13: // done
			eventSelectText1 = "Go to see the doctor.";
			eventSelectText2 = "Notthing.";


			eventText = "Sick.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 13\n";
			break;
		case 14: // done
			eventSelectText1 = "Yes.";
			eventSelectText2 = "No.";


			eventText = "Exercise.";

			delete this->eventSelectButton1;
			this->eventSelectButton1 = new Button(570, 280, 225, 50, &this->font, eventSelectText1, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);
			delete this->eventSelectButton2;
			this->eventSelectButton2 = new Button(820, 280, 225, 50, &this->font, eventSelectText2, selectSize, sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200), sf::Color::White);

			buttonCount = 2;
			eventCheck = 1;

			std::cout << "case 14\n";
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
	if (Evnow == -2)
	{
		switch (answer)
		{
		case 1:
			Happiness = cheak(Happiness, random(6) + 5);
			Look = cheak(Look, 5);
			answer = 0; eventCheck = false;
			break;
		}
	}
	if (Evnow == -3)
	{
		if (answer == 1)
		{
			this->quit = true;
		}
	}
	if (Evnow == -4)
	{
		switch (answer)
		{
		case 1:
			if (random(2) == 0)
			{
				this->quit = true;
			}
			else
			{
				Happiness = cheak(Happiness, 30);
			}
			answer = 0; eventCheck = false;
			break;
		case 2:
			if (random(2) == 0)
			{
				Happiness = cheak(Happiness, -15);
			}
			else
			{
				Happiness = cheak(Happiness, 15);
			}
			answer = 0; eventCheck = false;
			break;
		case 3:
			if (random(2) == 0)
			{
				Happiness = cheak(Happiness, -5);
			}
			else
			{
				Happiness = cheak(Happiness, 5);
			}
			answer = 0; eventCheck = false;
			break;
		}
	}
	if (Evnow == -5)
	{
		switch (answer)
		{
		case 1:
			Moral = cheak(Moral, 15);
			answer = 0; eventCheck = false;
			break;
		case 2:
			answer = 0; eventCheck = false;
			break;
		}
	}
	if (Evnow == -6)
	{
		switch (answer)
		{
		case 1:
			Moral = cheak(Moral, 10);
			Look = cheak(Look, 20);
			answer = 0; eventCheck = false;
			break;
		case 2:
			if (random(2) == 0)
			{
				Moral = cheak(Moral, -15);
			}
			else
			{
				Happiness = cheak(Happiness, 10);
			}
			answer = 0; eventCheck = false;
			break;
		}
	}
	if (Evnow == -7)
	{
		switch (answer)
		{
		case 1:
			Health = cheak(Health, -20);
			Happiness = cheak(Happiness, -10);
			answer = 0; eventCheck = false;
			break;
		}
	}
	if (Evnow == -8)
	{
		if (age > 6)
		{
			switch (answer)
			{
			case 1:
				Health = cheak(Health, -10);
				Happiness = cheak(Happiness, 20);
				Look = cheak(Look, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, -10);
				answer = 0; eventCheck = false;
				break;
			}
		}
	}
	if (Evnow == -9)
	{
		switch (answer)
		{
		case 1:
			Happiness = cheak(Happiness, 30);
			Look = cheak(Look, -10);
			answer = 0; eventCheck = false;
			break;
		case 2:
			Look = cheak(Look, -10);
			Happiness = cheak(Happiness, 15);
			answer = 0; eventCheck = false;
			break;
		case 3:
			answer = 0; eventCheck = false;
			break;
		}
	}
	if (Evnow == -10)
	{
		switch (answer)
		{
		case 1:
			Smart = cheak(Smart, -30);
			answer = 0; eventCheck = false;
			break;
		}
	}
	if (Evnow == -11)
	{
		switch (answer)
		{
		case 1:
			Look = cheak(Look, 10);
			Health = cheak(Health, -15);
			Moral = cheak(Moral, 20);
			answer = 0; eventCheck = false;
			break;
		case 2:
			answer = 0; eventCheck = false;
			break;
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
				Happiness = cheak(Happiness, random(6) + 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				answer = 0; eventCheck = false;
				break;
			}
		case 1:
			switch (answer)
			{
			case 1:
				Health = cheak(Health, random(6) + 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 2:
			switch (answer)
			{
			case 1:
				Health = cheak(Health, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Health = cheak(Health, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 3:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 20);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 4:
			switch (answer)
			{
			case 1:
				Health = cheak(Health, -2);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Health = cheak(Health, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 5:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -8);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 6:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 2);
				Moral = cheak(Moral, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -8);
				Moral = cheak(Moral, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 7:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 5);
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -3);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 8:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -30);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -30);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 9:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 5);
				Moral = cheak(Moral, 3);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -5);
				Moral = cheak(Moral, -2);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 10:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 7);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -7);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 11:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -3);
				Health = cheak(Health, -3);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, -2);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -3);
				Health = cheak(Health, -3);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, -2);
				answer = 0; eventCheck = false;
				break;
			case 3:
				Happiness = cheak(Happiness, -3);
				Health = cheak(Health, -3);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, -2);
				answer = 0; eventCheck = false;
				break;
			case 4:
				Happiness = cheak(Happiness, -3);
				Health = cheak(Health, -3);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, -2);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 12:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 2);
				Moral = cheak(Moral, 5);
				Look = cheak(Look, 2);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Moral = cheak(Moral, -4);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 13:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 3);
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -2);
				Health = cheak(Health, -2);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 14:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -3);
				Look = cheak(Look, -3);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -1);
				answer = 0; eventCheck = false;
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
						Health = cheak(Health, 10);
					}
					else
					{
						Health = cheak(Health, -10);
						Look = cheak(Look, -10);
					}
				}
				else
				{
					Health = cheak(Health, -10);
					Look = cheak(Look, -10);
				}
				answer = 0; eventCheck = false;
				break;
			case 2:
				Health = cheak(Health, -20);
				Look = cheak(Look, -20);
				answer = 0; eventCheck = false;
				break;
			case 3:
				Happiness = cheak(Happiness, 10);
				Moral = cheak(Moral, -20);
				answer = 0; eventCheck = false;
				break;
			case 4:
				Health = cheak(Health, -5);
				Look = cheak(Look, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 1:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 30);
				answer = 0; eventCheck = false;
				break;
			case 2:
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 2:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 20);
				Look = cheak(Look, -20);
				Smart = cheak(Smart, -30);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, 5);
				Smart = cheak(Smart, 15);
				answer = 0; eventCheck = false;
				break;
			case 3:
				if (random(101) <= 40)
				{
					Happiness = cheak(Happiness, -15);
				}
				else
				{
					Look = cheak(Look, 5);
					Smart = cheak(Smart, 15);
				}
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 3:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 10);
				answer = 0; eventCheck = false;
				break;
			case 3:
				Happiness = cheak(Happiness, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 4:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 5:
			switch (answer)
			{
			case 1:
				Health = cheak(Health, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Health = cheak(Health, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 6:
			switch (answer)
			{
			case 1:
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Health = cheak(Health, -15);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 7:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 8);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -3);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 8:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 8);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -3);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 9:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 10:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 8);
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -6);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 11:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -3);
				Health = cheak(Health, -4);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, -2);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -3);
				Health = cheak(Health, -4);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, -2);
				answer = 0; eventCheck = false;
				break;
			case 3:
				Happiness = cheak(Happiness, -3);
				Health = cheak(Health, -4);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, -2);
				answer = 0; eventCheck = false;
				break;
			case 4:
				Happiness = cheak(Happiness, -3);
				Health = cheak(Health, -4);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, -2);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 12:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 50);
				Moral = cheak(Moral, -10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, 7);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 13:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 14:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -10);
				Moral = cheak(Moral, -10);
				Look = cheak(Look, -10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, 5);
				Happiness = cheak(Happiness, 5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 100:
			switch (answer)
			{
			case 1:
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 101:
			switch (answer)
			{
			case 1:
				answer = 0; eventCheck = false;
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
				Moral = cheak(Moral, -20);
				Happiness = cheak(Happiness, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, 10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 1:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 20);
				Look = cheak(Look, -20);
				Smart = cheak(Smart, -30);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, 5);
				Smart = cheak(Smart, 15);
				answer = 0; eventCheck = false;
				break;
			case 3:
				if (random(101) <= 40)
				{
					Happiness = cheak(Happiness, -15);
				}
				else
				{
					Look = cheak(Look, 5);
					Smart = cheak(Smart, 15);
				}
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 2:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 20);
				Look = cheak(Look, -20);
				Smart = cheak(Smart, -30);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, 5);
				Smart = cheak(Smart, 15);
				answer = 0; eventCheck = false;
				break;
			case 3:
				if (random(101) <= 40)
				{
					Happiness = cheak(Happiness, -15);
				}
				else
				{
					Look = cheak(Look, 5);
					Smart = cheak(Smart, 15);
				}
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 3:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 10);
				answer = 0; eventCheck = false;
				break;
			case 3:
				Happiness = cheak(Happiness, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 4:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 5:
			switch (answer)
			{
			case 1:
				Health = cheak(Health, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Health = cheak(Health, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 6:
			switch (answer)
			{
			case 1:
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Health = cheak(Health, -15);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 7:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 8);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -3);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 8:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 8);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -3);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 9:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 10:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 8);
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -6);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 11:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -3);
				Health = cheak(Health, -4);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, -2);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -3);
				Health = cheak(Health, -4);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, -2);
				answer = 0; eventCheck = false;
				break;
			case 3:
				Happiness = cheak(Happiness, -3);
				Health = cheak(Health, -4);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, -2);
				answer = 0; eventCheck = false;
				break;
			case 4:
				Happiness = cheak(Happiness, -3);
				Health = cheak(Health, -4);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, -2);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 12:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 50);
				Moral = cheak(Moral, -10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, 7);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 13:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 14:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -10);
				Moral = cheak(Moral, -10);
				Look = cheak(Look, -10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, 5);
				Happiness = cheak(Happiness, 5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 15: //done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, 5);
				Happiness = cheak(Happiness, 10);
				answer = 0; eventCheck = false;
				break;
			case 3:
				Look = cheak(Look, -5);
				Happiness = cheak(Happiness, -5);
				answer = 0; eventCheck = false;
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
				Moral = cheak(Moral, -10);
				Happiness = cheak(Happiness, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				answer = 0; eventCheck = false;
				break;
			case 3:
				Look = cheak(Look, -20);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 1:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 2:
			switch (answer)
			{
			case 1:
				Look = cheak(Look, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 5);
				answer = 0; eventCheck = false;
				break;
			case 3:
				Look = cheak(Look, -20);
				Happiness = cheak(Happiness, 10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 3:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 10);
				answer = 0; eventCheck = false;
				break;
			case 3:
				Happiness = cheak(Happiness, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 4:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 5:
			switch (answer)
			{
			case 1:
				Health = cheak(Health, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Health = cheak(Health, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 6:
			switch (answer)
			{
			case 1:
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Health = cheak(Health, -15);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 7:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 8);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -3);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 8:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 8);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -3);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 9:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 10:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 8);
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -6);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 11:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -3);
				Health = cheak(Health, -4);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, -2);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -3);
				Health = cheak(Health, -4);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, -2);
				answer = 0; eventCheck = false;
				break;
			case 3:
				Happiness = cheak(Happiness, -3);
				Health = cheak(Health, -4);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, -2);
				answer = 0; eventCheck = false;
				break;
			case 4:
				Happiness = cheak(Happiness, -3);
				Health = cheak(Health, -4);
				Moral = cheak(Moral, -5);
				Look = cheak(Look, -2);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 12:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 50);
				Moral = cheak(Moral, -10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, 7);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 13:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 14:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -10);
				Moral = cheak(Moral, -10);
				Look = cheak(Look, -10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, 5);
				Happiness = cheak(Happiness, 5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 15: //done
			switch (answer)
			{
			case 1:
				Moral = cheak(Moral, -10);
				Look = cheak(Look, -10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, 5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 16: //done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, -5);
				Happiness = cheak(Happiness, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 17: //done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -10);
				Moral = cheak(Moral, -10);
				Look = cheak(Look, -10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, 5);
				Happiness = cheak(Happiness, 5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 18: //done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				Health = cheak(Health, 10);
				Look = cheak(Look, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Health = cheak(Health, -10);
				Happiness = cheak(Happiness, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 19: //done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, -5);
				Happiness = cheak(Happiness, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 20: //done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 20);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -20);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 21: //done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, 10);
				Smart = cheak(Smart, 20);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, -5);
				Happiness = cheak(Happiness, -5);
				Smart = cheak(Smart, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 100:
			switch (answer)
			{
			case 1:
				answer = 0; eventCheck = false;
				break;
			}
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
				Look = cheak(Look, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 1:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, -5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, -20);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 2:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, -20);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -10);
				Look = cheak(Look, 10);
				Moral = cheak(Moral, 10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 3: // done
			switch (answer)
			{
			case 1:
				Look = cheak(Look, 20);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -10);
				Look = cheak(Look, -10);
				Health = cheak(Health, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 4: // done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -5);
				Look = cheak(Look, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 5: // done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, -10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 5);
				Look = cheak(Look, 5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 6: //done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -15);
				Health = cheak(Health, -5);
				Smart = cheak(Smart, -5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 15);
				Health = cheak(Health, 5);
				Smart = cheak(Smart, 5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 7: // done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 5);
				Look = cheak(Look, 10);
				Smart = cheak(Smart, 10);
				Moral = cheak(Moral, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Look = cheak(Look, 5);
				Moral = cheak(Moral, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 8: // done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 5);
				Look = cheak(Look, 5);
				Moral = cheak(Moral, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 5);
				Look = cheak(Look, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 9: // done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 10: // done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				Look = cheak(Look, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -15);
				Look = cheak(Look, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 11: // done
			switch (answer)
			{
			case 1:
				Smart = cheak(Smart, 20);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Smart = cheak(Smart, -15);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 12: //done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				Look = cheak(Look, 5);
				Moral = cheak(Moral, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -5);
				Look = cheak(Look, -5);
				Moral = cheak(Moral, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 13: //done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -15);
				Look = cheak(Look, -5);
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -20);
				Look = cheak(Look, -5);
				Health = cheak(Health, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 14: // done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				Look = cheak(Look, 15);
				Health = cheak(Health, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -15);
				Look = cheak(Look, -15);
				Health = cheak(Health, -20);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 100:
			switch (answer)
			{
			case 1:
				answer = 0; eventCheck = false;
				break;
			case 2:
				answer = 0; eventCheck = false;
				break;
			case 3:
				answer = 0; eventCheck = false;
				break;
			case 4:
				answer = 0; eventCheck = false;
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
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, -5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, -20);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 1:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, 10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 2:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 3:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 5);
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 5);
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 4:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -5);
				Health = cheak(Health, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 5:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -5);
				Look = cheak(Look, 15);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -10);
				Look = cheak(Look, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 6:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -5);
				Look = cheak(Look, -10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Happiness, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 7:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -15);
				Look = cheak(Look, -5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 5);
				Look = cheak(Look, 5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 8:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				Look = cheak(Look, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 9:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				Look = cheak(Look, -10);
				Health = cheak(Health, -5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -10);
				Look = cheak(Look, 10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 10:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -15);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, 10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 11:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				Look = cheak(Look, 10);
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -10);
				Look = cheak(Look, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 12:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, 7);
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -10);
				Look = cheak(Look, -10);
				answer = 0; eventCheck = false;
				break;
			case 3:
				Happiness = cheak(Happiness, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 13:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 5);
				Health = cheak(Health, -10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 8);
				Look = cheak(Look, 3);
				answer = 0; eventCheck = false;
				break;
			case 3:
				Happiness = cheak(Happiness, -20);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 14:
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -20);
				Look = cheak(Look, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, 5);
				answer = 0; eventCheck = false;
				break;
			case 3:
				Happiness = cheak(Happiness, 15);
				Look = cheak(Look, 10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 100:
			switch (answer)
			{
			case 1:
				answer = 0; eventCheck = false;
				break;
			}
			break;
		}
	}
	if (age >= 61)
	{
		switch (Evnow)
		{
		case 0: //done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -5);
				Health = cheak(Health, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 1: //done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				Look = cheak(Look, -5);
				Health = cheak(Health, -5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -5);
				Look = cheak(Look, 5);
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 2: //done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -5);
				Look = cheak(Look, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 3: //done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				Look = cheak(Look, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -15);
				Look = cheak(Look, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 4: //done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				Look = cheak(Look, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -15);
				Look = cheak(Look, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 5: // done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, 5);
				Health = cheak(Health, 5);
				Smart = cheak(Smart, 2);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -10);
				Look = cheak(Look, -5);
				Health = cheak(Health, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 6: // done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, 5);
				Smart = cheak(Smart, 10);
				answer = 0; eventCheck = false;
				break;
			case 3:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, 5);
				answer = 0; eventCheck = false;
				break;
			case 4:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, 5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 7: // done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 5);
				Moral = cheak(Moral, 20);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 8: // done
			switch (answer)
			{
			case 1:
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Health = cheak(Health, -10);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 9: // done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, -5);
				Smart = cheak(Smart, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 5);
				Look = cheak(Look, -2);
				Smart = cheak(Smart, 5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 10: // done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 10);
				Look = cheak(Look, -5);
				Health = cheak(Health, -10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 5);
				Look = cheak(Look, 5);
				Health = cheak(Health, 5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 11: // done
			switch (answer)
			{
			case 1:
				Health = cheak(Health, 15);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Health = cheak(Health, -15);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 12: // done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 15);
				Look = cheak(Look, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -15);
				Look = cheak(Look, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 13: // no apply
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, 2);
				Look = cheak(Look, 5);
				Health = cheak(Health, 10);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, -5);
				Look = cheak(Look, -5);
				answer = 0; eventCheck = false;
				break;
			}
			break;
		case 14: // done
			switch (answer)
			{
			case 1:
				Happiness = cheak(Happiness, -15);
				Health = cheak(Health, 10);
				Smart = cheak(Smart, 5);
				answer = 0; eventCheck = false;
				break;
			case 2:
				Happiness = cheak(Happiness, 5);
				Health = cheak(Health, -5);
				answer = 0; eventCheck = false;
				break;
			}
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