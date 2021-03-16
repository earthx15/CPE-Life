
#include "Interface_test.h"
#include "state.h"
/*
int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Main Menu");
    
    MainMenu mainmenu(1080, 720);


    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            
            if (evnt.type == sf::Event::Closed)
            {
                window.close();
            }

            mainmenu.cursor_selected(window);

            

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                int x = mainmenu.mainMenuPressed();
                if (x == 0)
                {
                    printf("PLAY button was pressed\n");
                }
                if (x == 1)
                {
                    printf("ACHIEVMENT button was pressed\n");
                }
                if (x == 2)
                {
                    printf("QUIT button was pressed\n");
                }

            }

               
        }
        

        
        window.clear();
        mainmenu.Draw(window);
        window.display();
    }
    return 0;
    //testtesttest
}
*/