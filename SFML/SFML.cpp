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
    GameObject canon_shape(500, 900, 150, 100);
    canon_shape.setOriginToCenter();
    canon_shape.rotate(45);

    Canon canon_manager;
    //

    Ball test_ball(500, 500, 50, 50);

    sf::Clock clock;
    float delta_time = 0;

    bool test = false;
    test_ball.setPositionObject(500, 900);

    //GameLoop
    while (window->isOpen())
    {        

        canon_manager.update(canon_shape.shape, window);
        
        
        test_ball.moveDirection(delta_time, test_ball.speedX, test_ball.speedY);

        //EVENT
        
        if (test == false) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                test_ball.speedX = canon_manager.vect_x * 1;
                test_ball.speedY = canon_manager.vect_y * 1;
                cout << test_ball.speedX;
                cout << test_ball.speedY;
                test = true;
            }
        }

        sf::Event oEvent;
        while (window->pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed) {
                window->close();
            }
        }

        //UPDATEE



        //DRAW
        window->clear();
        
        window->draw(*canon_shape.shape);

        window->draw(*test_ball.shape);

        window->display();

        delta_time = clock.restart().asSeconds();

    }

    return 0;
}




