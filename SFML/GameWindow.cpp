#include "GameWindow.h"

GameWindow::GameWindow() {

}

int GameWindow::game() {

    srand(time(NULL));

    //Cr�ation d'une fen�tre
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "SFML");

    //
    sf::Texture background;
    if (!background.loadFromFile("img/dog.jpg"))
        cout << "image not loaded";

    sf::Sprite sprite;
    sprite.setTexture(background);
    sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
    sprite.setPosition(100, 100);
    //

    // init canon
    GameObject canon_shape(500, 900, 150, 100);
    canon_shape.setOriginToCenter();
    canon_shape.rotate(45);

    Canon canon_manager;
    ///

    // balls
    vector<Ball*> tab_balls;
    //

    // grid
    LevelCreater level;
    vector<Brick*> tab_brick;
    tab_brick = level.loadTable();
    //
    
    // bonus
    vector<Bonus*> tab_bonus;
    //


    sf::Clock clock;
    float delta_time = 0;

    bool already_collided;
    int limit_ball = 1;

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

                    if (tab_balls.size() < limit_ball) {
                        tab_balls.push_back(new Ball(490, 900, 10));

                        float norme = sqrt(pow(canon_manager.vect_x, 2) + pow(canon_manager.vect_y, 2));

                        tab_balls[tab_balls.size() - 1]->speedX = canon_manager.vect_x / norme;
                        tab_balls[tab_balls.size() - 1]->speedY = canon_manager.vect_y / norme;
                    }
                }
            }
        }

        canon_manager.update(canon_shape.shape, window);

        for (int j = 0; j < tab_bonus.size(); j++) {

            tab_bonus[j]->moveDirection(delta_time, 0, 1, tab_bonus[j]->speed_bonus);
        }

        for (int i = 0; i < tab_balls.size(); i++) {

                tab_balls[i]->moveDirection(delta_time, tab_balls[i]->speedX, tab_balls[i]->speedY, tab_balls[i]->speed);

                if (tab_balls[i]->windowCollidedX(window)) {
                    tab_balls[i]->speedX = tab_balls[i]->invertDirection(tab_balls[i]->speedX);
                }

                if (tab_balls[i]->windowCollidedY(window)) {
                    tab_balls[i]->speedY = tab_balls[i]->invertDirection(tab_balls[i]->speedY);
                }


                if (tab_brick.size() != 0) {

                    already_collided = false;

                    for (int j = 0; j < tab_brick.size(); j++) {

                        if (tab_balls[i]->hasCollided(tab_brick[j]->shape, tab_brick[j]->width, tab_brick[j]->height) == true) {

                            if (already_collided == false) {

                                sf::Vector2f newVect = tab_balls[i]->newBounceDirection(tab_brick[j]->shape, tab_brick[j]->width, tab_brick[j]->height);
                                tab_balls[i]->speedX = newVect.x * tab_balls[i]->speedX;
                                tab_balls[i]->speedY = newVect.y * tab_balls[i]->speedY;

                                already_collided = true;
                            }
                            tab_brick[j]->update();

                            if (tab_brick[j]->health <= 0) {
                                if (tab_brick[j]->dropBonus() == true) {
                                    tab_bonus.push_back(new Bonus(tab_brick[j]->x + tab_brick[j]->width / 2, tab_brick[j]->y + tab_brick[j]->height / 2, 20, 20));
                                }
                                tab_brick.erase(tab_brick.begin() + j);
                                j--;
                            }
                        }
                    }
                }

                if (tab_bonus.size() != 0) {
                    for (int j = 0; j < tab_bonus.size(); j++) {

                        if (tab_balls[i]->hasCollided(tab_bonus[j]->shape, tab_bonus[j]->width, tab_bonus[j]->height) == true) {
                            limit_ball = 5;
                            tab_bonus.erase(tab_bonus.begin() + j);
                            j--;
                        } else if (tab_bonus[j]->y < 0) {
                            tab_bonus.erase(tab_bonus.begin() + j);
                            j--;
                        }
                    }
                }

                if (tab_balls[i]->ballOutsideWindow(window) == true) {
                    limit_ball = 1;
                    tab_balls.erase(tab_balls.begin() + i);
                    i--;
                }
        }
        


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


        if (tab_bonus.size() != 0) {
            for (int i = 0; i < tab_bonus.size(); i++) {
                window->draw(*tab_bonus[i]->shape);
            }
        }

        //
        window->draw(sprite);
        //

        window->display();

        delta_time = clock.restart().asSeconds();

    }

    return 0;
}
