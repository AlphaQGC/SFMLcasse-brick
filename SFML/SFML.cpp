#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <stdio.h>
#include <iostream>
#include <ctime>

#include "GameObject.h"
#include "Canon.h"
#include "Ball.h"
#include "Brick.h"

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

    Brick brick(500, 100, 150, 150);

    vector<Ball*> tab_balls;
    vector<Brick*> tab_brick;
    
    tab_brick.push_back(new Brick(150, 100, 100, 100));
    tab_brick.push_back(new Brick(450, 100, 100, 100));
    tab_brick.push_back(new Brick(850, 100, 100, 100));


    sf::Clock clock;
    float delta_time = 0;

    bool test = false;

    //GameLoop
    while (window->isOpen())
    {        

        //EVENT
     

        sf::Event oEvent;
        while (window->pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed) {
                window->close();
            }

            if (oEvent.type == sf::Event::MouseButtonPressed) {
                switch(oEvent.mouseButton.button){
                case sf::Mouse::Left:

                    if (tab_balls.size() == 0) {
                        tab_balls.push_back(new Ball(490, 900, 20));

                        float norme = sqrt(pow(canon_manager.vect_x, 2) + pow(canon_manager.vect_y, 2));

                        tab_balls[tab_balls.size() - 1]->speedX = canon_manager.vect_x / norme;
                        tab_balls[tab_balls.size() - 1]->speedY = canon_manager.vect_y / norme;
                    }
                }
            }
        }


        canon_manager.update(canon_shape.shape, window);

        if (tab_balls.size() !=0) {
            for (int i = 0; i < tab_balls.size(); i++) {

                tab_balls[i]->moveDirection(delta_time, tab_balls[i]->speedX, tab_balls[i]->speedY);

                if (tab_balls[i]->windowCollidedX(window)) {
                    tab_balls[i]->speedX = tab_balls[i]->invertDirection(tab_balls[i]->speedX);
                }

                if (tab_balls[i]->windowCollidedY(window)) {
                    tab_balls[i]->speedY = tab_balls[i]->invertDirection(tab_balls[i]->speedY);
                }

                if (tab_brick.size() != 0) {
                    for (int j = 0; j < tab_brick.size(); j++) {

                        if (tab_balls[i]->hasCollided(tab_brick[j]->shape, tab_brick[j]->width, tab_brick[j]->height) == true) {

                            if (tab_balls[i]->checkCollisionX(tab_brick[j]->shape, tab_brick[j]->height) == true) {
                                tab_balls[i]->speedX = tab_balls[i]->invertDirection(tab_balls[i]->speedX);
                            }

                            if (tab_balls[i]->checkCollisionY(tab_brick[j]->shape, tab_brick[j]->height) == true) {
                                tab_balls[i]->speedY = tab_balls[i]->invertDirection(tab_balls[i]->speedY);
                            }

                            tab_brick[j]->update();

                            if (tab_brick[j]->health <= 0) {
                                tab_brick.erase(tab_brick.begin() + j);
                                j--;
                            }
                        }
                    }
                }

                if (tab_balls[i]->ballOutsideWindow(window) == true) {
                    tab_balls.erase(tab_balls.begin() + i);
                    i--;
                }
            }
        }


        //UPDATEE



        //DRAW
        window->clear();
        
        window->draw(*canon_shape.shape);

        if (tab_brick.size() != 0) {
            for (int i = 0; i < tab_brick.size(); i++) {
                window->draw(*tab_brick[i]->shape);
            }
        }

        
        if (tab_balls.size() != 0) {
            for (int i = 0; i < tab_balls.size(); i++) {
                window->draw(*tab_balls[i]->shape);
            }
        }

        window->display();

        delta_time = clock.restart().asSeconds();

    }

    return 0;
}




