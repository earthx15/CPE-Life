#include "game.h"
#include <iostream>



//Initialization
void Game::initWindows()
{

    std::ifstream ifs("Config/game.txt");

    std::string title = "None";
    sf::VideoMode window_bounds(1080, 720);
    unsigned frame_limit = 120;
    bool vertical_sync_enable = false;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> frame_limit;
        ifs >> vertical_sync_enable;
    }


    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(frame_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enable);
}


void Game::initStates()
{

    //this->states.push(new GameState(this->window));
    this->states.push(new MainMenuState(this->window, &this->states));



}



//Constructors / Destructors
Game::Game()
{
    this->initWindows();
    this->initStates();
    std::cout << "\nGame Start!\n";
}

Game::~Game()
{
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}


//Functions
void Game::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();


    //system("cls");
    //std::cout << this->dt << "\n";
}

void Game::endApplication()
{
    std::cout << "Ending Application!";
}

void Game::updateSFMLEvent()
{
    while (this->window->pollEvent(this->evnt))
    {
        if (this->evnt.type == sf::Event::Closed)
        {
            this->window->close();
        }
    }
}

void Game::update()
{
    this->updateSFMLEvent();

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else
    {
        this->endApplication();
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();

    //render items
    if (!this->states.empty())
        this->states.top()->render(this->window);

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}