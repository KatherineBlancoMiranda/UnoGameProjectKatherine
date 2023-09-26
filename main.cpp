#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "classplayer.h"
#include "classmenu.h"
#include "interactwithkeyboard.h"
#include "stopcard.h"
#include "zerocard.h"
#include "drawunobutton.h"
#include "activeunobutton.h"

using namespace std;

int main()
{
    int selectCard = 0;
    int turn = 1;
    int lastTurn = turn;
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

}
