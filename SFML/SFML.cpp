#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <stdio.h>
#include <iostream>
#include <ctime>

#include "GameObject.h"
#include "Canon.h"
#include "Ball.h"

using namespace std;


int main(int argc, char** argv)
{   
    //Cr�ation d'une fen�tre
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "SFML");

    // init canon
    GameObject canon_shape(500, 900, 100, 100);
    canon_shape.setOriginToCenter();

    Canon canon_manager;

    Ball test_ball(500, 500, 50, 50);

    sf::Clock clock;
    float delta_time = 0;

    //GameLoop
    while (window->isOpen())
    {        

        canon_manager.update(canon_shape.shape, window);

        test_ball.moveY(delta_time);
        test_ball.moveX(delta_time);
       
        if (test_ball.windowCollidedX(window) == true)
        {
            cout << "X";
            test_ball.speedX = test_ball.invertDirection(test_ball.speedX);
        }

        if (test_ball.windowCollidedY(window) == true)
        {
            cout << "Y";
            test_ball.speedY = test_ball.invertDirection(test_ball.speedY);
        }

        //EVENT
        sf::Event oEvent;
        while (window->pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                window->close();
        }

        //UPDATEE



        //DRAW
        window->clear();
           
       // window->draw(*canon_shape.shape);
       window->draw(*test_ball.shape);



        window->display();

        delta_time = clock.restart().asSeconds();

    }

    return 0;
}




