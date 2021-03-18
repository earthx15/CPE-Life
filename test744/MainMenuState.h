#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "Gamestate.h"
#include "Button.h"


class MainMenuState :
    public State
{
private:
    sf::RectangleShape Background;
    sf::RectangleShape HTP;

    Button* gamestate_btn;
    Button* acheivment_btn;
    Button* exit_btn;
    Button* backToState_btn;

    sf::Texture backgroundTexture;
    sf::Texture HTPTexture;

    bool htpCheck;



public:

    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~MainMenuState();

    //Functions
    void endState();

    void updateButtons();
    void updateInputs(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target);

};

#endif