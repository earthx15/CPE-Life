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

    Button* eventSelectButton1;
    Button* eventSelectButton2;
    Button* eventSelectButton3;
    Button* eventSelectButton4;

    int answer;
    int buttonCount;
    
    //dataText(showing data)
    Button* ageShow;
    Button* dataI;
    Button* dataII;
    Button* dataIII;
    Button* dataIV;
    Button* dataV;

    Button* eventTextButton;

    

    //(data)
    int age = 0;
    
    int Happiness =  60 + random(31);
    int Health = 70 +  random(31);
    int Smart = 5 + random(96);
    int Look = 20 + random(81);
    int Moral = 0 +  random(101);

    
    //Event generating code

    bool eventCheck;
    /*std::string EVcommon[] = { "Tooth_decay","injec_vaccine","have_yungbra","injured_from_toys","bully","puppy_love","skipping_class","true_friend","old_camera","smoke","car","copy_theexam","activity","party","boss","cheat","Promote","retire" };
    std::string EVspacial[] = { "","" };*/
    
    //eventCount
    int babyEvent = 5;
    int childEvent;
    int primaryEvent;
    int seccondaryEvent;
    int bachelorEvent;
    int primaryAdultEvent;
    int secondaryAdultEvent;
    int elderlyEvent;

    int specialEvent;

    int Evnow;
    int randtype;
    

    std::string eventText;
    std::string eventSelectText1;
    std::string eventSelectText2;
    std::string eventSelectText3;
    std::string eventSelectText4;
   
    
    

    



public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();

    //Functions
    int random(int n, int x = 0);

   
    
    void endState();

    



    //Event generating code
    int eventRandom();

    void creatEvent(int Evnow);
    
    
    
    //update
    void updateButtons();
    void updateInputs(const float& dt);
    void updateText();
    void updateAge();
    void updateAnswer();
    
    void update(const float& dt);
    
    
    //render
    void render(sf::RenderTarget* target);


    


};

#endif