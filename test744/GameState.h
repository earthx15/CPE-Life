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

    
    //Buttons(can be clicked)
    Button* backToState_btn;
    Button* aged_btn;
    
    //dataText(showing data)
    Button* ageShow;
    Button* dataI;
    Button* dataII;
    Button* dataIII;
    Button* dataIV;
    Button* dataV;
    //(data)
    int age = 0;


public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();

    //Functions
    void endState();

    void updateAge();

    //update
    void updateButtons();
    void updateInputs(const float& dt);
    void updateText();
    void update(const float& dt);


    
    //render
    void render(sf::RenderTarget* target);

};

#endif