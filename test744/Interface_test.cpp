#include "Interface_test.h"

MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("font/BebasNeue-Regular.ttf"))
		printf("fail");

	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::White);
	mainMenu[0].setString("START");
	mainMenu[0].setCharacterSize(40);
	mainMenu[0].setPosition(500, 100);

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("ACHEIVMENT");
	mainMenu[1].setCharacterSize(40);
	mainMenu[1].setPosition(500, 200);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("QUIT");
	mainMenu[2].setCharacterSize(40);
	mainMenu[2].setPosition(500, 300);

	mainMenuSelected = -1;
}

MainMenu::~MainMenu()
{

}

void MainMenu::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_main_menu; i++)
	{
		window.draw(mainMenu[i]);
	}

}

void MainMenu::cursor_selected(sf::RenderWindow& window)
{
	if (mainMenu[0].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		
		mainMenuSelected = 0;
		mainMenu[mainMenuSelected].setFillColor(::sf::Color::Red);
		
	}
	else if (mainMenu[1].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		
		mainMenuSelected = 1;
		mainMenu[mainMenuSelected].setFillColor(::sf::Color::Red);
		
	}
	else if (mainMenu[2].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		
		mainMenuSelected = 2;
		mainMenu[mainMenuSelected].setFillColor(::sf::Color::Red);
	}
	else if (~(mainMenu[0].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) || ~(mainMenu[1].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) || ~(mainMenu[2].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
	{
		
		mainMenuSelected = -1;
	}
	
}