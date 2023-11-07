#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <ctime>
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


    sf::Clock clock;
    float delta_time = 0;

    //GameLoop
    while (oWindow.isOpen())
    {        
        
        object3.moveUp(delta_time);



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

        delta_time = clock.restart().asSeconds();

    }

    return 0;
}




