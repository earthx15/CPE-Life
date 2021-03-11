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
    sf::RectangleShape BackgroundName;
    sf::RectangleShape BackgroundLog;
    sf::RectangleShape BackgroundSituation;
    sf::RectangleShape BackgroundStatus;
    
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
   
    //functions
    int random(int n);

    //(data)
    int age = 0;
    
    int Happiness =  60 + random(31);
    int Health = 70 +  random(31);
    int Smart = 5 + random(96);
    int Look = 20 + random(81);
    int Moral = 0 +  random(101);


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