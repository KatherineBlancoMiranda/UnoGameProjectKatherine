#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "classplayer.h"
#include "showusedcard.h"
#include "classmenu.h"


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

void stopCard(int& lastTurn, card& usedCard, int& turn) {

    if (usedCard.type == 10) {

        turn = lastTurn;

    }
    lastTurn = turn;

}

void zeroCard(Player& playerOne, Player& playerTwo, card& usedCard) {

    Player savePlayerCards;

    if (!usedCard.effect) {

        return;

    }

    if (usedCard.type == 0) {
        
        Player savePlayerCards = playerOne;
        playerOne = playerTwo;
        playerTwo = savePlayerCards;

    }
    usedCard.effect = false;
}
        
void drawUnoButton(sf::Texture& unoButtonTexture, sf::Sprite& unoButtonSprite, sf::RenderWindow& window) {

    unoButtonSprite.setTexture(unoButtonTexture);

    unoButtonSprite.setPosition(600, 300);

    window.draw(unoButtonSprite);

}

bool activeUnoButton(bool& leftClick) {

    if (leftClick) {

        return true;

    }
}
      

using namespace std;

int main()
{
    int selectCard = 0;
    int turn = 1;
    bool pressSpace = false;
    bool pressEnter = false;
    bool pressZ = false;
    bool pressX = false;
    bool leftClick = false;
    bool unoButtonPressed = false;
    bool pressOne = false;
    int countCards = 0;
    sf::RenderWindow window(sf::VideoMode(900, 700), "Juego uno");
    sf::Texture texture;
    texture.loadFromFile("Cards.png");
    sf::Texture unoButtonTexture;
    sf::Sprite unoButtonSprite;
    sf::Texture menuTexture;
    menuTexture.loadFromFile("menu.png");
    unoButtonTexture.loadFromFile("unobutton.png");

    


    int lastTurn = turn;

    srand(time(0));

    Player playerOne;
    Player playerTwo;
    Player cardsSet;
    card usedCard;
    Menu menuOptions;

    playerOne.setCardTexture(texture);
    playerTwo.setCardTexture(texture);
    cardsSet.setCardTexture(texture);
    menuOptions.setMenuTexture(menuTexture);

    cardsSet.generateCards();
    cardsSet.shuffleCards();


    for (int i = 0; i < 8; i++) {

        playerOne.addCard(cardsSet.takeCard(0));
        playerTwo.addCard(cardsSet.takeCard(0));

    }

    usedCard = cardsSet.takeCard(0);

    menuOptions.showMenu();

    while (window.isOpen()) {

        interactWithKeyboard(window, selectCard, turn, pressSpace, pressZ, pressEnter, pressX, leftClick, pressOne);

        if (pressOne) {

            menuOptions.hideBox();

        }

        if (menuOptions.boxIsOpen()) {

            pressSpace = false;
            pressZ = false;
            pressEnter = false;
            pressX = false;
            leftClick = false;
            selectCard = 0;

        }

        window.clear(sf::Color::White);

        drawUnoButton(unoButtonTexture, unoButtonSprite, window);

        cardsSet.drawDeckCards(window, 500, 250);

        if (turn > 2) {

            turn = 1;

        }
        if (leftClick) {

            unoButtonPressed = true;

        }

        stopCard(lastTurn, usedCard, turn);
        
        
        playerOne.activeUnoButtonNotPressed(unoButtonPressed, cardsSet);
        if (turn == 1) {

            playerOne.drawPlayerCards(window, 0, 0, selectCard, usedCard, pressSpace, turn, pressEnter, countCards, unoButtonPressed);

            playerOne.takeCardFromDeck(pressZ, cardsSet, countCards, turn, unoButtonPressed);

            playerOne.changeCardColor(selectCard, pressX);

            if (playerOne.getTotalCards() == 0) {

                menuOptions.showWinner(0);

            }

        }
        

        else {

            playerTwo.drawPlayerCards(window, 0, 450, selectCard, usedCard, pressSpace, turn, pressEnter, countCards, unoButtonPressed);

            playerTwo.takeCardFromDeck(pressZ, cardsSet, countCards, turn, unoButtonPressed);

            playerTwo.changeCardColor(selectCard, pressX);

            if (playerTwo.getTotalCards() == 0) {

                menuOptions.showWinner(475);

            }

        }
        playerTwo.activeUnoButtonNotPressed(unoButtonPressed, cardsSet);
        zeroCard(playerOne, playerTwo, usedCard);
        

        menuOptions.drawMenu(window);
        window.display();

    }

   /* while (true) {

        playerOne.doActions(&usedCard);
        playerTwo.doActions(&usedCard);

    }*/




}
