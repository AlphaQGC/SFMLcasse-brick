#include "GameWindow.h"

GameWindow::GameWindow() {

}

int GameWindow::game() {

    srand(time(NULL));

    //Cr�ation d'une fen�tre
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "SFML");

    // init board
    sf::Texture background_texture;
    background_texture.loadFromFile("img/background.png");
    sf::Sprite background;
    background.setTexture(background_texture);
    background.setPosition(-100, -100);
    background.setScale(1.5, 1.5);
    //
    
    // init canon
    const char* img_canon = "img/canon.png";
    GameObject canon_shape(500, 900, 150, 100, img_canon);
    canon_shape.setOriginToCenter();
    canon_shape.rotate(45);
    Canon canon_manager;
    //

    // balls
    vector<Ball*> tab_balls;
    const char* img_ball = "img/ball.png";
    //

    // grid
    LevelCreater level;
    vector<Brick*> tab_brick;
    int count_level = 0;
    //

    sf::Clock clock;
    float delta_time = 0;

    int limit_ball = 1;

    int min;
    int index;

    //GameLoop
    while (window->isOpen())
    {

        //EVENT

        if (tab_brick.size() == 0) {
            if (count_level < 4) {
                count_level += 1;
                tab_balls.clear();
                tab_brick = level.loadTable(count_level);
            }
        }

        sf::Event oEvent;
        while (window->pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed) {
                window->close();
            }
        }
      
        if (tab_brick.size() != 0) {
            if (tab_balls.size() < limit_ball) {
                min = tab_brick[0]->y;
                index = 0;
                for (int i = 0; i < tab_brick.size(); i++) {
                    if (min < tab_brick[i]->y) {
                        index = i;
                    }
                }

                canon_manager.getVect(canon_shape.shape, window, tab_brick[index]->shape);

                tab_balls.push_back(new Ball(490, 900, 10, img_ball));

                float norme = sqrt(pow(canon_manager.vect_x, 2) + pow(canon_manager.vect_y, 2));

                tab_balls[tab_balls.size() - 1]->vectX = canon_manager.vect_x / norme;
                tab_balls[tab_balls.size() - 1]->vectY = canon_manager.vect_y / norme;
            }
        }

        for (int i = 0; i < tab_balls.size(); i++) {

                tab_balls[i]->moveDirection(delta_time, tab_balls[i]->vectX, tab_balls[i]->vectY, tab_balls[i]->speed);

                if (tab_brick.size() != 0) {

                    for (int j = 0; j < tab_brick.size(); j++) {

                        if (tab_balls[i]->hasCollided(tab_brick[j]->shape, tab_brick[j]->width, tab_brick[j]->height) == true) {

                            tab_brick[j]->update();

                            if (tab_brick[j]->health <= 0) {
                                tab_brick.erase(tab_brick.begin() + j);
                                j--;
                            }

                            /* ?????????????
                            tab_balls.erase(tab_balls.begin() + i);
                            i--;
                            */
                        }
                    }
                }

                if (tab_balls[i]->windowCollided(window) == true) {
                    tab_balls.erase(tab_balls.begin() + i);
                    i--;
                }
        }
        


        //DRAW
        window->clear();

        window->draw(background);

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

        window->draw(*canon_shape.shape);


        window->display();

        delta_time = clock.restart().asSeconds();

    }

    return 0;
}
