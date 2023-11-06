#include <SFML/Graphics.hpp>
#include <time.h>
#include "GameObject.h"


int main(int argc, char** argv)
{
    //Cr�ation d'une fen�tre
    sf::RenderWindow oWindow(sf::VideoMode(800, 800), "SFML");

    GameObject object1(0,0, 100,100);
    GameObject object2(700, 700, 100, 100);
    GameObject object3(0, 700, 100, 100);
    GameObject object4(700, 0, 100, 100);
    GameObject object5(300, 300, 100);


    //Uint32 start;
    //int countDelta = 0;

    //GameLoop
    while (oWindow.isOpen())
    {

        //Uint32 start = SDL_GetTicks();

        //if (countDelta >= 20) {
            // move something
            //countDelta = 0;
        //}

        //Uint32 end = SDL_GetTicks();
        //Uint32 deltaTime = end - start;
        //countDelta += deltaTime;


        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }

        //UPDATE



        //DRAW
        oWindow.clear();
           
        oWindow.draw(*object1.shape);
        oWindow.draw(*object2.shape);
        oWindow.draw(*object3.shape);
        oWindow.draw(*object4.shape);
        oWindow.draw(*object5.shape);


        oWindow.display();
    }

    return 0;
}




