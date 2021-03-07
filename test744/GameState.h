#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "Button.h"
#include "MainMenuState.h"

class GameState :

    public State
{
private:
    sf::RectangleShape Background;

    Button* backToState_btn;

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();

    //Functions
    void endState();

    void updateButtons();
    void updateInputs(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target);

};

#endif