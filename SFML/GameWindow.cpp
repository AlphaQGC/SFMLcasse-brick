#include "GameWindow.h"

GameWindow::GameWindow() {

}

int GameWindow::game() {
    //Cr�ation d'une fen�tre
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "SFML");

    // init canon
    GameObject canon_shape(500, 900, 150, 100);
    canon_shape.setOriginToCenter();
    canon_shape.rotate(45);

    Canon canon_manager;
    //

    vector<Ball*> tab_balls;

    // grid
    LevelCreater level;
    vector<Brick*> tab_brick;
    tab_brick = level.loadTable();
    //
    


    sf::Clock clock;
    float delta_time = 0;

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
                switch (oEvent.mouseButton.button) {
                case sf::Mouse::Left:

                    if (tab_balls.size() < 10) {
                        tab_balls.push_back(new Ball(490, 900, 20));

                        float norme = sqrt(pow(canon_manager.vect_x, 2) + pow(canon_manager.vect_y, 2));

                        tab_balls[tab_balls.size() - 1]->speedX = canon_manager.vect_x / norme;
                        tab_balls[tab_balls.size() - 1]->speedY = canon_manager.vect_y / norme;
                    }
                }
            }
        }

        canon_manager.update(canon_shape.shape, window);

        if (tab_balls.size() != 0) {
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

                            sf::Vector2f newVect = tab_balls[i]->newBounceDirection(tab_brick[j]->shape, tab_brick[j]->width, tab_brick[j]->height);
                            tab_balls[i]->speedX = newVect.x * tab_balls[i]->speedX;
                            tab_balls[i]->speedY = newVect.y * tab_balls[i]->speedY;

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


        //UPDATE



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
