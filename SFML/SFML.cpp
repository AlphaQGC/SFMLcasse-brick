// SFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML/Graphics.hpp>
#include "GameObject.h"
int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(1000, 1000), "SFML");

    ////Création d'un cercle de radius 100
    //sf::CircleShape oCircle(100.f);
    ////A la position 0, 0
    //oCircle.setPosition(0.f, 0.f);
    ////Et de couleur verte
    //oCircle.setFillColor(sf::Color::Green);


    ////Création d'un rectangle de taille 50, 50
    //sf::RectangleShape oRectangle(sf::Vector2f(50.f, 50.f));
    ////A la position 100, 100
    //oCircle.setPosition(100.f, 100.f);
    ////Et de couleur rouge
    //oRectangle.setFillColor(sf::Color::Red);

    GameObject objectRectangle(200, 200, 50, 50,2);


    //GameLoop
    while (oWindow.isOpen())
    {
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

        oWindow.draw(*objectRectangle.shape);
        /*oWindow.draw(oRectangle);*/

        oWindow.display();
    }

    return 0;
}




