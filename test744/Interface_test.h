#pragma once
#include<SFML/Graphics.hpp>
#define MAX_main_menu 3

class MainMenu
{
public:
	MainMenu(float width, float height);

	void Draw(sf::RenderWindow& window);
	void cursor_selected(sf::RenderWindow& window);

	int mainMenuPressed()
	{
		return mainMenuSelected;
	}
	~MainMenu();

private:
	int mainMenuSelected;
	sf::Font font;
	sf::Text mainMenu[MAX_main_menu];
};