#ifndef STATE_H
#define STATE_H

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include "background.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

class State
{
private:

protected:

	//sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;

	sf::Font font;
	sf::Font font2;
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;



public:
	sf::Texture bgtextture[11];
	sf::Texture bgtextture2[11];
	std::vector<Backgrounds> background;
	std::vector<Backgrounds> background2;

	sf::RenderWindow* window;
	std::stack<State*>* states;
	State(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~State();

	const bool& getQuit() const;

	virtual void checkForQuit();

	virtual void initFont();
	virtual void initbg();
	virtual void endState() = 0;
	virtual void updateMousePos();
	virtual void updateInputs(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
};

#endif