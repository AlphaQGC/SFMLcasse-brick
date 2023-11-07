#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include "GameObject.h"
using namespace std;


int main(int argc, char** argv)
{   
    sf::Mouse mouse;
    //Cr�ation d'une fen�tre
    sf::RenderWindow oWindow(sf::VideoMode(800, 800), "SFML");

    GameObject object2(350, 700, 100, 100);

    sf::Clock clock;
    float delta_time = 0;

    //GameLoop
    while (oWindow.isOpen())
    {        
        sf::Vector2i mouse_pos = mouse.getPosition(oWindow);
        
        system("cls");
        cout << "x:" << mouse_pos.x << endl;
        cout << "y:" << mouse_pos.y << endl;

        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }

        //UPDATEE



        //DRAW
        oWindow.clear();
           
        oWindow.draw(*object2.shape);


        oWindow.display();

        delta_time = clock.restart().asSeconds();

    }

    return 0;
}




