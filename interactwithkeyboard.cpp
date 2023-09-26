#include "interactwithkeyboard.h"

void interactWithKeyboard(sf::RenderWindow& window, int& selectCard, int& turn, bool& pressSpace, bool& pressZ, bool& pressEnter, bool& pressX, bool& leftClick, bool& pressOne) {

    sf::Event event;
    pressSpace = false;
    pressZ = false;
    pressEnter = false;
    pressX = false;
    leftClick = false;
    pressOne = false;

    while (window.pollEvent(event)) {

        if (event.type == sf::Event::Closed) {

            window.close();

        }

        if (event.type == sf::Event::KeyPressed) {

            if (event.key.code == sf::Keyboard::Left) {

                selectCard--;

            }

            if (event.key.code == sf::Keyboard::Right) {

                selectCard++;

            }
            if (event.key.code == sf::Keyboard::Space) {


                pressSpace = true;

            }

            if (event.key.code == sf::Keyboard::Enter) {

                pressEnter = true;

            }

            if (event.key.code == sf::Keyboard::Z) {

                pressZ = true;

            }
            if (event.key.code == sf::Keyboard::X) {

                pressX = true;

            }
            if (event.key.code == sf::Keyboard::Num1) {

                pressOne = true;

            }

        }
        if (event.type == sf::Event::MouseButtonPressed) {

            if (event.mouseButton.button == sf::Mouse::Left) {

                leftClick = true;

            }

        }

    }

}