#ifndef  GAME_H
#define GAME_H




#include "MainMenustate.h"



class Game
{
private:
	sf::RenderWindow* window;
	sf::Event evnt;
	sf::VideoMode videoMode;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;


	//Initialization

	void initWindows();
	void initStates();

public:

	//Constructors / Destructors
	Game();
	virtual ~Game();


	//Functions

	//Regular
	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvent();
	void update();

	//Render
	void render();

	//Core
	void run();




};

#endif 