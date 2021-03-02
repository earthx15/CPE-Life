#pragma once

#include "state.h"
class MainMenuState :
    public State
{
private:

public:
    MainMenuState(sf::RenderWindow* window);
    virtual ~MainMenuState();

    //Functions
    void endState();

    void updateKeybinds(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);

};

